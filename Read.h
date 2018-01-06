
#ifndef READ_H
#define READ_H

#include"Role.h"

class Read {

public:
	Read(int roleType);
	~Read();
	static Role getRole();
private:
	static Role player;
};

#endif