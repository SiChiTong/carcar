#include<iostream>
#include<algorithm>

using namespace std;
void show (int* a)
{
	for(int i=0;i<10;++i)
		cout<<"\t"<<*(a+i)<<endl;
}
int main()
{
	int a[]={1,2,23,21,35,23,0,9,123,12};
	show(a);
	sort(a,a+10);
	show(a);
	return 0;
}
