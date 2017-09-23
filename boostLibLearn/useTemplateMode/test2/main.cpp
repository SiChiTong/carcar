#include<iostream>  
#include "template_compile.cpp"  
using namespace std;  
int main(void)  
{  
    base<int> bobj;  
    cout<<bobj.add_base(2,3)<<endl;  
	return 0;
}  
