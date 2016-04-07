#ifndef ITEMS_H_
#define ITEMS_H_
#include <iostream>

class item
{
public:
	item();
	~item();

private:
	bool isConsumable;
	bool isStorageble;
};


#endif