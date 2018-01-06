#include <iostream>
#include "Map.h"


using namespace std;

Map::Map():npc(0){
	position = 0;
	dx = 5;
	dy = 2;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy] = '*';
}

Map::Map(int p) :npc(p) {
	position = p;
	/*
	switch (p)			//我跳不进
	{
	case'0': {
		dx = 5;
		dy = 2;
		break;
	}
	case'1': {
		dx = 4;
		dy = 2;
		break;
	}
	case'2':{
		dx = 3;
		dy = 2;
		break;
	}
	case'3': {
		dx = 3;
		dy = 1;
		break;
	}
	case'4': {
		dx = 2;
		dy = 1;
		break;
	}
	case'5': {
		dx = 2;
		dy = 0;
		break;
	}
	case'6': {
		dx = 3;
		dy = 3;
		break;
	}
	case'7': {
		dx = 2;
		dy = 3;
		break;
	}
	case'8': {
		dx = 1;
		dy = 3;
		break;
	}
	case'9': {
		dx = 0;
		dy = 3;
		break;
	}
	default:
		break;
	}
	*/
	if (p == 0) {
		dx = 5;
		dy = 2;
	}
	if (p == 1) {
		dx = 4;
		dy = 2;
	}
	if (p == 2) {
		dx = 3;
		dy = 2;
	}
	if (p == 3) {
		dx = 3;
		dy = 1;
	}
	if (p == 4) {
		dx = 2;
		dy = 1;
	}
	if (p == 5) {
		dx = 2;
		dy = 0;
	}
	if (p == 6) {
		dx = 3;
		dy = 3;
	}
	if (p == 7) {
		dx = 2;
		dy = 3;
	}
	if (p == 8) {
		dx = 1;
		dy = 3;
	}
	if (p == 9) {
		dx = 0;
		dy = 3;
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy] = '*';
}

Map::~Map()
{
}

void Map::Store()
{
}


void Map::ShowMap()
{
	system("cls");
	cout << "世界地图:" << endl;
	cout<<"                                  __________"<<endl;
	cout<<"                                 |          |"<<endl;
	//cout<<"                                 |          |"<<endl;
	cout<<"                                 |   昆仑   |"<<endl;
	cout<<"                                 |    "<<pos[0][3]<<"     |"<<endl;
	//cout<<"                                 |          |"<<endl;
	cout<<"                                 |__________|"<<endl;
	cout<<"                                 |          |"<<endl;
	//cout<<"                                 |          |"<<endl;
	cout<<"                                 |  十里坡  |"<<endl;
	cout<<"                                 |    "<<pos[1][3]<<"     |"<<endl;
	//cout<<"                                 |          |"<<endl;
	cout<<"___________ __________           |__________|"<<endl;
	cout<<"|          |          |          |          |"<<endl;
	//cout<<"|          |          |          |          |"<<endl;
	cout<<"|   地宫   |  五龙山  |          |  轩辕庙  |"<<endl;
	cout<<"|    "<< pos[2][0] <<"     |    "<< pos[2][1] <<"     |          |    "<< pos[2][3] <<"     |"<<endl;
	//cout<<"|          |          |          |          |"<<endl;
	cout<<"|__________|__________|__________|__________|"<<endl;
	cout<<"           |          |          |          |"<<endl;
	//cout<<"           |          |          |          |"<<endl;
	cout<<"           |   西郊   |  岳州城  |   东郊   |"<<endl;
	cout<<"           |     "<< pos[3][1] <<"    |    "<< pos[3][2] <<"     |    "<< pos[3][3] <<"     |"<<endl;
	//cout<<"           |          |          |          |"<<endl;
	cout<<"           |__________|__________|__________|"<<endl;
	cout<<"                      |          |"<<endl;
	//cout<<"                      |          |"<<endl;
	cout<<"                      |   官道   |"<<endl;
	cout<<"                      |    "<< pos[4][2] <<"     |"<<endl;
	//cout<<"                      |          |"<<endl;
	cout<<"                      |__________|"<<endl;
	cout<<"                      |          |"<<endl;
	//cout<<"                      |          |"<<endl;
	cout<<"                      |  平江镇  |"<<endl;
	cout<<"                      |    "<< pos[5][2] <<"     |"<<endl;
	//cout<<"                      |          |"<<endl;
	cout<<"                      |__________|"<<endl;
	cout << "您现在的位置为" << mapName[position] << endl;
}


void Map::showRoom() {
	if (isThereChat()) 
		cout << "这里有：" << '\t'<<npc.getName() << '\t';
}

void Map::Move(char order)
{
	pos[dx][dy] = ' ';
	switch (order)
	{
		case 'w': {
			if (position == 0 || position == 1 || position == 3 || position == 6 || position == 7 || position == 8) {
				dx--;
				position++;
			}
			else
			{
				cout << "移动失败" << endl;
			}
			break;
		}
		case 'a': {
			if (position == 2 || position == 4 ) {
				dy--;
				position++;
			}
			else if (position == 6)
			{
				dy--;
				position = 2;
			}
			else
			{
				cout << "移动失败" << endl;
			}
			break;
		}
		case 's': {
			if (position == 1 || position == 2 || position == 4 || position == 7 || position == 8 || position == 9) {
				dx++;
				position--;
			}
			else
			{
				cout << "移动失败" << endl;
			}
			break;
		}
		case 'd': {
			if (position == 3 || position == 5 ){
				dy++;
				position--;
			}
			else if (position == 2)
			{
				dy++;
				position = 6;
			}
			else
			{
				cout << "移动失败" << endl;
			}
			break;
		}
		default:
			break;
	}
	pos[dx][dy] = '*';
	npc = Npc(position);		//更新npc
	showRoom();
}

bool Map::isThereChat()
{
	if (position == 0 || position == 2 || position == 4 || position == 5 || position == 7 || position == 9)
		return true;
	else return false;
}

bool Map::isThereFight()
{
	if (position == 1 || position == 3 || position == 4 || position == 5 || position == 6 || position == 7 || position == 8 || position == 9)
		return true;
	else return false;
}

int Map::getPosition()
{
	return position;
}

string Map::getNpcName(){
	return npc.getName();
}

void Map::setNpc(Npc newNpc) {
	npc = newNpc;
}

Role Map::chatToNpc(Role player){
	return npc.chat(player);
}

int Map::getNpcGoodsId(){
	return npc.getGoodsId();
}

int Map::getNpcGoodsNum(){
	return npc.getGoodsNum();
}

string Map::getName()
{
	return mapName[position];
}
