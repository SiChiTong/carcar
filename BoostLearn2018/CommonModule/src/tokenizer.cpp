#include "tokenizer.h"
//字符切割
//参考：http://blog.csdn.net/huang_xw/article/details/8449045
void test_tokenizer(){
	
	std::string tem("th!is is ,a,test!");
	boost::char_separator<char> sep("!,"); //"!"和"," 为字符切割标志。
	boost::tokenizer<boost::char_separator<char>> object(tem,sep); 	
	//boost::tokenizer<> object(tem);	
	for(boost::tokenizer<boost::char_separator<char>>::iterator beg=object.begin();beg!=object.end();beg++){
		std::cout<<*beg<<"\n";					
	}	
	
}