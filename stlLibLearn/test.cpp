#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;
 
#define SIZE 100
int iarray[SIZE];
vector<int> intVector(100);

int arry(void){

   iarray[20] = 50;
   int* ip = find(iarray, iarray + SIZE, 50);
 // iarry 和iarry+size 是搜索的范围
 //必须记住STL使用模板。因此，STL函数自动根据它们使用的数据类型来构造
   if (ip == iarray + SIZE)
     cout << "50 not found in array" << endl;
   else
     cout << *ip << " found in array" << endl;
   return 0;


};

void vec_arry(void)
{
	intVector[20] = 50;
	vector<int>::iterator intIter =
   	find(intVector.begin(), intVector.end(), 50);
  	if (intIter != intVector.end())
    	cout << "Vector contains value " << *intIter << endl;
  	else
    	cout << "Vector does not contain 50" << endl;

}


int main()
{
	//arry();
	vec_arry();
}







