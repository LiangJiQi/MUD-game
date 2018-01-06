#include <iostream>
#include<fstream>
#include <Windows.h>
#include "Bag.h"
#include "Enemy.h"
#include "Fight.h"
#include "Goods.h"
#include "Map.h"
#include "Npc.h"
#include "Role.h"
#include "Skill.h"
#include "Store.h"
#include"Save.h"
#include"Task.h"

using namespace std;

//强制界面全屏
/*
void FullScreen() {
	HWND hwnd = GetForegroundWindow();
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);
	char setting[30];
	sprintf_s(setting, "mode con:cols=%d lines=%d", x, y);
	system(setting);
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, x, y, NULL);
	MoveWindow(hwnd, 0, 0, x, y, 1);
	printf("\n\n");
}
*/

//欢迎界面
int welcomePage()
{
	HANDLE hConsole;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY| FOREGROUND_RED);
	/*
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);
	*/
	for(int i = 0;i < 8;i++)
		cout << endl;
	cout  <<'\t' << '\t' << '\t' << '\t' << "    0   0           0          0           " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "    0   0            0         0 0  000    " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "    000000000  000000000000    0 0         " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   0    0      0    0     0   0  0 00000   " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "  00  0 0  0   0   0  0   0  0  0    0     " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "0      00 0       0 0  0       00    0     " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   0 00000000   0    0       0  0    0     " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   0    00         0   0        0    0     " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   0   0  0      0 00000 0      0    0     " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   0  0    0   0   0   0  0     0  0 0     " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   0 0      0      00000        0   00     " << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	string newGameMenu = "   1.新的游戏  2.读取存档  3.退出游戏";
	cout << '\t' << '\t' << '\t' << '\t' ;
	cout << '\t' << "   ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "       游戏制作信息" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "   ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   制作人：中国海洋大学2017夏季学期c++课程设计16组" << endl;
	cout << '\t' << '\t' << '\t' << '\t' <<"   梁同学、张同学与孟同学" << endl<<endl;
	cout << '\t' << '\t' << '\t' << '\t';
	for (int i = 0;i < newGameMenu.length();i++) {
		Sleep(50);
		cout << newGameMenu[i];
	}
	cout << endl << endl << '\t' << '\t' << '\t' << '\t'<<"   ";
	return 0;
}

//显示游戏背景
int backgroundGame()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "故事背景" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	string background = "    鸿蒙开化之初，中州大陆昆仑之巅的鸿钧上人创立道教，并收徒三人，各授以道门绝技，三徒皆修成混元大罗金仙万劫不坏之体，分别发展出道教的人道、阐教和截教三个分支。此三徒正是人道教主太上老君、阐教教主元始天尊和截教的通天教主。";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "    三教主秉承师父鸿钧上人教诲，广收门徒将道教流传于世。只因入道门中即可修仙，使人跳出三界之外，不在五行之中，免除生死轮回之苦，使得入道修行之人多不胜数！但修仙之道并非苦心修炼便可达成。修行路上，均要经历三百年一小劫，一千五百年一大劫的劫数。修行之人均无法避开劫数，只能根据自身道行的深浅去经历劫数。";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "    值商周两朝交替之时，恰逢修仙一千五百年仙劫，于是三教主共议封神榜，以观众仙道行浅深。然劫数难逃，封神一役，致使道门内部阐教和截教不和，修仙众人俱遭屠戮，更引来西方教派参与纷争，后因鸿钧上人亲自出面调停，终得以平息。";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "    五百年后的中洲大陆，故事就发生在一个平凡冷清的小镇上。";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");


	return 0;
}

