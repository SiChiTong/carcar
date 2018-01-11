#include "share_scoped.h"

FamilyTool::FamilyTool(const int& tool_id,const std::string& tool_name,
                       char* tool_attribute){
    tool_attribute_=new char[30];
	tool_id_=tool_id;
	tool_name_=tool_name;
	strcpy(tool_attribute_,tool_attribute);
	LOG("init FamilyTool!");

}

FamilyTool::~FamilyTool(){
	delete tool_attribute_;
	LOG("delete FamilyTool");

}

void FamilyTool::DisplayFamilyTool(){

	std::cout<<"tool_id_:"<<tool_id_<<std::endl;
	std::cout<<"tool_name_:"<<tool_name_<<std::endl;
	std::cout<<"tool_attribute_:"<<tool_attribute_<<std::endl;

}

int TestScoped(){
	
	boost::scoped_ptr<FamilyTool> object_family_too(new FamilyTool(12,"desk","eat meal"));
	if(object_family_too==nullptr){
		LOG("failed :apply FamilyTool object!");
		return -1;
	}else{

	object_family_too->DisplayFamilyTool();

	}
	return 0;	

}




