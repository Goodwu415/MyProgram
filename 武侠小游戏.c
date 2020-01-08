#include <stdio.h>

struct Hero{
	int id;			
	char name[50];	//名称  
	char skill[50];	//技能 
	int level;		//等级 
	int hp;			//血量 
	int mp;			//魔法值 
	
};
struct Martial{
	int id; 	//
	char name[50];	//名称
	int count; 		//人数
	int type;		//类型 
};
struct Player{
	int id;
	char name[50]; 	//名称
	char pass[50];	//登陆密码
	char sex;  		//性别
	struct Martial martial; // 门派 
}; 
int main()
{
	struct Player player = { 1, "杨蜥蜴","123",'f',{1, "动物派", 1, 2} };
	printf("id %d\t名称 %s\t密码 %s\t性别 %c\t门派id %d	门派名称 %s\t人数 %d\t门派类型 %d\n",player.id,player.name,player.pass,player.sex,player.martial.id,player.martial.name,player.martial.count,player.martial.type);	
  
	return 0;
}
