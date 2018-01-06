#ifndef SAVE_H
#define SAVE_H
#include"Role.h"
#include"Bag.h"

class Save {
public:
	Save();
	~Save();
	static void setToFile(Role player);
	static void saveBag(int **saveBagArray);

private:
};

#endif