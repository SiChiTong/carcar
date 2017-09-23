#include <string>
#include <iostream>
#include <boost/scoped_ptr.hpp>

class implementation
{
public:
    ~implementation() { std::cout <<"destroying implementation\n"; }
    void do_something() { std::cout << "did something\n"; }
};

void test()
{
    boost::scoped_ptr<implementation> impl(new implementation());
    impl->do_something();
}

int main()
{
    std::cout<<"Test Begin ... \n";
    test();
    std::cout<<"Test End.\n";
	return 0;
}
