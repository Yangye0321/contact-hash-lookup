#include<iostream>
#include<fstream>
#define Maxsize 53
using namespace std;
struct HashNode     //哈希表中的节点
{
    string name;
    string pn;     //phonenumber
    string addr;
    int st;        //searchtime
    int number;
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
    int TraverseHash(Buckets* con,int choice);  //遍历哈希表
    void CreateHash(Buckets* con,HashNode data[],int n,int choice);  //创建哈希表
    void InsertHash(Buckets* con,HashNode data);  //插入哈希表
    void SearchHash(Buckets* con,string key,int choice);  //查找哈希表
    void DeleteHash(Buckets* con,string name);  //删除哈希表中的节点
    void ReadData(Buckets* con,int choice);  //从文件中读取数据
    void WriteData(Buckets* con);  //将数据写入文件
    void visit1(HashNode p);
    void visit2(HashNode p,int& count);
    void visit3(HashNode p,int& total);
    void SortHash(Buckets* con);  //排序哈希表
    void CountASL(Buckets* con);  //计算平均搜索长度
    void ClearHash(Buckets* con);  //清空哈希表
};
