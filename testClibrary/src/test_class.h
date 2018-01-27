#ifndef TEST_CLASS_H
#define TEST_CLASS_H

#include "common.h"
class AA{
	
	public:
		AA(int a);
		AA();
		int Get();
	protected:
		int aa;
		
};

class BB:public AA
{
	
	public:
		BB(int b);
		int bb;
		int func(AA& OBJ);		
};

int TestClass();


#endif

