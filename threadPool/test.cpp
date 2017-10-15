//#include "common.h"
#include<iostream>
class BB;
class AA;
class BB {
	public: int c,d;
	void display1(AA *obj);
};
class AA {
	public: int a1,a2;
	public:
	AA(){a1=12;a2=23;};
	void display();
	friend void BB::display1(AA *obj);
};

void BB::display1(AA *obj){
	obj->display();
}

void AA::display(){
	std::cout<<a1<<","<<a2<<std::endl;

}
int main(void){
	
	AA *aa=new(AA);
	BB *bb=new(BB);
	bb->display1(aa);
}
