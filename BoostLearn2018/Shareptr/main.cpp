#include "share_ptr.h"
#include "week_ptr.h"

//²Î¿¼£ºhttp://www.cnblogs.com/blueoverflow/p/4721202.html
using namespace std;
void test(){
	
	boost::shared_ptr<implementation> sp1(new implementation());
    std::cout<<"The Sample now has "<<sp1.use_count()<<" references\n";

    boost::shared_ptr<implementation> sp2 = sp1;
    std::cout<<"The Sample now has "<<sp2.use_count()<<" references\n";
    
    sp1.reset();
    std::cout<<"After Reset sp1. The Sample now has "<<sp2.use_count()<<" references\n";

    sp2.reset();
    std::cout<<"After Reset sp2.\n";
		
	
}

void test_week_ptr(){
	
	parent_ptr Parent(new parent());
	father_ptr Father(new father());
	
	Parent->father_=Father;
	Father->parent_=Parent;
	
	//Parent.reset();
	//Father.reset();
	
	cout<<"Parent share ptr counter:"<<Parent.use_count()<<"\n";
	cout<<"Father share ptr counter:"<<Father.use_count()<<endl;
	
	
}

int main(int argc,char** argv){
	
	//test();
	test_week_ptr();
	
	
}