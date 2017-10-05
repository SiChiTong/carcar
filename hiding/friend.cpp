#include"common.h"
class abb;
//int abb::get(ab obj);
class ab{
	private:
	int a;
	int b;
	public:
	ab();
	friend void display(ab obj);
	friend void allDisplay(ab obj1,abb obj2);
	int get(abb obj);
};


ab::ab(){a=1;b=2;};
void display(ab obj){
	std::cout<<(obj.a+obj.b)<<std::endl;	
}

class abb{
	private:
	int a;
	public:
	int b;
	abb();
	friend void allDisplay(ab obj1,abb obj2);
	int get(ab obj);
	friend int get(abb obj);
};

abb::abb(){a=11,b=22;};
void allDisplay(ab obj1,abb obj2){
	std::cout<<(obj1.a+obj2.b)<<std::endl;
}

int ab::get(abb obj){
    return obj.b;
 };
int main(void){
	ab aa;
	abb bb;
//	display(aa);
//	allDisplay(aa,bb);
	std::cout<<aa.get(bb);
	return 0;
}
