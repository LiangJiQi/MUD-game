#ifndef NPC_H
#define NPC_H
#include<string>
#include"Role.h"

class Npc{
public:
	Npc(int num);
	~Npc();

	string getName();
	Role chat(Role player);
	int getGoodsId();
	int getGoodsNum();
	int getMoney();
	bool isChatted(int whichNpc);
	
private:
	string name;
	int type;
	int goodId;
	int goodNum;
	int money;
	Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
	//const string name[6] = { "火行者","木行者","水行者","金行者","土行者","上帝" };
	//const int goodsId[6] = { 1,4,9,12,16,25 };		//6个Npc能给的物品
	//const int money[6] = { 25,34,49,52,66,75 };		//6个Npc能给的金钱
};

#endif