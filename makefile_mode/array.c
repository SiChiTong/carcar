//cut string for exmaple :"qweriiiiiiityuiop"  cut "qweriiiiiiityu" and "iop"
//and combine 2 part :result:iopqweriiiiiiityu
/*
 author:gongwnbo date:2017-9-21 
*/
#include<stdio.h>
#include<stdlib.h>
#define num 6
char a[]="qweriiiiiiityuiop";
void fun(char *str,int n,char* back)
{
	
	char *p=(char*)malloc(sizeof(a));//ack heap 
	int m=0,hold=0;
	while(*str!='\0')
	{
		*p=*str;
		p++;
		str++;
		m++;
	}	
	hold=m; //m is strlen(a[])
	printf("m=%d\n",m);	
	while(*(p-n)!='\0')//cut a[] for part2
	{
		*back=*(p-n);
		n--;
		back++;
	}
	while((p-m)!=(p-num))//cut a[] for part1
	{
		*back=*(p-m);
		back++;
		m--;	
	}
	free(p-hold); //important p is where end of a[].so must free "p-hold"
}

int main(void)
{
	printf("start\n");
	char *res=(char*)malloc(sizeof(a));
	fun(a,num,res);
	printf("old string:%s\n",a);
	printf("new string:%s\n",res);
	return 0;
	char *test=(char*)malloc(sizeof(a));
	test=a;	
	printf("test string:%s\n",test);
}



