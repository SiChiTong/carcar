#ifndef SHARE_PTR_H
#define SHARE_PTR_H
#include "common.h"
using namespace std;

class SharePtr{

    private:
		vector<std::string> name_;
		int id_;
		char* backup_;
	public:
		SharePtr(std::string* name_begin,int name_size);
		~SharePtr();
		void Display();		

};

void TestSharePtr();

int TestScopePtr();

#endif