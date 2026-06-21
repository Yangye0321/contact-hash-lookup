#include<iostream>
#include<fstream>
#define Maxsize 40
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
class Functions
{
    public:
    unsigned int BKDRHash(char* str); //BKDRHash函数
    void TraverseHash(Buckets* con);  //遍历哈希表
    void CreateHash(Buckets* con,HashNode data[],int n);  //创建哈希表
    void InsertHash(Buckets* con,HashNode data);  //插入哈希表
    void SearchHash(Buckets* con,string name);  //查找哈希表
    void DeleteHash(Buckets* con,string name);  //删除哈希表中的节点
    void ReadData(Buckets* con);  //从文件中读取数据
    void WriteData(Buckets* con);  //将数据写入文件
};
