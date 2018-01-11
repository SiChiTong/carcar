#include "share_ptr.h"
#include "log_system.h"
#define NUM 3
using namespace std;

SharePtr::SharePtr(std::string* name_begin,int name_size){

	backup_=new char[30];
	LOG("init SharePtr");	
	for(int i=0;i<name_size;i++){
		name_.push_back(*(name_begin+i));		
	
	}

}

SharePtr::~SharePtr(){

	LOG("delete SharePtr");
	delete backup_;
	
}

void SharePtr::Display(){


	for(vector<std::string>::iterator iter=name_.begin();
	    iter!=name_.end();iter++){

		std::cout<<*iter<<"\n";
	}

}

void TestSharePtr(){

	std::string str_arry[NUM];
	str_arry[0]="I ";
	str_arry[1]="Love ";
	str_arry[2]="You!";
	
	boost::shared_ptr<SharePtr> share_ptr_obj(new SharePtr(str_arry,NUM));
	share_ptr_obj->Display();

}

//test scope ptr

int TestScopePtr(){
	boost::scoped_ptr<int> sample_ptr(new int(12));
	if(sample_ptr==nullptr){
		LOG("sample_ptr->isValid() filed");
		
		return -1;
		
	}
	LOG("sample_ptr success!!");
	std::cout<<"sample_ptr:"<<*sample_ptr<<"\n";
	return 0;		
}