//游戏运行函数
void newGame(Role player,Map map) {

	Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
	Store store;
	int chatNum = 0;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
menu:
	Sleep(2000);
	system("cls");
	cout <<endl<< "位于 :" << map.getName() << endl;
	map.showRoom();
	if (map.isThereFight()) {
		Enemy_Boss  boss(map.getPosition());
		
		if(map.isThereChat() == false)
			cout << "这里有：" << '\t' ;
		cout << boss.getName() <<'\t'<<"三头小野怪"<< endl;
	}
	player.showRole();											//显示人物信息
	cout << endl << "1.交谈 2.战斗 3.移动 4.状态 5.商店 6.退出 7.保存并退出" << endl;
	int choice;
	while (true) {
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
			cout << "选择错误，请重新选择。" << endl;
		else break;
	}
	if (choice == 1) {
		if (map.isThereChat()) {
			//交谈
			Npc npc(map.getPosition());
			map.setNpc(npc);
			cout << endl << "可以对话的人物:" << endl ;
			cout << map.getNpcName() << endl;
			player = map.chatToNpc(player);
		}
	}
	else if (choice == 2) {
		if (map.isThereFight()) {
			Enemy_Boss  boss(map.getPosition());
			Enemy_Small smallEnemy;
			boss.showEnemy();
			Fight fight(player, boss);
			system("cls");
			cout << "正在进入战斗......." << endl;
			while (!fight.isFightEnd()) {
				Sleep(3000);
				system("cls");
				if (fight.fightRound() == true) {
					player = fight.runEndFight();
					goto menu;
				}
			}
			player = fight.endFight();		//战斗正常结束，获得增益
			smallEnemy.~Enemy_Small();
		}
		else
		{
			cout << "这里没有战斗可以发生" << endl;
		}
	}
	else if (choice == 3) {
		while (true)
		{
			map.ShowMap();
			cout << "使用w a s d来移动 按1进入地图" << endl;
			char order;
			cin >> order;
			if (order == '1') {
				system("cls");
				break;
			}
			else {
				map.Move(order);
				chatNum = 0;
				player.setMapId(map.getPosition());
			}

		}

	}
	else if (choice == 4) {
		cout << "1.属性 2.背包 3.技能 4.装备 5.任务 6.返回" << endl;
		int choice;
		while (true) {
			cin >> choice;
			if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
				cout << "选择错误，请重新选择。" << endl;
			else break;
		}
		if (choice == 2) {
			player.showBag();		//显示背包
			player.useDrug();		//是否使用药品
		}

		else if (choice == 3) player.showSkill();//显示技能
		else if (choice == 4) {
			player.showEquip();
			cout << "1.更换装备		2.取下装备		3.退出" << endl;
			int choiceEquip;
			cin >> choiceEquip;
			if (choiceEquip == 1) {
				player.showBag();
				cout << "请选择要换上的装备(24.取消)" << endl;
				int id;
				cin >> id;
				if (id >= 24 || id < 0)
					goto menu;
				player.wearEquip(id);
				player.getBag().reduceGoods(id, 1);
			}
			if (choiceEquip == 2) {
				cout << "请输入要换下的装备" << endl;
				cout << "1." << goods[player.getWeapon()].getName() << endl;
				cout << "2." << goods[player.getClothes()].getName() << endl;
				int choice;
				cin >> choice;
				if (choice == 1)
				{
					player.removeEquip(player.getWeapon());
					player.getBag().addGoods(player.getWeapon(), 1);
				}
				if (choice == 2)
				{
					player.removeEquip(player.getClothes());
					player.getBag().addGoods(player.getClothes(), 1);
				}
			}
			if (choiceEquip == 3)
				goto menu;
		}
		else if (choice == 5) {
			cout << "任务" << player.getTaskId() << '\t' << player.getTaskName() << '\t' << player.getTaskDesc() << endl << endl;
		}
		else if (choice == 6) goto menu;
		else if (choice == 1)		//这里跳转到menu开头那里显示人物信息
			cout << "以上就为人物属性。" << endl;
	}
	else if (choice == 5) {
		cout << "1.购买物品		2.售出物品		3.退出" << endl;
		int choiceStore;
		cin >> choiceStore;
		if (choiceStore == 1) {
			store.showStores();
			player = store.storeToPlayer(player);
		}
		if (choiceStore == 2) {
			player.showBag();
			player = store.playerToStore(player);

		}
		if (choiceStore == 3)
			goto menu;
	}

	else if (choice == 6) {
		cout << "成功退出！" << endl;
		exit(0);
	}
		
	else if (choice == 7) {
		Save::setToFile(player);
		exit(0);
	}
	goto menu;

}

