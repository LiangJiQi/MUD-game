#pragma once
#ifndef TASK_H
#define TASK_H
#include"Goods.h"
#include<string>

class Task {
public:
	Task(int id);
	~Task();

	int getTaskId();
	string getName();
	string getDesc();
	bool getIsEnd();
	Goods getGoods();
	void setGoods(Goods newGoods);
	void setIsTaskEnd();

private:
	int taskId;		//任务ID
	string name;	//任务名称
	string desc;	//任务描述
	bool isEnd;		//任务完成标记
	Goods goods;	//任务完成所需的物品,初始化为空的


};




#endif