#include <stdio.h>

struct Hero{
	int id;			
	char name[50];	//����  
	char skill[50];	//���� 
	int level;		//�ȼ� 
	int hp;			//Ѫ�� 
	int mp;			//ħ��ֵ 
	
};
struct Martial{
	int id; 	//
	char name[50];	//����
	int count; 		//����
	int type;		//���� 
};
struct Player{
	int id;
	char name[50]; 	//����
	char pass[50];	//��½����
	char sex;  		//�Ա�
	struct Martial martial; // ���� 
}; 
int main()
{
	struct Player player = { 1, "������","123",'f',{1, "������", 1, 2} };
	printf("id %d\t���� %s\t���� %s\t�Ա� %c\t����id %d	�������� %s\t���� %d\t�������� %d\n",player.id,player.name,player.pass,player.sex,player.martial.id,player.martial.name,player.martial.count,player.martial.type);	
  
	return 0;
}
