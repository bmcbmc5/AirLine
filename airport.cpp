#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 168
//�ɻ�����168�� 
int limit;//Ȩ�� 
/*	
	Ա����
		¼��
		�޸ĺ�����Ϣ 
		�û� ��
			��ѯ
			��Ʊ
			��Ʊ 
*/
int choice;//ѡ����� 
void print()
{
	/*
	printf("�����������˺ţ�\n");
	char username[11];
	scanf("%s",username);
	printf("��������������:\n");
	char secret[20];
	*/
	printf("����������Ȩ��:\n"); 
	scanf("%d",&limit);
	printf("-----------------------------\n");
	printf("   ����ѧԺ���չ�˾��ӭ����\n");
	printf("1.��ѯ����\n");
	printf("2.��Ʊ����\n");
	printf("3.�˶�����\n"); 
	if(limit == 1){
		printf("4.¼�뺽����Ϣ\n");
		printf("5.�޸ĺ�����Ϣ\n"); 
	} 
	printf("-----------------------------\n");
	printf("��������ѡ��ķ���\n");
	
	bool judge = false;
	while(!judge){
		fflush(stdin);
		double data;
		scanf("%lf",&data);
		if(data>5 || data<1|| data!=(int)data) printf("����������������룺\n");
		else if(limit==0&&4<=data&&data<=5) printf("����������������룺\n");
		else {
			judge = true;
			choice = (int)data;
		}
	} 
	
}
void first(){
	//��Ҫ��ͬһ���ļ����ڣ��½������ļ����ֱ�Ϊ
	//������Ϣ�ļ�������š���ɽ��� ʱ��ص㡢Ʊ�ۡ��ۿۡ�ÿ�˺����������� 
	//�˿���Ϣ�ļ������������֤�š���Ʊ�� ������ 
}
void checkin()
{
	// �򿪳˿���Ϣ�ļ� 
	// ¼����Ϣ 
		//����˿����������֤�š� ��Ʊ�� ������ 
		//����Ա ���Ƽ���غ���
			/*�Ƽ���ת*/
			/*ѡ����غ��࣬���Բ����ظ�������Ϣ*/
		//��û��Ա��д��˿���Ϣ�ļ� 
	//�رճ˿���Ϣ�ļ� 
}
void checkout()
{
	//�򿪳˿���Ϣ�ļ�
	// ¼����Ϣ 
		//����˿����������֤
		//ȷ���Ƿ���Ʊ
		//�޸��ļ�����Ϣ 
	//�رճ˿���Ϣ�ļ� 
}
}
void search()
{
	// �򿪺�����Ϣ 
	// ¼����Ϣ 
	//1.
		//�����ѯ�����
		//���ֲ���
		//�����Ϣ 
	//2.
		//������ɽ������
		//�����AΪ��㣬BΪ�յ�ĺ���
		/*�����ת��Ϣ*/ 
	//�رպ�����Ϣ�ļ� 
}
void input()
{
	// �򿪺�����Ϣ 
		// ¼����Ϣ 
		//������Ž������� 
	//�رպ�����Ϣ�ļ� 
	
}
void change()
{
	// �򿪺�����Ϣ 
	// ¼����Ϣ 
		//�޸ķ����ࣺ���� or ɾ��
		//�����ģ��ѽṹ������Ϣ����
		//��ɾ�����Ѻ��渲��ǰ�� struct[i-1]=struct[i] 
	//�رպ�����Ϣ�ļ� 
}
int main(){
	print();
	switch(choice)
	{
		case 1: search(); break;
		case 2: checkin(); break;
		case 3: checkout(); break;
		case 4: input(); break;
		default: change();
	}
	return 0;
} 
