#include "c_pluse.h"

int TestVector(){
	std::vector<int> vec_int;
	vec_int.push_back(12);
	vec_int.push_back(13);
	for(auto &p:vec_int){
		std::cout<<p<<"\n";
		
	}
	return 0;
}
