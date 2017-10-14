#include "common.h"
using namespace std;
typedef struct{

	int age;
	string _class;
	string phone;
	string email;
	int sort;


}stuInfo;

class stu{
	public:
	string name ;
	stuInfo* info=new stuInfo;
	public:
	stu();
        virtual ~stu(){
		printf("delete stu object!!");
		delete info;	
	};
	virtual void desplay();
};

class stuMan:public stu
{
	private:
	int *height=new(int);
	public:	
	stuMan();
	~stuMan(){
		printf("delete stuMan !!");
		delete height;
		//~stu();
		delete info;
	};
	void display();
};


stu::stu():name("okk"){
	info->age=0;
	info->_class="one";
	info->phone="15091545284";
	info->email="350817634@qq.com";
	info->sort=0;
};

void stu::desplay(){
	printf("name:%s,info->age:%d,info->_class:%s,info->phone:%s,info->email:%s,info->sort:%d\n"
	,name.c_str(),info->age,info->_class.c_str(),info->phone.c_str(),info->email.c_str(),info->sort);
};

stuMan::stuMan(){
	info->age=0;
        info->_class="one";
        info->phone="15091545284";
        info->email="350817634@qq.com";
        info->sort=0;
	name="hello";
	*height=175;
};

void stuMan::display(){

	std::cout<<"name:"<<name<<"info->age:"<<info->age<<"info->_class"<<info->_class<<"info->phone"
	<<info->phone<<"info->email:"<<info->email<<"info->sort:"<<info->sort<<"height:"<<*height<<endl;
}
int main(void)
{
	stu* student1=new stu();
	student1->desplay();
	stuMan* student2=new stuMan();
	student2->desplay();
	delete student1;
	//delete student2;

}
