#include "common.h"
using namespace std;
typedef struct{

	int age;
	string _class;
	string phone;
	string email;
	int sort;


}stuInfo;

class stu{
	public:
	string name ;
	stuInfo* info=new stuInfo;
	public:
	stu();
        virtual ~stu(){
		printf("delete stu object!!\n");
		delete info;	
	};
	virtual void desplay();
};

class stuMan:public stu
{
	private:
	int *height=new(int);
	public:	
	stuMan();
	~stuMan(){
		printf("delete stuMan !!");
		delete height;
		//~stu();
		delete info;
	};
	void display();
};


stu::stu():name("okk"){
	info->age=0;
	info->_class="one";
	info->phone="15091545284";
	info->email="350817634@qq.com";
	info->sort=0;
};

void stu::desplay(){
	printf("name:%s,info->age:%d,info->_class:%s,info->phone:%s,info->email:%s,info->sort:%d\n"
	,name.c_str(),info->age,info->_class.c_str(),info->phone.c_str(),info->email.c_str(),info->sort);
};

stuMan::stuMan(){
	info->age=0;
        info->_class="one";
        info->phone="15091545284";
        info->email="350817634@qq.com";
        info->sort=0;
	name="hello";
	*height=175;
};

void stuMan::display(){

	std::cout<<"name:"<<name<<"info->age:"<<info->age<<"info->_class"<<info->_class<<"info->phone"
	<<info->phone<<"info->email:"<<info->email<<"info->sort:"<<info->sort<<"height:"<<*height<<endl;
}

class home{
	private:
		vector<string> books;
		vector<string*> aBook;
		vector<string> *pBook=new(vector<string>);
		vector<string> booksSwap;
	public:
		~home(){
			cout<<"delete home object!"<<endl;
			delete pBook;
			
		}
		home(string *a,int num){
			vector<string> tem(a,a+num);
			books.assign(tem.begin(),tem.end());
			booksSwap.push_back("nice");
			booksSwap.push_back("beauty");
			booksSwap.push_back("good");
			booksSwap.push_back("good");
			booksSwap.push_back("good");
		}
		void setABook(string** b,int num);
		void setPBook(){
			pBook->assign(books.begin(),books.end());
			
		};
		void displayAllBook();
		void _operatorVector();
		
	
};

void home::displayAllBook(){
	for(vector<string>::iterator _index=books.begin();_index!=books.end();_index++)
		cout<<*_index<<endl;
	for(vector<string*>::iterator _index1=aBook.begin();_index1!=aBook.end();_index1++)
		cout<<**_index1<<endl;
	for(vector<string>::iterator _index2=pBook->begin();_index2!=pBook->end();_index2++)
		cout<<*_index2<<endl;
	for(vector<string>::iterator _index3=booksSwap.begin();_index3!=booksSwap.end();_index3++)
		cout<<*_index3<<endl;
};

void home::setABook(string** b,int num){
	aBook.assign(b,b+num);
	
};

void home::_operatorVector(){
	cout<<"pBook->size():"<<pBook->size()<<endl;
	cout<<"pBook->capacity:"<<pBook->capacity()<<endl;
	cout<<"books.swap(booksSwap)"<<endl;
	books.swap(booksSwap);
	cout<<"pBook->front():"<<pBook->front()<<endl;
	cout<<"pBook->back():"<<pBook->back()<<endl;
	cout<<"pBook->at(3):"<<pBook->at(3)<<endl;
	pBook->clear();
	if(pBook->empty())
		cout<<"execute erase()"<<endl;
		cout<<"pBook->size():"<<pBook->size()<<endl;
		cout<<"pBook->capacity:"<<pBook->capacity()<<endl;
};
int main(void)
{
	stu* student1=new stu();
	student1->desplay();
	stuMan* student2=new stuMan();
	student2->desplay();
	delete student1;
	//delete student2;
	string a[5]={"gong","wen","bo","like","code"};
	string *b[4]={&a[0],&a[1],&a[3],&a[4]};
	home Home(a,5);
	Home.displayAllBook();
	cout<<' '<<endl;
	Home.setABook(b,4);
	Home.displayAllBook();
	cout<<' '<<endl;
	Home.setPBook();
	Home.displayAllBook();
	Home._operatorVector();
    Home.displayAllBook();
	

}
