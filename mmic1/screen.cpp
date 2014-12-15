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
		//*reinterpret_cast<type-id> (expression)�����԰�һ��ָ��ת����һ��������Ҳ���԰�һ������ת����һ��ָ��
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
	//*static_cast < type-id > ( expression )���������expressionת��Ϊtype-id���ͣ���û������ʱ���ͼ������֤ת���İ�ȫ�ԡ�
	freeStore=(static_cast<Screen*>(p));
}