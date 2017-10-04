#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
	int first[]={12,234,1,2,100,12,333,32,21};
	int second[]={234,1,2,44,3,12};
	std::vector<int> v(100);
	std::vector<int>::iterator it;

	std::sort(first,first+9);
	std::sort(second,second+6);
	it=std::set_union(first,first+9,second,second+5,v.begin());

	v.resize(it-v.begin());
	std::cout <<v.size()<<":v.size\n";
	for(it=v.begin();it!=v.end();it++){
		std::cout<<" "<<*it<<"\n";
	
	}
	return 0;
}

