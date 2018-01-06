#include <iostream>
#include <string>
#include <vector>
#include<iomanip>
#include "Store.h"

using namespace std;

Store::Store()
{
	for (int i = 0; i < 24; ++i)
	{
		stores.insert(pair<int, int>(i, 999));//商店物品初始化 数量为999
	}
	
}

Store::~Store()
{
}

void Store::showStores()
{
	cout <<left<<setw(17)<< "物品ID" <<setw(76)<< "描述" << "价格" << endl;
	map<int, int>::iterator iter;
	int i = 0;//物品序号
	for (iter = stores.begin(); iter != stores.end(); ++iter)
	{
		cout <<left<<setw(2) <<i << "." <<setw(10)<< goods[iter->first].getName() << "   "
			<<setw(76)<< goods[iter->first].getDesc() << "   "
			<< goods[iter->first].getPriceBuy() << endl;

		++i;//物品序号
	}
}

Role Store::storeToPlayer(Role player)
{
	int goodsId, goodsNum;
	cout << "24.退出" << endl;
	cout << "请输入要购买的物品ID号" << endl;
	cin >> goodsId;
	if (goodsId == 24) return player;
	cout << "请输入要购买的数量(输入0退出)" << endl;
	cin >> goodsNum;
	if (goodsNum == 0) return player;
	int totalPrice = int(goods[goodsId].getPriceBuy()) * int(goodsNum);
	if (player.getMoney() >= totalPrice)
	{
		player.addGoodsToBag(goodsId, goodsNum);
		player.setMoney(player.getMoney() - totalPrice);
		cout << "购买成功" << endl;
		cout << "获得 " << goods[goodsId].getName() << " * " << goodsNum;
	}
	else
	{
		cout << "金钱不足,购买失败" << endl;
	}
	return player;
}

Role Store::playerToStore(Role player)
{
	int goodsId, goodsNum;
	cout << "请输入要卖出的物品ID(输入24退出)" << endl;
	cin >> goodsId;
	if (goodsId == 24) return player;
	cout << "请输入要卖出的数量(输入0退出)" << endl;
	cin >> goodsNum;
	if (goodsNum == 0) return player;
	if (player.subGoodsToBag(goodsId, goodsNum)) {
		int totalPrice = int(goods[goodsId].getPriceSell()) * int(goodsNum);

		player.setMoney(player.getMoney() + totalPrice);
		cout << "出售成功" << endl;
		cout << "获得金钱:" << totalPrice << endl;
	}
	else {
		cout << "无此物品，出售失败！" << endl;
	}
	return player;
}
