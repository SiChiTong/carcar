#include "share_ptr.h"

implementation:: ~implementation(){
	std::cout <<"destroying implementation\n"<<std::endl;
}
  
void implementation::do_something(){
	std::cout << "did something\n"<<std::endl; 
}