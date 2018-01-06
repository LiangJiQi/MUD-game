#ifndef SKILL_H
#define SKILL_H

#include <string>
//#include "Role.h"
#include "Enemy.h"

class Skill {
public:
	Skill();
	~Skill() {};
	int getLevel(int whatSkill);		//判断技能等级（是否为零尚未习得）对应伤害
	bool addLevel(int whatSkill);	    //增加技能等级，每次一级
	void setLevel(int whatSkill,int l);		//设置技能等级

	int getLevel_Max(int whatSkill);	//得到技能的最高等级
	string getName(int whatSkill);		//得到技能名字
	string getDisc(int whatSkill);		//得到技能描述
	int getType(int whatSkill);			//得到技能类型
	int getNeedMP(int whatSkill);		//得到技能耗蓝
	double getAddAttack(int whatSkill);	//得到技能的攻击力加强
	int getRecoverHp(int whatSkill);	//得到技能恢复的生命值
	int getDebuff(int whatSkill);

	//void showRoleSkill();		//显示角色的所有技能

	//void enemyUseSkill(int whatSkill);		//怪物使用技能
	//void RoleUseSkill(int whatSkill);		//角色使用技能

protected:

	/*
	char disc[140];
	int skillLevel;
	int type;	//1,物理 2,法术 3,物法皆有
	int needMp;
	double addAttack;
	int recoverHp;
	int debuffSkill;
	*/

	string skill_1Name;
	string skill_2Name;
	string skill_3Name;
	string skill_4Name;

	string skill_1Disc;
	string skill_2Disc;
	string skill_3Disc;
	string skill_4Disc;

	int skillLevel_1;			//在基类构造函数里初始化
	int skillLevel_2;
	int skillLevel_3;
	int skillLevel_4;

	int skillLevel_Max_1;		//每个技能的最高等级
	int skillLevel_Max_2;		//在基类构造函数里初始化
	int skillLevel_Max_3;
	int skillLevel_Max_4;

	int skill_1Type;
	int skill_2Type;
	int skill_3Type;
	int skill_4Type;

	int skill_1NeedMp;
	int skill_2NeedMp;
	int skill_3NeedMp;
	int skill_4NeedMp;

	double skill_1AddAttack;
	double skill_2AddAttack;
	double skill_3AddAttack;
	double skill_4AddAttack;

	int skill_1recoverHp;
	int skill_2recoverHp;
	int skill_3recoverHp;
	int skill_4recoverHp;

	int skill_1debuffSkill;
	int skill_2debuffSkill;
	int skill_3debuffSkill;
	int skill_4debuffSkill;

};

//角色一的技能
class Role_1Skill :public Skill {
public:
	Role_1Skill();

private:

};


class Role_2Skill :public Skill {
public:
	Role_2Skill();
private:

};


class Role_3Skill :public Skill {
public:
	Role_3Skill();
private:
};

#endif