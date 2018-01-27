#include "share_ptr.h"
SmartPtr::SmartPtr():data(std::make_shared<std::vector<std::string>>()){}

void TestSmart(){
	
	SmartPtr smart_ptr;
	smart_ptr.data->push_back("test smart");
	std::vector<std::string>::iterator itr;
	for(itr=smart_ptr.data->begin();itr!=smart_ptr.data->end();itr++){
		
		std::cout<<*itr<<"\n";
		
	}
}