#include"common.h"
extern "C" int printf (const char *, ...);
class a {
	public:
		int su(int i);
};

int a::su(int i){
	printf("__FUNCTION__:%s\n",__FUNCTION__);
	printf("__PRETTY_FUNCTION__:%s\n",__PRETTY_FUNCTION__);
	printf("__LINE__:%d\n",__LINE__);
	return 0;
}

int main(void){

	a ax;
	ax.su(0);
	return 0;
}
