#include <iostream>
#include "Skill.h"

using namespace std;

Skill::Skill() {

	skillLevel_1 = 0;
	skillLevel_2 = 0;
	skillLevel_3 = 0;
	skillLevel_4 = 0;

	skillLevel_Max_1 = 7;		//每个技能的最高等级,待定
	skillLevel_Max_2 = 7;
	skillLevel_Max_3 = 7;
	skillLevel_Max_4 = 6;

}
int Skill::getLevel(int whatSkill) {
	/*
	switch (whatSkill) {
	case '1':return skillLevel_1; break;
	case '2':return skillLevel_2; break;
	case '3':return skillLevel_3; break;
	case '4':return skillLevel_4; break;
	default: return 0;
	}
	*/
	if (whatSkill == 1)
		return skillLevel_1;
	if (whatSkill == 2)
		return skillLevel_2;
	if (whatSkill == 3)
		return skillLevel_3;
	if (whatSkill == 4)
		return skillLevel_4;

}

int Skill::getLevel_Max(int whatSkill) {
	/*
	switch (whatSkill) {
	case '1':return skillLevel_Max_1; break;
	case '2':return skillLevel_Max_2; break;
	case '3':return skillLevel_Max_3; break;
	case '4':return skillLevel_Max_4; break;
	default:return 0;
	}
	*/
	if (whatSkill == 1)
		return skillLevel_Max_1;
	if (whatSkill == 2)
		return skillLevel_Max_2;
	if (whatSkill == 3)
		return skillLevel_Max_3;
	if (whatSkill == 4)
		return skillLevel_Max_4;
}

string Skill::getName(int whatSkill) {
	/*
	switch (whatSkill) {		//这种方法不行，程序崩溃。
	case '1':return skill_1Name;
	case '2':return skill_2Name; 
	case '3':return skill_3Name;
	case '4':return skill_4Name; 
	default:return NULL;
	}
	*/
	if(whatSkill == 1)
		return skill_1Name;
	if (whatSkill == 2)
		return skill_2Name;
	if (whatSkill == 3)
		return skill_3Name;
	if (whatSkill == 4)
		return skill_4Name;

}

string Skill::getDisc(int whatSkill) {
	/*
	switch (whatSkill) {
	case '1':return skill_1Disc; break;
	case '2':return skill_2Disc; break;
	case '3':return skill_3Disc; break;
	case '4':return skill_4Disc; break;
	default:return 0;
	}
	*/
	if (whatSkill == 1)
		return skill_1Disc;
	if (whatSkill == 2)
		return skill_2Disc;
	if (whatSkill == 3)
		return skill_3Disc;
	if (whatSkill == 4)
		return skill_4Disc;
}

int Skill::getType(int whatSkill) {
	/*
	switch (whatSkill) {
	case '1':return skill_1Type; break;
	case '2':return skill_2Type; break;
	case '3':return skill_3Type; break;
	case '4':return skill_4Type; break;
	default:return 0;
	}
	*/
	if (whatSkill == 1)
		return skill_1Type;
	if (whatSkill == 2)
		return skill_2Type;
	if (whatSkill == 3)
		return skill_3Type;
	if (whatSkill == 4)
		return skill_4Type;
}

int Skill::getNeedMP(int whatSkill) {
	/*
	switch (whatSkill) {
	case '1':return skill_1NeedMp; break;
	case '2':return skill_2NeedMp; break;
	case '3':return skill_3NeedMp; break;
	case '4':return skill_4NeedMp; break;
	default:return 0;
	}
	*/
	if (whatSkill == 1)
		return skill_1NeedMp;
	if (whatSkill == 2)
		return skill_2NeedMp;
	if (whatSkill == 3)
		return skill_3NeedMp;
	if (whatSkill == 4)
		return skill_4NeedMp;
}

double Skill::getAddAttack(int whatSkill) {
	/*
	switch (whatSkill) {
	case '1':return skill_1AddAttack; break;
	case '2':return skill_2AddAttack; break;
	case '3':return skill_3AddAttack; break;
	case '4':return skill_4AddAttack; break;
	default:return 0;
	}
	*/
	if (whatSkill == 1)
		return skill_1AddAttack;
	if (whatSkill == 2)
		return skill_2AddAttack;
	if (whatSkill == 3)
		return skill_3AddAttack;
	if (whatSkill == 4)
		return skill_4AddAttack;
}

