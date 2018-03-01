#include "func_pointer.h"
//模板
template <typename T,typename U>
U DoSun(T a,T b){
	
	std::cout<<"beginning !"<<"\n";
	U c=a+b;
	return c;
	
}
//func函数
int test_std_func(){
	typedef std::function<int(int,int)> pf;
	pf pf_ptr=DoSun<int,int>;
	std::cout<<pf_ptr(23,9)<<"\n";
	return 0;
	
}