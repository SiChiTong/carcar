#include"common.h"
using namespace std;
class TestVec{
	private:
		vector<int>* _id=new vector<int>();
		vector<string>* _name=new vector<string>();
		map<int,string> _map;
	public:
	
	TestVec(int* id,int idSize,string* name,int nameSize);
	~TestVec(){
		cout<<"delete TestVec"<<endl;
		delete _id;
		delete _name;
		//delete _map;
	}
	int display();
	int operVec();
};
TestVec::TestVec(int* id,int idSize,string* name,int nameSize){
	for(int i=0;i<idSize;i++){
		_id->push_back(*(id+i));
	}
	_name->assign(name,name+nameSize); //initial data of name;
	for(int k=0;k<nameSize;k++)
		_map.insert(make_pair(*(id+k),*(name+k)));
	
	/*
	for(int j=0;j<nameSize;j++){
		_name->push_back(*(name+j));
		
	}
	*/
};
int TestVec::display(){
	vector<int>::iterator inter_id=_id->begin();
	vector<string>::iterator inter_name=_name->begin();
	map<int,string>::iterator intera_map=_map.begin();
	
	while(inter_id!=_id->end()){
		cout<<*inter_id<<endl;
		inter_id++;		
	}
	while(inter_name!=_name->end()){
		cout<<*inter_name<<endl;
		inter_name++;
		
	}
	while(intera_map!=_map.end()){
		cout<<intera_map->first<<":"<<intera_map->second<<endl;
		intera_map++;
	}
	return 0;
};

int TestVec::operVec(){
	//if(!_id->empty())
		//_id->clear();
	cout<<"_id->size():"<<_id->size()<<endl;
	cout<<"_id->front():"<<_id->front()<<endl;
	cout<<"sizeof(_id):"<<sizeof(_id)<<endl;
	cout<<"_id->pop_back()"<<endl;
	_id->pop_back();
	_id->pop_back();
	return 0;
	
};
int main()
{
	int temI[]={1,2,3,4,6,7,8,9};
	string temS[4]={"asdf","fff","tetet","kkk"};
	TestVec *obj=new TestVec(temI,sizeof(temI)/sizeof(int),temS,4);
	obj->operVec();
	obj->display();
	delete obj;
	
	
	
}