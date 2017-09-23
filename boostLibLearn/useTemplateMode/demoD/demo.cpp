 #include<iostream>
 #include "demo.h"
 
 template<class T> A<T>::A(){}
 
 template<class T> T A<T>::g(T a,T b){
     return a+b;
 }
 
 int main(int argc,char **agrv){
     A<int> a;
     std::cout<<a.g(2,3.2)<<std::endl;
	return 0;
 }
