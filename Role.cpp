#include <iostream>
#include <string>
#include "Role.h"

using namespace std;


Role::Role(int t):task(0){  //1战士2剑客3法师
	mapId = 0;
	switch (t) {
	case 0: {
		type = 0;		//用来判断有没有保存的游戏
		break;
	}
	case 1: {
		name = "弦倚";
		type = 1;
		health_max = 160;
		health = 160;
		magic_max = 100;
		magic = 100;
		attack = 30;
		exp = 0;
		exp_Max = 300;			//暂定
		level = 1;
		defend = 10;
		money = 0;
		skill = Role_1Skill::Role_1Skill();
		break;
	}
	case 2: {
		name = "凝幽";
		type = 2;
		health_max = 200;
		health = 200;
		magic_max = 100;
		magic = 100;
		attack = 30;
		exp = 0;
	//	exp_Max = 300;			//暂定
		level = 1;
		defend = 10;
		money = 0;
		skill = Role_2Skill::Role_2Skill();
		break;
	}
	case 3: {
		name = "拢月";
		type = 3;
		health_max = 120;
		health = 120;
		magic_max = 100;
		magic = 100;
		attack = 45;
		exp = 0;
		//exp_Max = 300;				//暂定
		level = 1;
		defend = 10;
		money = 0;
		skill = Role_3Skill::Role_3Skill();
		break;
	}
	default:break;
	}
}

void Role::operator=(Role player) {			//重载=实现深复制
	name = player.getName();
	type = player.getType();
	health_max = player.getHealth_max();
	health = player.getHealth();
	magic_max = player.getMagic_max();
	magic = player.getMagic();
	attack = player.getAttack();
	exp = player.getExp();

	level = player.getLevel();
	defend = player.getDefend();	
	money = player.getMoney();
	bag = player.getBag();		

	task = player.getTask();
	mapId = player.getMapId();		
	skill = player.getSkill();		
	story = player.getStory();
}

bool Role::showSkill() {    //返回是否有技能释放
	if (skill.getLevel(1) || skill.getLevel(2) || skill.getLevel(3) || skill.getLevel(4) ) {
		cout << "你可以选择使用的技能有：" << endl;
		if (skill.getLevel(1) )
			cout << "1技能：" << skill.getName(1) << ends << skill.getLevel(1) << "点" << '\t';
		if (skill.getLevel(2) )
			cout << "2技能：" << skill.getName(2) << ends << skill.getLevel(2) << "点" << '\t';
		if (skill.getLevel(3) )
			cout << "3技能：" << skill.getName(3) << ends << skill.getLevel(3) << "点" << '\t';
		if (skill.getLevel(4) )
			cout << "4技能：" << skill.getName(4) << ends << skill.getLevel(4) << "点" << '\t';
		cout << endl;
		return true;
	}
	else {
		cout << "你当前尚未习得任何技能。" << endl;
		return false;
	}
}
double Role::useSkill() {
		cout << endl << "请选择：";
		int useWhatSkill;
		cin >> useWhatSkill;
		if (skill.getLevel(useWhatSkill) <= 0) {
			cout << "你尚未习得该技能，无法使用。" << endl;
			return 0;
		}
		else if (getMagic() < skill.getNeedMP(useWhatSkill)) {
			cout << "你的蓝量不足，无法使用该技能。" << endl;
			return 0;
		}
		else {
			setMagic(getMagic() - skill.getNeedMP(useWhatSkill));
			cout << "你花费"<<skill.getNeedMP(useWhatSkill) <<"点内力使用了“" << skill.getName(useWhatSkill) << "”技能，对";			//这里跳转回Filght.cpp继续
			return skill.getAddAttack(useWhatSkill) + (1 + (skill.getLevel(useWhatSkill) * 0.1));//返回技能的攻击加成与技能等级提供的攻击加成
		}
}

Role::~Role() {}

string Role::getName() {
	return name;
}

int Role::getType() {
	return type;
}

int Role::getMapId() {
	return mapId;
}

