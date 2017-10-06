/*
friend 使用
参考：http://blog.csdn.net/jackychu/article/details/3020866
designer:wenboGong
*/
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
	friend class abb;//友元类定义
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
	friend int ab::get(abb obj);//友元类内部函数
	void getAbFormAbb(ab ojb);
};

abb::abb(){a=11,b=22;};
void allDisplay(ab obj1,abb obj2){
	std::cout<<(obj1.a+obj2.b)<<std::endl;
}

int ab::get(abb obj){
    return obj.b;
 };

void abb::getAbFormAbb(ab ojb){

	std::cout<<ojb.a<<std::endl;
}
int main(void){
	ab aa;
	abb bb;
//测试模块
//	display(aa);
//	allDisplay(aa,bb);
//	std::cout<<aa.get(bb);
	bb.getAbFormAbb(aa);
	return 0;
}
