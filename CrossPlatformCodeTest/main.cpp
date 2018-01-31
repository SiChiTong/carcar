#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main(int argc,char** argv){
	
	#ifdef __linux
	printf("test at linux\n");
	#endif
	
	#ifdef __WIN32
	printf("test at window\n");
	#endif 
	
	
}





