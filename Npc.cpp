
#include"Npc.h"
#include<iostream>
using namespace std;


/*
string Npc::getName(int whichNpc) {
	return name[whichNpc];
}
*/

Npc::Npc(int num){
	type = num;
	switch (num)
	{
	case 0: {
		name = "雪蝶";
		goodId = 20;
		goodNum = 5;
		money = 20;
		break;
	}
	case 2: {
		name = "云中子";
		goodId = 1;
		goodNum = 1;
		money = 50;
		break;
	}
	case 4: {
		name = "广法天尊";
		goodId = 12;
		goodNum = 1;
		money = 100;
		break;
	}
	case 5: {
		name = "接引道人";
		goodId = 21;
		goodNum = 50;
		money = 200;
		break;
	}
	case 7: {
		name = "玉鼎真人";
		goodId = 7;
		goodNum = 1;
		money = 2000;
		break;
	}
	case 9: {
		name = "元始天尊";
		goodId = 9;
		goodNum = 1;
		money = 0;
		break;
	}

	default:
		break;
	}
}

Npc::~Npc(){}

string Npc::getName() {
	return name;
}

Role Npc::chat(Role player) {
	switch (type)
	{
	case 0: {
		if (player.getStory() == 0) {
			cout << "雪蝶: 最近镇上不太安宁啊" << endl;
			system("pause");
			cout << "你: 怎么了, 出什么事情了" << endl;
			system("pause");
			cout << "雪蝶: 最近镇子北面的官道突然出现很多以前没有的野物, 厉害得很, 有些猎户都不是他们的对手, 让镇上的居民人心惶惶" << endl;
			system("pause");
			cout << "你: 这些野物这么猖狂? 让我会会它们, 顺便去岳州城里打探一下消息" << endl;
			system("pause");
			cout << "雪蝶: 那你一定要小心啊, 这些金疮药你拿着, 防备野物的伤害" << endl;
			system("pause");
			player.setStory(player.getStory() + 1);
			player.addGoodsToBag(getGoodsId(), getGoodsNum());
			cout << endl << "获得物品:" << goods[getGoodsId()].getName() << " * " << getGoodsNum() << endl << endl;

		}
		else cout << "已经交谈过了。" << endl << endl;
		break;
	}
	case 2: {
		if (player.getStory() == 1) {
			cout << "云中子：你听说雪蝶被杀害了吗？" << endl;
			system("pause");
			cout << "你: 真的吗？我前些天还见过他，怎么回事？" << endl;
			system("pause");
			cout << "云中子: 不太清楚，据说是被一只千年树怪偷袭，最后连尸体都找不到。" << endl;
			system("pause");
			cout << "你: 真是可恨，雪蝶帮助过我，我一定要找回雪蝶的尸体！" << endl;
			system("pause");
			cout << "云中子:少侠够豪爽，这里有一把雪蝶遗留下的精钢剑，拿去防身，一路多多保重！我听说广法天尊正在五龙山游历，你可以先去问问他,不过你要拿到猛兽魂才能见到他。" << endl;
			system("pause");
			player.setStory(player.getStory() + 1);
			player.addGoodsToBag(getGoodsId(), getGoodsNum());
			cout << endl << "获得物品:" << goods[getGoodsId()].getName() << " * " << getGoodsNum() << endl << endl;
			player.setTask(Task(1));

		}
		else cout << "需要与之前人物交谈。或者已经交谈过了。" << endl << endl;
		break;
	}
	case 4: {
		if (player.getStory() == 2) {
			if (player.getTaskIsEnd() == true) {	//检查任务是否完成
				cout << "广法天尊：这位少侠，为何如此行色匆匆啊？" << endl;
				system("pause");
				cout << "你: 我正在寻找雪蝶的尸体，您可有听说过？" << endl;
				system("pause");
				cout << "广法天尊: 我并没有听说过，不过我的师兄玉鼎真人可能知道，你去问问他吧。" << endl;
				system("pause");
				cout << "你: 感谢天尊，那我这就去。" << endl;
				system("pause");
				cout << "广发天尊:你这样空手去可不行啊，我的师兄是个怪脾气，听说他最近在找大夏龙雀，你带上它去我师兄才会帮你的。" << endl;
				system("pause");
				cout << "你: 敢问在哪里才能找到大夏龙雀？" << endl;
				system("pause");
				cout << "广发天尊:这件神器是在地宫顶峰，那里有远古石甲虫守护，你可要小心啊，这里有件环锁铠，拿去防身。" << endl;
				system("pause");
				player.setStory(player.getStory() + 1);
				player.addGoodsToBag(getGoodsId(), getGoodsNum());
				cout << endl << "获得物品:" << goods[getGoodsId()].getName() << " * " << getGoodsNum() << endl << endl;
				player.setTask(Task(2));
			}
			else cout << "你未达成任务，无法对话。";
			}
		else cout << "需要与之前人物交谈。或者已经交谈过了。" << endl << endl;
		break;
	}
	case 5: {
		if (player.getStory() == 3) {
			cout << "  " << endl;
			system("pause");
			cout << "接引道人：嘿！小子！有没有看见我的毒蝎虎？" << endl;
			system("pause");
			cout << "你: 没有，我正在寻找雪蝶，您可有听说过？" << endl;
			system("pause");
			cout << "接引道人: 我也没有，不过这地宫寒冷无比，你是怎么进来的？" << endl;
			system("pause");
			cout << "你: 我已经寻找了很久了，心里很着急，误打误撞我就进来了。" << endl;
			system("pause");
			cout << "接引道人:看你相貌堂堂，也不想是坏人，在这人生地不熟的，我就给你点小还丹，记得帮我看看有没有见着我的毒蝎虎。" << endl;
			system("pause");
			player.setStory(player.getStory() + 1);
			player.addGoodsToBag(getGoodsId(), getGoodsNum());
			cout << endl << "获得物品:" << goods[getGoodsId()].getName() << " * " << getGoodsNum() << endl << endl;


		}
		else cout << "需要与之前人物交谈。或者已经交谈过了。" << endl << endl;
		break;
	}
	case 7: {
		if (player.getStory() == 4) {
			cout << "一位醉酒了的邋遢男子向你走来，嘴里还念念有词的说：“我可是玉鼎真人......”" << endl;
			system("pause");
			cout << "你:您就是玉鼎真人？ 我正在寻找雪蝶的尸体，您可有听说过？" << endl;
			system("pause");
			cout << "玉鼎真人：少侠，求人可是要有诚意的哦。" << endl;
			system("pause");
			if (player.getTaskIsEnd() == true) {	//检查任务是否完成
				cout << "你: 是你的师弟广法天尊叫我来的，他说给你大夏龙雀，你会有些答案。" << endl;
				system("pause");
				cout << "玉鼎真人: 看来你是有备而来啊，我也只有听说雪蝶并没有死，她被树怪掳走后陷入了龙穴，不过我不知道是哪里的龙。" << endl;
				system("pause");
				cout << "你: 感谢真人，可我这线索就断了啊，这可怎么办啊。" << endl;
				system("pause");
				cout << "玉鼎真人:不用着急，你可以去找我们的师傅元始天尊，他神通广大肯定知道在哪。" << endl;
				system("pause");
				cout << "玉鼎真人: 不过他老人家也跟我一样爱财如命，你可以带着紫龙天罡铠去昆仑找他。你懂的。你帮我找到了大夏龙雀，我也没什么报答你，一把无影飞剑就赠于你了。" << endl;
				system("pause");
				cout << "你: 谢真人。" << endl;
				system("pause");
				player.setStory(player.getStory() + 1);
				player.addGoodsToBag(getGoodsId(), getGoodsNum());
				cout << endl << "获得物品:" << goods[getGoodsId()].getName() << " * " << getGoodsNum() << endl << endl;
				player.setTask(Task(3));
			}
			else {
				cout << "玉鼎真人：你一点诚意都没有，我们就交不了朋友了" << endl;
				system("pause");
				cout << "玉鼎真人径直离开了你" << endl;
				system("pause");
			}
			

		}
		else cout << "需要与之前人物交谈。或者已经交谈过了。" << endl << endl;
		break;
	}
	case 9: {
		if (player.getStory() == 5) {
			cout << "元始天尊:你来了。" << endl;
			system("pause");
			cout << "你: 天尊果然神通广大，竟然能知道我要来。我正在寻找雪蝶，您可有听说过？" << endl;
			system("pause");
			cout << "元始天尊: 你一路找来，我都知道了。" << endl;
			system("pause");
			cout << "你: 敢请天尊明示。" << endl;
			system("pause");
			if (player.getTaskIsEnd() == true) {
				cout << "元始天尊:她还活着，被困在纳什男爵的龙坑里了，你要打败它才能救出雪蝶。" << endl;
				system("pause");
				cout << "你: 谢过天尊。" << endl;
				system("pause");
				cout << "元始天尊:你这样去可不行，我这有一把剑，见你有缘，也不想江湖少一位有为少年，赐给你了。" << endl;
				system("pause");
				player.setStory(player.getStory() + 1);
				player.addGoodsToBag(getGoodsId(), getGoodsNum());
				cout << endl << "获得物品:" << goods[getGoodsId()].getName() << " * " << getGoodsNum() << endl << endl;
			}
			else {
				cout << "你知道我的要求，你过几天再来找我吧。" << endl;
			}
		}
		else cout << "需要与之前人物交谈。或者已经交谈过了。" << endl << endl;
		break;
	}
	default:cout << "没有这个人物。" << endl << endl;break;
	}
	return player;
}

int Npc::getGoodsNum()
{
	return goodNum;
}

int Npc::getGoodsId() {
	return goodId;
}

int Npc::getMoney() {
	return money;
}
bool Npc::isChatted(int whichNpc) {
	if (whichNpc == 1)
		return true;
	if (whichNpc == 2)
		return true;
	if (whichNpc == 3)
		return true;
	if (whichNpc == 4)
		return true;
	if (whichNpc == 5)
		return true;
	if (whichNpc == 6)
		return false;
}
