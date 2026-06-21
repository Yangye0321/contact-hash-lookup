#include<iostream>
//#include"Functions.h"
using namespace std;
struct HashNode     //哈希表中的节点
{
    string name;
    string pn;     //phonenumber
    string addr;
    int st;        //searchtime
    HashNode* next;
};
struct Buckets      //存放哈希表的桶
{
    HashNode* head;  //头节点
};
#define Maxsize 40
unsigned int BKDRHash(char* str) //BKDRHash函数 
{
    unsigned int seed=131;
    unsigned int hash=0;
    
    while(*str)
    {
        hash=hash*seed+(*str++);
    }
    
    return hash%Maxsize;
}

void TraverseHash(Buckets* con)  //遍历哈希表
{
    HashNode* p;
    for(int i=0;i<Maxsize;i++)
    {
        p=con[i].head->next;
        while(p!=NULL)
        {
            cout<<p->st<<" "<<p->name<<" "<<p->pn<<" "<<endl;
            p=p->next;
        }
    }
}

void CreateHash(Buckets* con,HashNode data[],int n)  //创建哈希表
{
    int h;
    HashNode* p;
    int t=1;
    for(int i=0;i<n;i++)
    {
        h=BKDRHash(&data[i].name[0]);
        p=con[h].head;
        while(p->next!=NULL)
        {
            t++;
            p=p->next;
        }
        HashNode* s=new HashNode;
        s->name=data[i].name;
        s->pn=data[i].pn;
        s->st=t;
        s->next=NULL;
        p->next=s;
    }
}

void InsertHash(Buckets* con,HashNode data)  //插入哈希表
{
    int h=BKDRHash(&data.name[0]);
    HashNode* p=con[h].head;
    int t=1;
    while(p->next!=NULL)
    {
        t++;
        p=p->next;
    }
    HashNode* s=new HashNode;
    s->name=data.name;
    s->pn=data.pn;
    s->st=t;
    s->next=NULL;
    p->next=s;
}

void SearchHash(Buckets* con,string name)  //搜索哈希表
{
    int h=BKDRHash(&name[0]);
    HashNode* p=con[h].head->next;
    while(p!=NULL)
    {
        if(p->name==name)
        {
            cout<<p->st<<" "<<p->name<<" "<<p->pn<<" "<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"Not found!"<<endl;
}

void DeleteHash(Buckets* con,string name)  //删除哈希表中的节点
{
    int h=BKDRHash(&name[0]);
    HashNode* p=con[h].head;
    bool flag=false;
    while(p->next!=NULL)
    {
        if(flag)
        {
            p->st--;
        }
        if(p->next->name==name)
        {
            HashNode* q=p->next;
            p->next=q->next;
            delete q;
            cout<<"Deleted!"<<endl;
            flag=true;
            return;
        }
        p=p->next;
    }
    cout<<"Not found!"<<endl;
}
int main()
{
    Buckets* contacts = new Buckets[Maxsize];
    for(int i=0;i<Maxsize;i++)
    {
        contacts[i].head=new HashNode;
        contacts[i].head->next=NULL;
    }
    int n=3;
    HashNode data[3]={{"张三","1"},{"李四","2"},{"王五","3"}};
    CreateHash(contacts,data,n);
    //TraverseHash(contacts);
    SearchHash(contacts,"张三");
    DeleteHash(contacts,"张三");
    SearchHash(contacts,"张三");
    InsertHash(contacts,{"赵六","4"});
    SearchHash(contacts,"赵六");
    return 0;
}