void Role::setMapId(int NewMapId) {
	mapId = NewMapId;
}

int Role::getStory()
{
	return story;
}

void Role::setStory(int s)
{
	story = s;
}

int Role::getHealth_max() {
	return health_max;
}

void Role::setHealth_max(int hp_m) {
	health_max = hp_m;
}

int Role::getHealth() {
	return health;
}

void Role::setHealth(int hp) {
	health = hp;
	if ( hp > getHealth_max())
		health = getHealth_max();
	if (health < 0)
		health = 0;
}

int Role::getMagic_max() {
	return magic_max;
}

void Role::setMagic_max(int mp_m) {
	magic_max = mp_m;

}

int Role::getMagic() {
	return magic;
}

void Role::setMagic(int mp) {
	magic = mp;
	if (mp > getMagic_max())
		magic = getMagic_max();
	if (mp < 0)
		magic = 0;
}

int Role::getAttack() {
	return attack;
}

void Role::setAttack(int a) {
	attack = a;

}

int Role::getDefend() {
	return defend;
}

void Role::setDefend(int d) {
	defend = d;
}

int Role::getExp() {
	return exp;
}

void Role::setExp(int e) {
	exp = e;
	for (int i = 0;i < 29;i++)
		if (exp >= levelExp_Max[i] && exp < levelExp_Max[i + 1]) {
			setLevel(i+2);
			setHealth_max(getHealth_max() + levelExp_Max[i]);
			setMagic_max(getMagic_max() + levelExp_Max[i]);
			setAttack(getAttack() + levelExp_Max[i]/2);
			setDefend(getDefend() + levelExp_Max[i]/4);
			break;
		}
}

void Role::setExpSave(int e) {
	exp = e;
}

int Role::getLevelExp_max(int whichLevel) {
	return levelExp_Max[whichLevel];
}

int Role::getLevel() {
	return level;
}

void Role::setLevel(int l) {
	skillLevel = l - level;			//每次升级带来的技能升级点数
	if(level < l)
		cout << endl<<"恭喜你升到了"<<l<<"级"<<endl;
	for (; skillLevel > 0;) {
		cout << "你当前拥有" << skillLevel << "个技能点数，请选择要加点的技能：" << endl;

		for (int i = 1; i <= 4; i++)
			cout << i << "." << skill.getName(i) << '\t';
		cout << endl;
		int whatSkill;

		while (true) {
			cin >> whatSkill;
			if (whatSkill != 1 && whatSkill != 2 && whatSkill != 3 && whatSkill != 4)
				cout << "选择错误，请重新选择。" << endl;
			else break;
		}

		if (skill.addLevel(whatSkill) == true)
			skillLevel--;
	}
	level = l;
}

void Role::setLevelSave(int l) {
	level = l;
}

int Role::getMoney() {
	return money;
}

void Role::setMoney(int m) {
	money = m;
}

void Role::showRole()
{
	cout << endl;
	cout <<endl<< "当前人物属性:" <<'\t';
	cout << "姓名:" << name << '\t';
	cout << "等级:" << level << endl;
	cout << "气血:" << health << "/" << health_max << '\t';
	cout << "内力:" << magic << "/" << magic_max << endl;
	cout << "攻击:" << attack << '\t';
	cout << "防御:" << defend << '\t';
	cout << "金钱:" << money << endl;
}


Bag Role::getBag() {
	return bag;
}

Skill Role::getSkill() {
	return skill;
}

void Role::showBag() {
	bag.showBags();
}

int Role::getBagWhichGoodsId(int whichGoods) {
	return bag.getWhichGoodsId(whichGoods);

}

int Role::getBagWhichGoodsNum(int whichGoods) {
	return bag.getWhichGoodsNum(whichGoods);

}

