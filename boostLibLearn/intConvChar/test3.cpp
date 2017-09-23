#include <boost/lexical_cast.hpp>
#include <iostream>
int main()
{
        using std::cout;
        using std::endl;
        int i;
        try{
                i = boost::lexical_cast<int>("abcd");
        }
        catch(boost::bad_lexical_cast& e)
        {
                cout<<e.what()<<endl;
                return 1;
        }
        cout<<i<<endl;
        return 0;
}
