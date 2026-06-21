#define Maxsize 40
unsigned int BKDRHash(char* str) //BKDRHashº¯Êý 
{
    unsigned int seed=131;
    unsigned int hash=0;
    
    while(*str)
    {
        hash=hash*seed+(*str++);
    }
    
    return hash%Maxsize;
}

void TraverseHash(Buckets* con)  //±éÀú¹þÏ£±í
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