#include "test_class.h"
using namespace std;

BB::BB(int b):AA(b),bb(b){
	
	cout<<"test BB class"<<"\n";
	
}
int BB::func(AA& OBJ){
	
	int ret;
	ret=this->bb+this->aa+OBJ.Get();
	return ret;
		
}

AA::AA(int a){
	
	aa=a;
		
}

AA::AA(){
	
	aa=90;
}
int AA::Get(){
	return aa;
	
}
int TestClass(){
	
	AA* object_a(new AA(19));
	BB* object_b(new BB(14));
	cout<<object_b->func(*object_a)<<"\n";	
	cout<<"delete object"<<"\n";
	delete object_a;
	delete object_b;
	return 0;
}