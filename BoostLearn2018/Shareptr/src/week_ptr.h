#ifndef WEEK_PTR_H
#define WEEK_PTR_H
#include "common.h"

class parent;
class father;
typedef boost::shared_ptr<parent> parent_ptr;
typedef boost::shared_ptr<father> father_ptr;
typedef boost::weak_ptr<father> father_weak_ptr;

class father{
	
	public:
		~father();
	public:
		parent_ptr parent_; 
};

class parent{
	
	public:
		~parent();
	public:
		father_weak_ptr father_;	
	
};


#endif