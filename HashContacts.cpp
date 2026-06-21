#include<iostream>
#include<fstream>
#include"Functions.h"
using namespace std;
#define Maxsize 40

int main()
{
    Functions f;
    Buckets* contacts = new Buckets[Maxsize];
    for(int i=0;i<Maxsize;i++)
    {
        contacts[i].head=new HashNode;
        contacts[i].head->next=NULL;
    }
    int n;
    f.ReadData(contacts);
    // HashNode data[3]={{"张三","1"},{"李四","2"},{"王五","3"}};
    // f.TraverseHash(contacts);
    // f.SearchHash(contacts,"张三");
    // f.DeleteHash(contacts,"张三");
    // f.SearchHash(contacts,"张三");
    // f.InsertHash(contacts,{"赵六","4"});
    // f.SearchHash(contacts,"赵六");

    ////待新增用户交互功能
    
    f.WriteData(contacts);
    return 0;
}