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