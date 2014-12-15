#include "screen.h"

int main(){
	cout<<sizeof(Screen)<<endl;
	Screen* psl=new Screen(1);
	Screen* psl2=new Screen(2);
	cout<<psl<<" "<<psl->get()<<endl;
	cout<<psl2<<" "<<psl2->get()<<endl;
	delete psl;
	delete psl2;
	return 0;
}