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

void CreateHash(Buckets* con,HashNode data[],int n)
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
    TraverseHash(contacts);
    return 0;
}