#ifndef SHARE_PTR_H
#define SHARE_PTR_H

#include "common.h"

class SmartPtr{
	public:
		std::shared_ptr<std::vector<std::string>> data;
		SmartPtr();
	
};

void TestSmart();

#endif