void Role::addGoodsToBag(int *goodsId, int *num) {
	cout << endl << "得到了：" << endl;
	
	bag.showGoods(goodsId, num);
	for (int i = 0; goodsId[i] >= 0;i++)
		if (goodsId[i] == 6 || goodsId[i] == 8 || goodsId[i] == 19) {
			task.setGoods(goods[goodsId[i]]);
			task.setIsTaskEnd();
		}
	if (bag.getGoodsNum() > 20) {
		cout << "背包已满，无法添加。" << endl;
	}
	else if (bag.getGoodsNum() + num[0]+num[1]+num[2]+num[3] > 20) {
		cout << "背包剩余空位不足，无法完全添加。" << endl;
		cout << "你仅能添加" << 20 - bag.getGoodsNum() << "件。" << endl;
		cout << "请选择要添加的物品：";
		for (int chioce = 0;num[chioce] == 0 || bag.getGoodsNum() >= 20;) {
			cin >> chioce;
			if (num[chioce] + bag.getGoodsNum() > 20) {
				bag.addGoods(goodsId[chioce], 20 - bag.getGoodsNum());
				cout << "成功添加" << 20 - bag.getGoodsNum() << "件到背包！" << endl << endl;
			}
			else {
				bag.addGoods(goodsId[chioce], num[chioce]);
				cout << "成功添加" << num[chioce] << "件到背包！" << endl << endl;
			}
		}
	}
	else {
		for(int i = 0; goodsId[i] >= 0;i++)
			bag.addGoods(goodsId[i], num[i]);
		cout << "全部成功添加到背包！" << endl << endl;
	}
}



void Role::addGoodsToBag(int goodsId, int num) {
	cout << endl << "得到了：" << endl;

	bag.showGoods(goodsId, num);
	if (bag.getGoodsNum() > 20) {
		cout << "背包已满，无法添加。" << endl;
	}
	else if (bag.getGoodsNum() + num > 20) {
		cout << "背包剩余空位不足，无法完全添加。" << endl;
		cout << "你仅能添加" << 20 - bag.getGoodsNum() << "件。" << endl;
		cout << "请选择要添加的物品：";
		for (int chioce = 0;num == 0 || bag.getGoodsNum() >= 20;) {
			cin >> chioce;
			if (num + bag.getGoodsNum() > 20) {
				bag.addGoods(goodsId, 20 - bag.getGoodsNum());
				cout << "成功添加" << 20 - bag.getGoodsNum() << "件到背包！" << endl << endl;
			}
			else {
				bag.addGoods(goodsId, num);
				cout << "成功添加" << num << "件到背包！" << endl << endl;
			}
		}
	}
	else {
		bag.addGoods(goodsId, num);
		cout << "全部成功添加到背包！" << endl << endl;
	}
}

bool Role::subGoodsToBag(int goodsId, int num) {
	return bag.reduceGoods(goodsId,num);
}

void Role::setBag(Bag bags){
	bag = bags;
}

void Role::savePlayerBag() {
	bag.saveBag();
}

/*
int ** Role::getBagSave()
{
	return bag.getSaveBag();
}
*/

void Role::newBag() {
	 Bag bags;
	 bag = bags;
}

void Role::setSkill(Skill& newSkill) {
	for(int i = 1;i <= 4;i++)
		skill.setLevel(i,newSkill.getLevel(i));
}

void Role::addSaveGoodsToBag(int goodsId,int num) {
	bag.addGoods(goodsId, num);
}

