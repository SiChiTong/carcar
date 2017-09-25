#include "common.h"
using namespace std;
/*
1.boost::any

boost::any是一种通用的数据类型，可以将各种类型包装后统一放入容器内
最重要的它是类型安全的。有点象COM里面的variant.

使用方法：
any::type() 返回包装的类型
any_cast可用于any到其他类型的转化

*/
void test_any()
{
	typedef std::vector<boost::any> many;
 	many a;
 	a.push_back(123);
 	a.push_back(string("test"));

 	for(unsigned int i=0;i<a.size();++i)
 	{
  	cout<<a[i].type().name()<<endl;
  	try
  	{
 //  string result = boost::any_cast<string>(a[i]);
		int result = boost::any_cast<int>(a[i]);
   		cout<<result<<endl;
  	}
 	 catch(boost::bad_any_cast & ex)
  	{
   		cout<<"cast error:"<<ex.what()<<endl;
 	 }
 	}
}


/*
2 boost::array仅仅是对数组一层薄薄的封装，提供跟各种算法配合的iterator,使用方法很简单
注意：可以使用{}来初始化array,因为array所有的成员变量都是public的

*/
void test_array()
{
	boost::array<int,10> ai = {1,2,3};


	for(size_t i=0;i<ai.size();++i)
 	{
  		cout<<ai[i]<<endl;
 	}
}
/*

lexical_cast用于将字符串转换成各种数字类型(int,float,short etc.)
*/
void test_lexical_cast()
{
 	int i = boost::lexical_cast<int>("123");
 	string m=boost::lexical_cast<string>(666);
 	cout << i << endl;
	cout << m << endl;
}

/*

boost::format是用于替代c里面的sprintf，优点是类型安全，不会因为类型和参数不匹配而导致程序崩溃了
而且还可以重复使用参数
*/
void test_format()
{
 cout << boost::format("writing %1%,  x=%2% : %3%-th try") % "toto" % 40.23 % 50 <<endl; 

 boost::format f("a=%1%,b=%2%,c=%3%,a=%1%");
 f %"string"%2%10.0;
 cout << f.str() << endl;

}

/*
boost::tokenizer是用于切割字符串的，类似于Java里面的StringTokenizer
*/
void test_tokenizer()
{
 string s("This is  , a ,test!");
 boost::tokenizer<> tok(s);
 for(boost::tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg){
       cout << *beg << "\n";
 }
}


/*
boost::thread是为了提供跨平台的thread机制。
利用boost::function来完成委托
*/
void mythread()
{
 cout<<"hello,thread!"<<endl;
}

void test_thread()
{
 boost::function< void () > f(mythread);
 boost::thread t(f);
 t.join();
 cout<<"thread is over!"<<endl;
}

struct test
{
 int foo(int x,int y)
 {
  cout<< "(test::foo invoking)x = "<<x << " y = "<< y <<endl;
  return x+y;
 }
};

int foo(int x,int y)
{
 cout<< "(foo invoking)x = "<<x << " y = "<< y <<endl;
 return x+y;
}


//泛函数使用
void test_function()
{
 boost::function<int (int,int)> f;
 f = foo;
 cout << "f(2,3)="<<f(2,3)<<endl;

 test x;
 /*f = std::bind1st(
      std::mem_fun(&test::foo), &x);*/
 boost::function<int (test*,int,int)> f2;
 f2 = &test::foo;
  
 cout << "f2(5,3)="<<f2(&x,5,3)<<endl;
}


//智能指针
//参考：http://www.cnblogs.com/TianFang/archive/2008/09/19/1294521.html

class implementation
{
public:
    ~implementation() { std::cout <<"destroying implementation\n"; }
    void do_something() { std::cout << "did something\n"; }
};

void test()
{
    boost::shared_ptr<implementation> sp1(new implementation());//申请指针，引用计数器加1
    std::cout<<"The Sample now has "<<sp1.use_count()<<" references\n";

    boost::shared_ptr<implementation> sp2 = sp1;
    std::cout<<"The Sample now has "<<sp2.use_count()<<" references\n";
    
    sp1.reset();//释放资源，引用计数器减1
    std::cout<<"After Reset sp1. The Sample now has "<<sp2.use_count()<<" references\n";

    sp2.reset();
    std::cout<<"After Reset sp2.\n";
}


int main(void)
{
	//test_any();
	//test_array();	
	//test_lexical_cast();
	//test_format();
	//test_tokenizer();
	//test_thread();
	//test_function();
	test();
}









