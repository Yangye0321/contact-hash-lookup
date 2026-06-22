#include<iostream>
#include<fstream>
#include"Functions.h"
using namespace std;
#define Maxsize 53
unsigned int Functions::BKDRHash(char* str) //BKDRHash函数 
{
    unsigned int seed=131;
    unsigned int hash=0;
    
    while(*str)
    {
        hash=hash*seed+(*str++);
    }
    
    return hash%Maxsize;
}
void Functions::visit1(HashNode p)    //输出信息
{
    cout<<p.st<<" "<<p.name<<" "<<p.pn<<" "<<endl;
}
void Functions::visit2(HashNode p,int& count)    //统计节点数
{
    count++;
}
void Functions::visit3(HashNode p,int& total)     //统计搜索长度
{
    total+=p.st;
}
int Functions::TraverseHash(Buckets* con,int choice)  //遍历哈希表
{
    HashNode* p;
    int num=0;
    for(int i=0;i<Maxsize;i++)
    {
        p=con[i].head->next;
        while(p!=NULL)
        {
            if(choice==1)
                visit1(*p);
            else if(choice==2)
                visit2(*p,num);
            else if(choice==3)
                visit3(*p,num);
            p=p->next;
        }
    }
    return num;
}

void Functions::CreateHash(Buckets* con,HashNode data[],int n)  //创建哈希表
{
    int h;
    HashNode* p;
    for(int i=0;i<n;i++)
    {
        h=BKDRHash(&data[i].name[0]);
        p=con[h].head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        HashNode* s=new HashNode;
        s->name=data[i].name;
        s->pn=data[i].pn;
        s->st=p->st+1;
        s->next=NULL;
        p->next=s;
    }
}

void Functions::InsertHash(Buckets* con,HashNode data)  //插入哈希表
{
    int h=BKDRHash(&data.name[0]);
    HashNode* p=con[h].head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    HashNode* s=new HashNode;
    s->name=data.name;
    s->pn=data.pn;
    s->st=p->st+1;
    s->next=NULL;
    p->next=s;
}

void Functions::SearchHash(Buckets* con,string name)  //搜索哈希表
{
    int h=BKDRHash(&name[0]);
    HashNode* p=con[h].head->next;
    while(p!=NULL)
    {
        if(p->name==name)
        {
            visit1(*p);
            return;
        }
        p=p->next;
    }
    cout<<"Not found!"<<endl;
}

void Functions::DeleteHash(Buckets* con,string name)  //删除哈希表中的节点
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
void Functions::ReadData(Buckets* con)  //从文件中读取数据
{
    	fstream file;
		file.open("contact.txt",ios::in);
        int n;
		file>>n;
		HashNode* data=new HashNode[n];
		for(int i=0;i<n;i++)
		{
			file>>data[i].name>>data[i].pn;
			data[i].st=0;
		}
		file.close();
        CreateHash(con,data,n);
}

void Functions::WriteData(Buckets* con)  //将数据写入文件
{
    fstream file;
    file.open("contact.txt",ios::out);
    int count=0;
    for(int i=0;i<Maxsize;i++)
    {
        HashNode* p=con[i].head->next;
        while(p!=NULL)
        {
            count++;
            p=p->next;
        }
    }
    file<<count<<endl;
    for(int i=0;i<Maxsize;i++)
    {
        HashNode* p=con[i].head->next;
        while(p!=NULL)
        {
            file<<p->name<<" "<<p->pn<<endl;
            p=p->next;
        }
    }
    file.close();
}

void Functions::CountASL(Buckets* con)  //计算平均搜索长度
{
    int total=TraverseHash(con,3);
    int num=TraverseHash(con,2);
    if(num==0)
        cout<<"No contacts!"<<endl;
    else
        cout<<"Average Search Length: "<<(double)total/num<<endl;
    cout<<total<<" "<<num<<endl;
}