int Skill::getRecoverHp(int whatSkill) {
	/*
	switch (whatSkill) {
	case '1':return skill_1recoverHp; break;
	case '2':return skill_2recoverHp; break;
	case '3':return skill_3recoverHp; break;
	case '4':return skill_4recoverHp; break;
	default:return 0;
	}
	*/
	if (whatSkill == 1)
		return skill_1recoverHp;
	if (whatSkill == 2)
		return skill_2recoverHp;
	if (whatSkill == 3)
		return skill_3recoverHp;
	if (whatSkill == 4)
		return skill_4recoverHp;
}
int Skill::getDebuff(int whatSkill) {
	/*
	switch (whatSkill) {
	case '1':return skill_1debuffSkill; break;
	case '2':return skill_2debuffSkill; break;
	case '3':return skill_3debuffSkill; break;
	case '4':return skill_4debuffSkill; break;
	default:return 0;
	}
	*/
	if (whatSkill == 1)
		return skill_1debuffSkill;
	if (whatSkill == 2)
		return skill_2debuffSkill;
	if (whatSkill == 3)
		return skill_3debuffSkill;
	if (whatSkill == 4)
		return skill_4debuffSkill;
}
bool Skill::addLevel(int whatSkill) {
	if (getLevel(whatSkill) >= getLevel_Max(whatSkill)) {
		cout << "技能等级已满，无法加点。"<<endl;
		return false;
	}
	else {
		if (whatSkill == 1)
			skillLevel_1++;
		if (whatSkill == 2)
			skillLevel_2++;
		if (whatSkill == 3)
			skillLevel_3++;
		if (whatSkill == 4)
			skillLevel_4++;
		cout << "成功添加一点！" << endl;
		return true;
	}
}
void Skill::setLevel(int whatSkill,int l){
	if (whatSkill == 1)
		skillLevel_1 = l;
	if (whatSkill == 2)
		skillLevel_2 = l;
	if (whatSkill == 3)
		skillLevel_3 = l;
	if (whatSkill == 4)
		skillLevel_4 = l;
}
/*for(int i = 1;i <= 4;i++)
cout<<i<<"."<<getName(i)<<'\t';
cout<<endl;
*/

Role_1Skill::Role_1Skill() {
	skill_1Name = "基本枪棍";
	skill_2Name = "独孤九剑";
	skill_3Name = "疯魔杖法";
	skill_4Name = "四象掌";
	skill_1Disc = "长兵器的入门功夫，虽然普通，也能让你更强壮";
	skill_2Disc = "这大概是最厉害的剑法了，习得此剑，当可独步天下";
	skill_3Disc = "少林疯僧自创的杖法，能显著提升身法";
	skill_4Disc = "峨嵋入门掌法。提升内力的效果明显";

	

	skill_1Type = 1;
	skill_2Type = 1;
	skill_3Type = 2;
	skill_4Type = 3;

	skill_1NeedMp = 5;
	skill_2NeedMp = 10;
	skill_3NeedMp = 15;
	skill_4NeedMp = 25;

	skill_1AddAttack = 0.1;
	skill_2AddAttack = 0.3;
	skill_3AddAttack = 0;
	skill_4AddAttack = 0.5;

	skill_1recoverHp = 10;
	skill_2recoverHp = 15;
	skill_3recoverHp = 0;
	skill_4recoverHp = 20;

	skill_1debuffSkill = 0;
	skill_2debuffSkill = 0;
	skill_3debuffSkill = 15;
	skill_4debuffSkill = 20;
}

//角色二的技能,待设计
Role_2Skill::Role_2Skill() {

	skill_1Name = "基本枪棍";
	skill_2Name = "独孤九剑";
	skill_3Name = "疯魔杖法";
	skill_4Name = "四象掌";

	skill_1Disc = "长兵器的入门功夫，虽然普通，也能让你更强壮。";
	skill_2Disc = "这大概是最厉害的剑法了，习得此剑，当可独步天下。";
	skill_3Disc = "少林疯僧自创的杖法，能显著提升身法。";
	skill_4Disc = "峨嵋入门掌法。提升内力的效果明显。";

	skill_1Type = 1;
	skill_2Type = 1;
	skill_3Type = 2;
	skill_4Type = 3;

	skill_1NeedMp = 5;
	skill_2NeedMp = 10;
	skill_3NeedMp = 15;
	skill_4NeedMp = 25;

	skill_1AddAttack = 0.1;
	skill_2AddAttack = 0.15;
	skill_3AddAttack = 0.0;
	skill_4AddAttack = 0.5;

	skill_1recoverHp = 10;
	skill_2recoverHp = 15;
	skill_3recoverHp = 0;
	skill_4recoverHp = 20;

	skill_1debuffSkill = 0;
	skill_2debuffSkill = 0;
	skill_3debuffSkill = 15;
	skill_4debuffSkill = 20;
}

//角色三的技能，待设计
Role_3Skill::Role_3Skill() {

	skill_1Name = "基本枪棍";
	skill_2Name = "独孤九剑";
	skill_3Name = "疯魔杖法";
	skill_4Name = "四象掌";

	skill_1Disc = "长兵器的入门功夫，虽然普通，也能让你更强壮。";
	skill_2Disc = "这大概是最厉害的剑法了，习得此剑，当可独步天下。";
	skill_3Disc = "少林疯僧自创的杖法，能显著提升身法。";
	skill_4Disc = "峨嵋入门掌法。提升内力的效果明显。";

	skill_1Type = 1;
	skill_2Type = 1;
	skill_3Type = 2;
	skill_4Type = 3;

	skill_1NeedMp = 5;
	skill_2NeedMp = 10;
	skill_3NeedMp = 15;
	skill_4NeedMp = 25;

	skill_1AddAttack = 0.1;
	skill_2AddAttack = 0.15;
	skill_3AddAttack = 0;
	skill_4AddAttack = 0.5;

	skill_1recoverHp = 10;
	skill_2recoverHp = 15;
	skill_3recoverHp = 0;
	skill_4recoverHp = 20;

	skill_1debuffSkill = 0;
	skill_2debuffSkill = 0;
	skill_3debuffSkill = 15;
	skill_4debuffSkill = 20;
}