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
	private:
	string name ;
	stuInfo* info=new(stuInfo);
	public:
	stu();
	~stu(){printf("delete stu object!!");};
	void desplay();
};

stu::stu():name("okk"){
	info->age=0;
	info->_class="one";
	info->phone="15091545284";
	info->email="350817634@qq.com";
	info->sort=0;
}

void stu::desplay(){
	printf("name:%s,info->age:%d,info->_class:%s,info->phone:%s,info->email:%s,info->sort:%d"
	,name.c_str(),info->age,info->_class.c_str(),info->phone.c_str(),info->email.c_str(),info->sort);
}
int main(void)
{
	stu* student1=new(stu);
	student1->desplay();
}
