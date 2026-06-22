#include<iostream>
#include<fstream>
#include<iomanip>
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
    int choice_sw;
    cout<<"请输入哈希查询方式：1.按姓名 2.按电话号码"<<endl;

    // HashNode data[3]={{"张三","1"},{"李四","2"},{"王五","3"}};
    // f.TraverseHash(contacts);
    // f.SearchHash(contacts,"张三");
    // f.DeleteHash(contacts,"张三");
    // f.SearchHash(contacts,"张三");
    // f.InsertHash(contacts,{"赵六","4"});
    // f.SearchHash(contacts,"赵六");

    ////待新增用户交互功能
    bool off=true;
    while(cin>>choice_sw)
    {
        if(choice_sw!=1&&choice_sw!=2)
        {
            cout<<"无效的查询方式，请重新输入！"<<endl;
            break;
        }
        f.ReadData(contacts,choice_sw);
        cout<<"请输入要执行的功能号：1.查询 2.添加 3.删除 4.显示所有联系人 5.计算平均搜索长度 6.更改查询方式 7.退出"<<endl;
        string name,pn,addr;
        int choice;
        while(off && cin>>choice)
        {
            switch(choice)
            {
                case 1:
                    if(choice_sw==1)
                    {
                        cout<<"请输入要查询的姓名："<<endl;
                        cin>>name;
                        f.SearchHash(contacts,name,1);
                    }
                    else if(choice_sw==2)
                    {
                        cout<<"请输入要查询的电话号码："<<endl;
                        cin>>pn;
                        f.SearchHash(contacts,pn,2);
                    }
                    break;
                case 2:
                    cout<<"请输入要添加的姓名、电话号码和地址："<<endl;
                    cin>>name>>pn>>addr;
                    f.InsertHash(contacts,{name,pn,addr});
                    break;
                case 3:
                    if(choice_sw==1)
                    {
                        cout<<"请输入要删除联系人的姓名："<<endl;
                        cin>>name;
                        f.DeleteHash(contacts,name);
                    }
                    else if(choice_sw==2)
                    {
                        cout<<"请输入要删除联系人的电话号码："<<endl;
                        cin>>pn;
                        f.DeleteHash(contacts,pn);
                    }

                    break;
                case 4:
                    cout<<"显示所有联系人："<<endl;
                    cout << left << setw(10) << "序号" << setw(10) << "姓名" << setw(15) << "电话号码" << setw(30) << "地址" << setw(10) << "查找次数" << endl;
                    cout << "----------------------------------------------------------------------------" << endl;
                    f.TraverseHash(contacts,1);
                    break;
                case 5:
                    cout<<"计算平均搜索长度："<<endl;
                    f.CountASL(contacts);
                    break;
                case 6:
                    cout<<"更改查询方式！"<<endl;
                    off=false;
                    f.WriteData(contacts);
                    f.ClearHash(contacts);
                    break;
                case 7:
                    cout<<"退出程序！"<<endl;
                    f.WriteData(contacts);
                    return 0;
                default:
                    cout<<"无效的功能号，请重新输入！"<<endl;
            }
            if(off)
                cout<<"请输入要执行的功能号：1.查询 2.添加 3.删除 4.显示所有联系人 5.计算平均搜索长度 6.更改查询方式 7.退出"<<endl;
        }
        off=true;
        cout<<"请输入哈希查询方式：1.按姓名 2.按电话号码"<<endl;
    }
    cin.get();
    return 0;
}