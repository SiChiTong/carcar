#include "templateDemo.cpp"//watch out "not templateDemo.h" ,because of class mode
#include <iostream>
using namespace std;

int main(void){
    A<int> a;
    cout<<a.g(2,3)<<endl;
	return 0;
}
