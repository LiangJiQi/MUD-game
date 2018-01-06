#ifndef ENEMY_H
#define ENEMY_H

#include <string>

using namespace std;

class Enemy {

public:
	Enemy();
	~Enemy();
	string getName();
	void setType(int whattype);
	int getType();

	int getHealth_max();
	void setHealth_max(int hp_m);

	int getHealth();
	void setHealth(int hp);

	int getMagic_max();
	void setMagic_max(int mp_m);

	int getMagic();
	void setMagic(int mp);

	int getAttack();
	void setAttack(int a);

	int getDefend();
	void setDefend(int d);


	int* getGoodsId();		//掉落物品
	int* getGoodsNum();		//掉落物品数量
	int getExp();			//增加经验
	int getMoney();			//增加金钱

	double useSkill();	//怪物使用技能，返回伤害数值

	void showEnemy();

protected:
	string name;
	int type;
	int health_max;
	int health;
	int magic_max;
	int magic;
	int attack;
	int defend;

	int goodsId[4]; //打死怪物会掉落的物品
	int goodsNum[4];//打死怪物会掉落的物品数量
	int exp;  //打死怪物增加的经验
	int money;  //打死怪物增加的金钱
};

class Enemy_Small {	//小怪
public:
	Enemy_Small();
	~Enemy_Small();
private:
	int health;
	int attack;
};

class Enemy_Boss :public Enemy { //大怪
public:
	Enemy_Boss();
	Enemy_Boss(int type);
	~Enemy_Boss() {};

};
#endif