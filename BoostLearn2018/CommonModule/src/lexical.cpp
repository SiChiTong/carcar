#include "lexical.h"

void test_lexical_cast(){
	
	int tem=boost::lexical_cast<int>("123");
	std::cout<<tem<<"\n";
		
}
