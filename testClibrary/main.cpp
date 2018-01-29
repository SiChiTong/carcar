#include "func.h"
#include "test_class.h"
#include "share_ptr.h"
using namespace std;
int aa=12;
int main(int argc,char** argv){
	
	//test_strtol();
	//test_mem();
	//test_str();
	//test_string();
	//test_new_and_delete();
	//TestClass();
    //test_share_ptr();	
	#if 0
	int aa=90;
	cout<<aa<<"\n";   // 打印局部变量 90
	cout<<::aa<<"\n"; //打印全局变量 12
	#endif 
	
	//TestSmart();
	TestParentClass();
}

