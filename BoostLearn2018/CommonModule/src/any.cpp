#include "any.h"
using namespace std;
void test_any(){
	v_any tem_any;
	tem_any.push_back(2);
	tem_any.push_back(3.14);
	tem_any.push_back('a');
	tem_any.push_back(string("test any"));
	
	for(uint i=0;i<tem_any.size();i++){
		cout<<i<<":"<<tem_any[i].type().name()<<"\n";	
		try{
			int result=boost::any_cast<int>(tem_any[i]);
			cout<<result<<"\n";			
		}catch(boost::bad_any_cast &ex){
			cout<<"cast error:"<<ex.what()<<"\n";
						
		}
									
	}
		
}