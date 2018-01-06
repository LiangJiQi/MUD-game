#include "Fight.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Fight::Fight(Role player, Enemy enemy) :player(player), enemy(enemy) {
	round = 1;
}
Fight::~Fight(){}

//每回合战斗
bool Fight::fightRound() {
	
	showFight();
	cout << "请选择：1，普通攻击 2，使用技能 3，使用药品 4，逃跑" << endl;
	int choices = 0;
	while (true) {
		cin >> choices;
		if (choices != 1 && choices != 2 && choices != 3 && choices != 4)
			cout << "选择错误，请重新选择。" << endl;
		else break;
	}

	if (choices == 1) {
		hurt = player.getAttack() - enemy.getDefend();
		if (hurt <= 0)
			cout << enemy.getName() << "的防御力抵挡了你的普通攻击，没有造成伤害。" << endl;
		else {
			cout << "你对" << enemy.getName() << "造成了" << hurt << "的普通伤害。" << endl;
			if (hurt > 50)
				cout << "三只小野怪已死亡。" << endl;
			enemy.setHealth(enemy.getHealth() - hurt);
		}
			if (isFightEnd() == false)
				enemyFight();		//怪物攻击
		
		
	}
	if (choices == 2) {
		if (player.showSkill()== false) {
			cout << "请重新选择攻击方式。" << endl<<endl;
			return false;
		}
		else {
			hurt = player.useSkill() * player.getAttack() - enemy.getDefend();
			if (hurt <= 0)
				cout << enemy.getName() << "的防御力抵挡了你的技能攻击，没有造成伤害。" << endl;
			else {
				cout << enemy.getName() << "造成了" << hurt << "的技能伤害。" << endl;
				enemy.setHealth(enemy.getHealth() - hurt);
			}
				if (isFightEnd() == false)
					enemyFight();  //怪物攻击
			
			
		}
	}
	if (choices == 3) {
		recoverHpOrMp();
		if (isFightEnd() == false)
			enemyFight();  //怪物攻击
	}
	if (choices == 4) {
		srand((unsigned)time(NULL));
		if (rand() % 100 <= 50) {			//一半的可能性成功
			cout << "逃跑失败!" << endl;
			if (isFightEnd() == false)
				enemyFight();  //怪物攻击
			return false;
		}
		else {
			cout << "逃跑成功!" << endl;
			return true;	//跳转至战斗逃跑结束，没有获得增益
		}
	}
	round++;		//回合数加一
	return false;				//战斗未逃跑
}

//显示战斗的状态
void Fight::showFight() {
	
	player.showRole();
	cout << endl;
	enemy.showEnemy();
	cout << endl << "当前为第" << round << "回合" << endl;
}

//怪物的随机战斗
void Fight::enemyFight() {
	srand((unsigned)time(NULL));
	if (rand() % 100 <= 50 ) {
		hurt = enemy.getAttack() - player.getDefend();
		if (hurt <= 0)
			cout << "你的防御力抵挡了" << enemy.getName() << "的普通攻击，没有对你造成伤害。" << endl;
		else {
			player.setHealth(player.getHealth() - hurt);
			cout << enemy.getName() << "对你造成了" << hurt << "的普通伤害" << endl;
		}
	}
	else {
		if (enemy.getMagic() < 20)
			cout <<enemy.getName()<< "的魔法值不足，无法发动技能，没有对你造成伤害。" << endl;
		else {
			hurt = enemy.useSkill() - player.getDefend();
			if (hurt <= 0)
				cout << "你的防御力抵挡了"<<enemy.getName()<<"的技能攻击，没有对你造成伤害。" << endl;
			else {
				cout << enemy.getName() <<"耗费"<<20<< "点魔法值使用技能对你造成了" << hurt << "的技能伤害。" << endl;
				player.setHealth(player.getHealth() - hurt); //使用技能并造成伤害
				enemy.setMagic(enemy.getMagic() - 20);
			}
		}
	}
}

//判断战斗的结束
bool Fight::isFightEnd() { //判断战斗是否结束
	if (player.getHealth() <= 0) 
		GameEnd();		//跳转到程序结束
	if (enemy.getHealth() <= 0) 
		return true;
	else return false;
}

//游戏结束
void Fight::GameEnd() {   //不必放在这
	cout << "你已死亡，游戏结束。" << endl;
	cout << "人在江湖，身不由己，少侠，不要气馁，重新来过。" << endl;

//	......;//结束游戏或者......你懂的
	exit(0);		//程序结束
}

//正常结束结束战斗，获得增益
Role & Fight::endFight() {  //结束战斗
	cout << enemy.getName() << "已死亡，战斗结束" << endl;
	addMoney(enemy.getMoney());
	addExp(enemy.getExp());
	addFightEndGoods(enemy.getGoodsId(),enemy.getGoodsNum());
	return player;
}

//选择逃跑，没有增益
Role &Fight::runEndFight() {
	return player;
}

void Fight::addMoney(int addMoney) { //增加金钱
	cout << "你获得了" << addMoney << "点金钱。" << endl;
	player.setMoney(player.getMoney() + addMoney);
}

void Fight::addFightEndGoods(int* addGoodsId,int* num) {  //增加物品
	player.addGoodsToBag(addGoodsId,num);		//addGoodsToBag函数来判断是否能放入
}

void Fight::addExp(int addExp) {  //增加经验
	cout << "你获得了" << addExp << "点经验。" << endl << endl;
	player.setExp(player.getExp() + addExp);

}

//使用药品恢复
void Fight::recoverHpOrMp() { //消耗物品回复生命值
	if (player.getBag().getGoodsNum() <= 0)
		cout << "没有药品可用！" << endl;
	else {
		cout << "请选择要使用的药品（0取消）：" << endl;
		for (int i = player.getBag().getGoodsNum();i > 0;i--) {
			for (int j = 20;j < 24; j++)
				if (player.getBagWhichGoodsId(i) == j)
					cout << i << "." << '\t' << goods[player.getBagWhichGoodsId(i)].getName() << '\t' << player.getBagWhichGoodsNum(i) << " 件" << endl;
		}

		int choiceGoodsId, choiceGoodsNum;
		cin >> choiceGoodsId;
		if (choiceGoodsId > 0) {
			choiceGoodsId = player.getBagWhichGoodsId(choiceGoodsId);
			cout << "请选择使用多少：" << endl;
			cin >> choiceGoodsNum;
			player.subGoodsToBag(choiceGoodsId, choiceGoodsNum);
			cout << "成功使用药品！";
			if (choiceGoodsId == 20 || choiceGoodsId == 21) {
				for (int i = choiceGoodsNum;i > 0;i--)
					player.setHealth(goods[choiceGoodsId].getAddHP() + player.getHealth());
				cout << "共恢复" << goods[choiceGoodsId].getAddHP() * choiceGoodsNum << "点气血。" << endl << endl;
			}
			if (choiceGoodsId == 22 || choiceGoodsId == 23) {
				for (int i = choiceGoodsNum;i > 0;i--)
					player.setHealth(goods[choiceGoodsId].getAddMP() + player.getMagic());
				cout << "共恢复" << goods[choiceGoodsId].getAddMP() * choiceGoodsNum << "点内力。" << endl << endl;
			}
		}
	}
}
