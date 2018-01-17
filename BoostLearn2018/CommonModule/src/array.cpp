#include "array.h"

void test_array(){
	
	boost::array<int,10> ai={1,2,3,900};
	for (size_t i=0;i<ai.size();i++){
		
		std::cout<<ai[i]<<"\n";		
		
	}	
}



