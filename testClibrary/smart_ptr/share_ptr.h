#ifndef SHARE_PTR_H
#define SHARE_PTR_H

#include "common.h"

class SmartPtr{
	public:
		std::shared_ptr<std::vector<std::string>> data;
		SmartPtr();
	
};
class Parent{
	public:
		std::shared_ptr<std::list<int>> data_;
		Parent();
		int InsertData();
		int DisplayData()const;
		
};

void TestSmart();
void TestParentClass();

#endif