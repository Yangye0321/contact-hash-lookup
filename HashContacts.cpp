#include<iostream>
#include<fstream>
#include"Functions.h"
using namespace std;
#define Maxsize 53

int main()
{
    Functions f;
    Buckets* contacts = new Buckets[Maxsize];
    for(int i=0;i<Maxsize;i++)
    {
        contacts[i].head=new HashNode;
        contacts[i].head->next=NULL;
        contacts[i].head->st=0;
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
    cout<<"请输入要执行的功能号：1.查询 2.添加 3.删除 4.显示所有联系人 5.计算平均搜索长度 6.退出"<<endl;
    int choice;
    string name,pn;
    while(cin>>choice)
    {
        switch(choice)
        {
            case 1:
                cout<<"请输入要查询的姓名："<<endl;
                cin>>name;
                f.SearchHash(contacts,name);
                break;
            case 2:
                cout<<"请输入要添加的姓名和电话号码："<<endl;
                cin>>name>>pn;
                f.InsertHash(contacts,{name,pn});
                break;
            case 3:
                cout<<"请输入要删除的姓名："<<endl;
                cin>>name;
                f.DeleteHash(contacts,name);
                break;
            case 4:
                cout<<"显示所有联系人："<<endl;
                f.TraverseHash(contacts,1);
                break;
            case 5:
                cout<<"计算平均搜索长度："<<endl;
                f.CountASL(contacts);
                break;
            case 6:
                cout<<"退出程序！"<<endl;
                f.WriteData(contacts);
                return 0;
            default:
                cout<<"无效的功能号，请重新输入！"<<endl;
        }
        cout<<"请输入要执行的功能号：1.查询 2.添加 3.删除 4.显示所有联系人 5.计算平均搜索长度 6.退出"<<endl;
    }
    
    f.WriteData(contacts);
    return 0;
}