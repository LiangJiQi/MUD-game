#ifndef MAP_H
#define MAP_H

#include <string>
#include "Enemy.h"
#include"Role.h"
#include "Npc.h"

using namespace std;

class Map
{
public:
	Map();//初始位置为地图0
	Map(int pos); //由参数pos为所在位置
	~Map();
	void ShowMap();			//显示大地图
	void showRoom();		//显示身处的地方的信息，（有什么人可以交谈或者战斗）
	void Store();
	void Move(char order);
	bool isThereChat();
	bool isThereFight();
	int getPosition();

	string getNpcName();		//得到当前npc名字
	void setNpc(Npc newNpc);
	Role chatToNpc(Role player);
	int getNpcGoodsId();
	int getNpcGoodsNum();
	string getName();

private:
	string name;
	int position; //当前位置
	string mapName[10] = { "平江镇","官道","岳州城","西郊","五龙山","地宫","东郊","轩辕庙","十里坡","昆仑" };
	int mapNum;
	char pos[6][6];
	int dx;
	int dy;
	Npc npc;
};

#endif