//读取游戏
void readFile() {
	ifstream fileRole("SaveRole.dat", ios_base::in | ios_base::binary);
	ifstream fileBag("SaveBag.dat", ios_base::in | ios_base::binary);
	ifstream fileSkill("SaveSkill.dat");
	ifstream fileTask("SaveTask.dat");
	if (!fileRole) {
		cout << "没有保存的游戏！" << endl;
		cout << "请重新选择:" << endl;
	}
	else {
		string name;
		int type, health_max, health, magic_max, magic, attack, exp, level, defend, money, mapId, story, weapon, clothes;
		fileRole >> name >> type >> health_max >> health >> magic >> magic_max >> attack >> exp >> level >> defend >> money >> mapId >> story >> weapon >> clothes;

		Role player(type);
		player.setHealth_max(health_max);
		player.setHealth(health);
		player.setMagic_max(magic_max);
		player.setMagic(magic);
		player.setAttack(attack);
		player.setExpSave(exp);
		player.setLevelSave(level);
		player.setDefend(defend);
		player.setMoney(money);
		player.setMapId(mapId);
		player.setStory(story);
		player.setWeapon(weapon);
		player.setClothes(clothes);

		Skill skill;
		fileSkill.read(reinterpret_cast<char *>(&skill), sizeof(Skill));
		Skill &newSkill = skill;
		player.setSkill(newSkill);

		Task task(0);
		fileTask.read(reinterpret_cast<char *>(&task), sizeof(Task));
		player.setTask(task);


		for (int key2 = 24;!fileBag.eof();) {
			
			int key;
			int value;
			fileBag >> key >> value;
			if (key2 == key)
				break;
			player.addSaveGoodsToBag(key, value);
			key2 = key;

		}
		fileRole.close();
		fileBag.close();
		fileSkill.close();
		Map newMap(player.getMapId());

		cout << "读入成功！" << endl;
		newGame(player,newMap);
	}
}

//程序入口
int main(){
	//FullScreen();
	welcomePage();
	int choice;
	while (true) {
		cin >> choice;;
		if (choice != 1 && choice != 2 && choice != 3)
				cout << "选择错误，请重新选择。" << endl;
			else break;
	}
		if (choice == 3)
			exit(0);
		//人物创建
		if (choice == 1) {
			backgroundGame();
			int choiceRole;
			cout << "职业简介: " << endl <<
				"1.人道" << endl << "认为“道”是宇宙万物的本原和主宰，无所不在，无所不包，万物都是从“道”演化而来的。" << endl <<
				"2.阐教" << endl << "阐者，明也。阐教主张崇尚自然，提倡道法自然，无所不容，自然无为，与自然和谐相处。" << endl <<
				"3.截教" << endl << "主张上道无德，下道唯德。大道五十衍四十九为定数，一线生机遁去，截教的教义正是截取这一线生机，演变六道。" << endl;
			cout << endl << "请输入要创建的职业" << endl;
			
			while (true) {
				cin >> choiceRole;
				if (choiceRole != 1 && choiceRole != 2 && choiceRole != 3 )
					cout << "选择错误，请重新选择。" << endl;
				else break;
			}
			Role player(choiceRole);
			system("cls");
			cout << "创建成功" << endl;
			Map map;
			newGame(player,map);
		}
		if (choice == 2) {
			readFile();
	}
	return 0;
}



