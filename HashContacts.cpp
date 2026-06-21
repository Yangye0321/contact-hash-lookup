#include<iostream>
#include"Functions.h"
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
    HashNode* next;
};
int main()
{
    Buckets* contacts = new Buckets[Maxsize];
    for(int i=0;i<Maxsize;i++)
    {
        contacts[i].next=NULL;
    }
}