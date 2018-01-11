#ifndef SHARE_SCOPED_H
#define SHARE_SCOPED_H
#include "common.h"
#include "log_system.h"

class FamilyTool{

	private:
		int tool_id_;
		std::string tool_name_;
		char* tool_attribute_;
	public:
		FamilyTool(const int& tool_id,const std::string& tool_name,char* tool_attribute);
		~FamilyTool();
		void DisplayFamilyTool();

};

int TestScoped();

#endif





