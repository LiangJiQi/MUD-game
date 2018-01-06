
#include"Task.h"

Task::Task(int id):goods(24) {
	isEnd = false;
	if (id == 1) {
		taskId = 1;
		name = "获得猛兽魂";
		desc = "猛兽混是剑刃上有形似野兽牙齿的倒刺，可以用来出其不意地夺取敌人武器的灵魂，它在东郊被雕文魔像守护。";
	}
	else if (id == 2) {
		taskId = 2;
		name = "获得大夏龙雀";
		desc = "大夏龙雀是制作极精巧，刀背雕饰着龙雀装饰的环首刀，世所罕见的珍品。它在地宫被石甲虫守护。";
	}
	else if (id == 3) {
		taskId = 3;
		name = "获得紫龙天罡铠";
		desc = "紫龙天罡铠是传说是由龙气化作紫色鳞片镶嵌而成的战甲，从头到脚绵密包裹。它在十里坡被炼狱巨龙守护。";
	}
}

Task::~Task() {

}

int Task::getTaskId() {
	return taskId;
}

string Task::getName() {
	return name;
}

string Task::getDesc() {
	return desc;
}

Goods Task::getGoods() {
	return goods;
}

void Task::setGoods(Goods newGoods){
	goods = newGoods;
}

bool Task::getIsEnd() {
	return isEnd;
}

void Task::setIsTaskEnd() {
	isEnd = true;
}