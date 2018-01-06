#include <iostream>
#include "Enemy.h"

using namespace std;

Enemy::Enemy(){}

Enemy::~Enemy(){}

string Enemy::getName() {
	return name;
}

void Enemy::setType(int whatType) {
	type = whatType;
}

int Enemy::getType() {
	return type;
}

int Enemy::getHealth_max() {
	return health;
}

void Enemy::setHealth_max(int hp_m) {
	health_max = hp_m;

}

int Enemy::getHealth() {
	return health;
}

void Enemy::setHealth(int hp) {
	health = hp;

}

int Enemy::getMagic_max() {
	return magic_max;
}

void Enemy::setMagic_max(int mp_m) {
	magic_max = mp_m;

}

int Enemy::getMagic() {
	return magic;
}

void Enemy::setMagic(int mp) {
	magic = mp;

}

int Enemy::getAttack() {
	return attack;
}

void Enemy::setAttack(int a) {
	attack = a;

}

int Enemy::getDefend() {
	return defend;
}

void Enemy::setDefend(int d) {
	defend = d;
}

int* Enemy::getGoodsId(){
	return goodsId;
}

int* Enemy::getGoodsNum() {
	return goodsNum;
}

int Enemy::getExp(){
	return exp;
}

int Enemy::getMoney(){
	return money;
}

double Enemy::useSkill(){
	return getAttack() * 1.5;
}

void Enemy::showEnemy() {
	cout <<endl<< "当前怪物属性:" <<'\t';
	cout << "名称:" << name << '\t'<<endl;
	cout << "生命值:" << health << "/" << health_max << '\t';
	cout << "魔法值:" << magic << "/" << magic_max << endl;
	cout << "攻击:" << attack << '\t';
	cout << "防御:" << defend << endl;
}


Enemy_Small::Enemy_Small() {  //小怪统一血量和攻击？
	health = 50;
	attack = 5;
}

Enemy_Small::~Enemy_Small(){}

Enemy_Boss::Enemy_Boss(int whatType) {
	setType(whatType);
	switch (whatType) {
	case 1: {
		name = "暗影黑狼";
		type = 0;
		health = 150;
		health_max = 150;
		magic = 100;
		magic_max = 100;
		attack = 20;
		defend = 10;

		goodsNum[0] = 2;		//对应每件物品的数量
		goodsNum[1] = 1;
		goodsNum[2] = 0;
		goodsNum[3] = 0;
		goodsId[0] = 0;	//打死该怪物会掉落的物品
		goodsId[1] = 1;
		goodsId[2] = -1;	//空，代表只有以上两件
		goodsId[3] = -1;

		exp = 8;		//打死该怪物得到的经验
		money = 30;		//打死该怪物得到的金钱
		break;
	}
	case 3: {
		name = "史诗绯红印记树怪";
		type = 2;
		health = 350;
		health_max = 350;
		magic = 120;
		magic_max = 120;
		attack = 30;
		defend = 15;

		goodsNum[0] = 2;			//对应每件物品的数量
		goodsNum[1] = 1;
		goodsNum[2] = 1;
		goodsNum[3] = 0;
		goodsId[0] = 2;	//打死该怪物会掉落的物品
		goodsId[1] = 3;
		goodsId[2] = 4;	
		goodsId[3] = -1;

		exp = 10;		//打死该怪物得到的经验
		money = 50;		//打死该怪物得到的金钱
		break;
	}
	case 4: {
		name = "史诗苍老雕文魔像";
		type = 3;
		health = 700;
		health_max = 700;
		magic = 120;
		magic_max = 120;
		attack = 100;
		defend = 50;

		goodsNum[0] = 2;			//对应每件物品的数量
		goodsNum[1] = 2;
		goodsNum[2] = 1;
		goodsNum[3] = 0;
		goodsId[0] = 5;	//打死该怪物会掉落的物品
		goodsId[1] = 6;
		goodsId[2] = 7;
		goodsId[3] = -1;
		

		exp = 10;		//打死该怪物得到的经验
		money = 50;		//打死该怪物得到的金钱
		break;
	}
	case 5: {
		name = "传说级远古石甲虫";
		type = 4;
		health = 1000;
		health_max =1000;
		magic = 110;
		magic_max = 110;
		attack = 200;
		defend = 100;

		goodsNum[0] = 2;			//对应每件物品的数量
		goodsNum[1] = 0;
		goodsNum[2] = 1;
		goodsNum[3] = 0;
		goodsId[0] = 8;	//打死该怪物会掉落的物品
		goodsId[1] = -1;
		goodsId[2] = 10;
		goodsId[3] = -1;

		exp = 15;		//打死该怪物得到的经验
		money = 40;		//打死该怪物得到的金钱
		break;
	}

	case 6: {
		name = "传说级深红锋啄鸟";
		type = 5;
		health = 4000;
		health_max = 4000;
		magic = 110;
		magic_max = 110;
		attack = 400;
		defend = 200;

		goodsNum[0] = 2;			//对应每件物品的数量
		goodsNum[1] = 3;
		goodsNum[2] = 2;
		goodsNum[3] = 0;
		goodsId[0] = 11;	//打死该怪物会掉落的物品
		goodsId[1] = 12;
		goodsId[2] = 13;
		goodsId[3] = -1;
		
		exp = 15;		//打死该怪物得到的经验
		money = 40;		//打死该怪物得到的金钱
		break;
	}
	case 7: {
		name = "传说级魔沼蛙";
		type = 6;
		health = 4000;
		health_max = 4000;
		magic = 110;
		magic_max = 110;
		attack = 400;
		defend = 200;

		goodsNum[0] = 2;			//对应每件物品的数量
		goodsNum[1] = 3;
		goodsNum[2] = 2;
		goodsNum[3] = 0;
		goodsId[0] = 14;	//打死该怪物会掉落的物品
		goodsId[1] = 15;
		goodsId[2] = 16;
		goodsId[3] = -1;
		
		exp = 15;		//打死该怪物得到的经验
		money = 40;		//打死该怪物得到的金钱
		break;
	}
	case 8: {
		name = "炼狱巨龙";
		type = 7;
		health = 8000;
		health_max = 8000;
		magic = 310;
		magic_max = 310;
		attack = 600;
		defend = 500;

		goodsNum[0] = 2;			//对应每件物品的数量
		goodsNum[1] = 3;
		goodsNum[2] = 2;
		goodsNum[3] = 1;
		goodsId[0] = 18;	//打死该怪物会掉落的物品
		goodsId[1] = 19;
		goodsId[2] = 20;
		goodsId[3] = 21;

		exp = 30;		//打死该怪物得到的经验
		money = 110;		//打死该怪物得到的金钱
		break;
	}
	case 9: {
		name = "最强霸龙纳什男爵";
		type = 8;
		health = 12000;
		health_max = 12000;
		magic = 510;
		magic_max = 510;
		attack = 800;
		defend = 700;

		goodsNum[0] = 2;			//对应每件物品的数量
		goodsNum[1] = 3;
		goodsNum[2] = 2;
		goodsNum[3] = 1;
		goodsId[0] = 20;	//打死该怪物会掉落的物品
		goodsId[1] = 21;
		goodsId[2] = 22;
		goodsId[3] = 23;

		
		exp = 50;		//打死该怪物得到的经验
		money = 500;		//打死该怪物得到的金钱
		break;
	}
	default:break;
	}
}