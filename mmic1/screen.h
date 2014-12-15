#include <cstddef>
#include <iostream>
using namespace std;

class Screen{
public:
	Screen(int x): i(x){}					//*
	int get(){return i;}

	void* operator new(size_t);				//*
	void operator delete(void*, size_t);
private:
	Screen* next;
	static Screen* freeStore;
	static const int screenChunk;

	int i;
};