void Role::useDrug() {
	if (bag.isUseDrug()) {
		cout << "是否使用药品：	1.是	2.否" << endl;
		int choice;
		cin >> choice;
		if (choice == 2)
			return;
		if (choice == 1) {
			cout << "请选择要使用的药品：" << endl;
			for (int i = bag.getGoodsNum();i > 0;i--) {
				for (int j = 20;j < 24; j++)
					if (getBagWhichGoodsId(i) == j)
						cout << i << "." << '\t' << goods[getBagWhichGoodsId(i)].getName() << '\t' << getBagWhichGoodsNum(i) << " 件" << endl;
			}
			cout << "0.取消" << endl;
			int choiceGoodsId, choiceGoodsNum;
			while (true) {
				cin >> choiceGoodsId;
				if(choiceGoodsId < 0 || choiceGoodsId > bag.getGoodsNum())
					cout << "选择错误，请重新选择！" << endl;
				else break;
				
			}
				choiceGoodsId = getBagWhichGoodsId(choiceGoodsId);
				cout << "请选择使用多少（输入0取消）：" << endl;
				cin >> choiceGoodsNum;
				subGoodsToBag(choiceGoodsId, choiceGoodsNum);
				cout << "成功使用药品！";
				if (choiceGoodsId == 20 || choiceGoodsId == 21) {
					for (int i = choiceGoodsNum;i > 0;i--)
						setHealth(goods[choiceGoodsId].getAddHP() + getHealth());
					cout << "共恢复" << goods[choiceGoodsId].getAddHP() * choiceGoodsNum << "点气血。" << endl << endl;
				}
				if (choiceGoodsId == 22 || choiceGoodsId == 23) {
					for (int i = choiceGoodsNum;i > 0;i--)
						setHealth(goods[choiceGoodsId].getAddMP() + getMagic());
					cout << "共恢复" << goods[choiceGoodsId].getAddMP() * choiceGoodsNum << "点内力。" << endl << endl;
				}
			if (choiceGoodsId == 0) return;
		}
	}
}

void Role::showEquip()
{
	cout << "当前已装备:" << endl;
	cout << "武器:";
	if (weapon == -1) {
		cout << "无" << endl;
	}
	else {
		cout << goods[weapon].getName() << endl;
	}
	cout << "防具:";
	if (clothes == -1) {
		cout << "无" << endl;
	}
	else {
		cout << goods[clothes].getName() << endl;
	}
}

void Role::wearEquip(int id)
{
	if (goods[id].getType() == 0) {
		if (weapon != -1) {
			removeEquip(weapon);
		}
		setAttack(getAttack() + goods[id].getAddAttack());
		weapon = id;
	}
	else if (goods[id].getType() == 1) {
		if (clothes != -1) {
			removeEquip(clothes);
		}
		setDefend(getDefend() + goods[id].getAddDefend());
		setHealth_max(getHealth_max() + goods[id].getAddMaxHP());
		setMagic_max(getMagic_max() + goods[id].getAddMaxMP());
		clothes = id;
	}
	bag.reduceGoods(id,1);
	cout << "已装备 " << goods[id].getName() << endl;
}

void Role::removeEquip(int id)
{
	if (goods[id].getType() == 0) {
		if (weapon != -1) {
			cout << "当前无武器" << endl;
		}
		setAttack(getAttack() - goods[id].getAddAttack());
		weapon = -1;
	}
	else if (goods[id].getType() == 1) {
		if (clothes != -1) {
			cout << "当前无防具" << endl;
		}
		setDefend(getDefend() - goods[id].getAddDefend());
		setHealth_max(getHealth_max() - goods[id].getAddMaxHP());
		setMagic_max(getMagic_max() - goods[id].getAddMaxMP());
		clothes = -1;
	}
	bag.addGoods(id, 1);
	cout << "已换下 " << goods[id].getName() << endl;
}

int Role::getTaskId()
{
	return task.getTaskId();
}

bool Role::getTaskIsEnd()
{
	return task.getIsEnd();
}

Task Role::getTask() {
	return task;
}

void Role::setTask(Task newTask){
	cout << "获得新任务！" << endl;
	task = newTask;
}

void Role::setTaskIsEnd(){
	task.setIsTaskEnd();
}

string Role::getTaskName()
{
	return task.getName();
}

string Role::getTaskDesc()
{
	return task.getDesc();
}

Goods Role::getTaskGoods()
{
	return task.getGoods();
}

void Role::setTaskGoods(Goods newTaskGoods){
	task.setGoods(newTaskGoods);
}

int Role::getWeapon()
{
	return weapon;
}

void Role::setWeapon(int w)
{
	weapon = w;
}

int Role::getClothes()
{
	return clothes;
}

void Role::setClothes(int c)
{
	clothes = c;
}