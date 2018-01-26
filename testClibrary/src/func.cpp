#include "func.h"

using namespace std;
void test_strtol(){
	char* digital="100";
	cout<<strtol("A",NULL,16)<<"\n";
	cout<<strtol("1010",NULL,2)<<"\n";
	cout<<atoi("900")<<"\n";
	cout<<atoi((const char*)digital)<<"\n";
}
void test_mem(){
	
	char buf[100]="just for you ok";
	char buf_b[]="1231";
	char buf_a[]="123";
	char* src=(char*)malloc(50);
	memcpy(src,buf,100);
	cout<<src<<"\n";
	//memset(src,0,50);
	char* tem=(char*)memchr(src,'for',50);
	cout<<sizeof(src)/sizeof(char)<<"\n";
	cout<<strlen(src)<<"\n";
	cout<<tem<<"\n";
	cout<<memcmp(buf_b,buf_a,sizeof(buf_a))<<"\n";		
}

void test_str(){
	
	char buf1[]="123";
	char buf2[]="123";
	char buf4[]="addfg";
	char buf3[]="this*is, a nice girl";
	cout<<strcmp(buf1,buf2)<<"\n";
	strcat(buf1,"add");
	strncat(buf1,buf4,2);	
	cout<<buf1<<"\n";
	
	#if 0
	char* sub_str=strstr(buf1,"23");
	char* ptr=strchr(buf1,'a');
	cout<<sub_str<<"\n";
	cout<<ptr<<"\n";	
	char* pch=strtok(buf3,"*");  //字符分割。
	while(pch!=NULL){
		
		cout<<pch<<"\n";
		pch=strtok(NULL,"*");
				
	}
	#endif
		
}

void test_string(){
	
	string str="sdf";
	string sub_str="asdf";
	char sub_cstr[]="asdf";
	cout<<memcmp(sub_cstr,sub_str.c_str(),sizeof(sub_cstr))<<"\n";
	cout<<str.compare(sub_str)<<"\n";
	str.append(sub_str);
	cout<<str<<"\n";
	str.assign(sub_str);
	cout<<str<<"\n";
	str.back()='!';
	cout<<str<<"\n";
	cout<<str.length()<<"\n";
	//sub_str.clear();
	size_t found;
	found=str.find("asdf",0);
	if(found!=std::string::npos)
		cout<<found<<"\n";
	sub_str.erase(1,2);
	cout<<sub_str<<"\n";
	
	string str1;
	str1=to_string(123)+"test to_string";
	cout<<str1<<"\n";
	string str_digital="12.345 1313"; //字符和数字的转化
	string str_int="990";
	size_t sz;
	cout<<stod(str_digital,&sz)<<"\n";
	cout<<stod(str_digital.substr(sz))<<"\n";
	
	cout<<stoi(str_int,nullptr,10)<<"\n";
		
}

void test_new_and_delete(){
	
	char* buf=new char[100];
	int* buf_int=new int(12);
	int* buf_int_arr=new int[10];
	string* buf_string(new string[10]);
	
	*(buf_string+3)="test string ok "+to_string(12.79999);
	cout<<*(buf_string+3)<<"\n";
	
	// initial buf_int_arr
	*(buf_int_arr+2)=255;
	sprintf(buf,"test new char");
	cout<<buf<<"\n";
	cout<<*buf_int<<"\n";
	cout<<*(buf_int_arr+2)<<"\n";	
	string str(buf);  //char* to string 
	cout<<str.length()<<"\n";
	
	delete[] buf;
	delete buf_int;
	delete[] buf_int_arr;
	delete[] buf_string;
		
}













