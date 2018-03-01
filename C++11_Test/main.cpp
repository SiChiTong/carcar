#include "c_pluse.h"
#include "func_pointer.h"
int main(int argc,char** argv){

	//TestVector();
	#if 0
	//函数指针使用
	typedef int (*PTRFUN)();
	PTRFUN PtrFun;	
	PtrFun=TestVector;	
	(*PtrFun)();
	//函数指针使用
	#endif
	
	test_std_func();
	return 0;

}
