#include "share_ptr.h"

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
