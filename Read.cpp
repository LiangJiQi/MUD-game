#include"Read.h"
#include<iostream>
#include<fstream>
using namespace std;

Read::Read(int roleType) :player(roleType) {}

Role Read::getRole() {			//读取人物属性

	ifstream file;
	file.open("Save.dat");
	if (!file) {
		cout << "没有保存的游戏！" << endl;
		return player;
	}
	else if (file.read(reinterpret_cast<char *>(&player), sizeof(Role))) {
		cout << "读入成功！" << endl;
		return player;
	}
	else {
		cout << "读入失败！" << endl;
		return player;
	}
	file.close();
}