#include "share_ptr.h"
SmartPtr::SmartPtr():data(std::make_shared<std::vector<std::string>>()){}

Parent::Parent():data_(std::make_shared<std::list<int>>())
{
	
	std::cout<<"initial Parents !!!"<<"\n";
	
}
int Parent::InsertData(){
	
	for(int i=10;i<20;i++){
		
	    data_->push_back(i);
		
	}
	return 0;	
}

int Parent::DisplayData()const{
	
	std::list<int>::iterator iter;
	for(iter=data_->begin();iter!=data_->end();iter++){
		
		std::cout<<*iter<<"\n";
		
	}
	return 0;	
}

void TestSmart(){
	
	SmartPtr smart_ptr;
	smart_ptr.data->push_back("test smart");
	std::vector<std::string>::iterator itr;
	for(itr=smart_ptr.data->begin();itr!=smart_ptr.data->end();itr++){
		
		std::cout<<*itr<<"\n";

		
	}
}

void TestParentClass(){
	std::shared_ptr<Parent> parent;
	parent=std::make_shared<Parent>();
	std::cout<<parent.use_count()<<"\n";  //智能指针资源统计
	std::shared_ptr<Parent> chrid(parent);
	
	
	parent->InsertData();
	parent->DisplayData();
	std::cout<<parent.use_count()<<"\n";
	
	std::cout<<"smart ptr authority shift"<<"\n";
	//chrid->InsertData();
    chrid->DisplayData();
	std::cout<<parent.use_count()<<"\n";
}

