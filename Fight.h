#ifndef FIGHT_H
#define FIGHT_H

#include "Enemy.h"
#include "Bag.h"
#include "Skill.h"
#include "Role.h"
#include"Goods.h"

class Fight {

public:
	Fight(Role player, Enemy enemy);
	~Fight();
	bool fightRound();//显示当前回合战斗,返回是否逃跑
	void showFight();//显示战斗状态
	void enemyFight();	//怪物的随机攻击
	bool isFightEnd();//判断是否结束
	Role& endFight();//结束战斗,将战斗完后的玩家返回覆盖main里的
	Role& runEndFight();	//逃跑结束战斗

	void addMoney(int addMoney);//添加金钱
	void addFightEndGoods(int* addGoods,int* num);//添加物品
	void addExp(int addExp);//添加经验

	void recoverHpOrMp();//物品回复生命值


	//void RoleuseSkill();	//战斗角色中使用技能

	void GameEnd();//判断游戏结束，程序退出，可以不放在这

private:
	Role player;//战斗的角色
	Enemy enemy;//战斗的怪物
	int round;//回合数
	double hurt;//战斗产生的伤害值
	Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
};

#endif