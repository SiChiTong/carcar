#include "common.h"
class testLib
{
	private:
		sting *str_;
		char *strc_;
	public:
		testLib();
		~testLib();
		testLib(string* str,char* strc);
		int opreLib(string* str,char* strc);
		int display();
		

}

testLib::testLib(){
	str_=new sting("tests");
	strc_=new char("testc");	
}

testLib::~testLib(){
	delete str_;
	delete strc_;
	
}
testLib::testLib(string* str,char* strc){
	str_->assign(*str);
	strcpy(strc_,strc);
		
}

int testLib::opreLib(string* str,char* strc){
	
	str_->append(*str);
	strcat(strc_,strc);
	return 0;
	
	
}

int testLib::display(){
	
	cout<<"str_:"<<str_<<endl;
	cout<<"strc_:"<<strc_<<endl;
}


int main(int argc,char *argv[])
{
	testLib *obj=new testLib();
	obj->display();
	return 0;
	
	
}
