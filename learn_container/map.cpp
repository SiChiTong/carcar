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
	public:
		~home(){
			cout<<"delete home object!"<<endl;
			delete pBook;
		}
		home(string *a,int num){
			vector<string> tem(a,a+num);
			books.assign(tem.begin(),tem.end());
		}
		void setABook(string** b,int num);
		void setPBook(){
			pBook->assign(books.begin(),books.end());
			
		};
		void displayAllBook();
		
	
};

void home::displayAllBook(){
	for(vector<string>::iterator _index=books.begin();_index!=books.end();_index++)
		cout<<*_index<<endl;
	for(vector<string*>::iterator _index1=aBook.begin();_index1!=aBook.end();_index1++)
		cout<<**_index1<<endl;
	for(vector<string>::iterator _index2=pBook->begin();_index2!=pBook->end();_index2++)
		cout<<*_index2<<endl;
};

void home::setABook(string** b,int num){
	aBook.assign(b,b+num);
	
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
	
	

}
