#include "screen.h"

Screen* Screen::freeStore=0;
const int Screen::screenChunk=24;

void* Screen::operator new(size_t size){
	Screen *p;
	if(!freeStore){
		//linked list is empty
		//call global operator new
		size_t chunk=screenChunk*size;
		freeStore=p=
			reinterpret_cast<Screen*>(new char[chunk]);			
		//*reinterpret_cast<type-id> (expression)它可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针
		for(; p!=&freeStore[screenChunk-1];++p)
			p->next=p+1;
		p->next=0;
	}
	p=freeStore;
	freeStore=freeStore->next;
	return p;
}
void Screen::operator delete(void* p, size_t){
	(static_cast<Screen*>(p))->next=freeStore;					
	//*static_cast < type-id > ( expression )该运算符把expression转换为type-id类型，但没有运行时类型检查来保证转换的安全性。
	freeStore=(static_cast<Screen*>(p));
}