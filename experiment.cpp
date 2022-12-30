#include<stdio.h>
#include<string.h>

int searchLine(char* arr){
	int num=3;
	return num;
}
int searchPas(char* arr){
	int num=3;
	return num;
}
/*
int main() {
	fopen("DataStructure.txt", "r");
	if(fp!=NULL){
		while(!feof(fp)){
			printf("%c",getc(fp));
		}
		fclose(fp);
	}
	else
		printf("fail to open!");
	return 0;
}*/

typedef struct user{
	char name[10];//�û����� 
	char id[20];//�û����֤�� 
	char account[15];//�˺� 
	char password[20];//���� 
	char phoneNum[12];//�ֻ��� 
	int num;//�û����� 
	//int level;//Ȩ��ֵ 
}user;

typedef struct flight{
	char flightNum[10];//����� 
	char up_time[17];//���ʱ�� 
	char off_time[17];//����ʱ�� 
	char up_pos[10];
	char off_pos[10];//��ʼ�� 
	double price;//Ʊ�� 
	double discount;//�ۿ� 
	int num;//�����ϵ����� 
}flight;

typedef struct passenger{
	char name[10]; 
	char id[20];
	char flightNum[10];
	char phoneNum[12];
	int num;//�˿����� 
}passenger;

int level=0;//Ȩ��ֵ 
user userArr[500005];
flight flightArr[500005];
passenger passengerArr[500005];

void rewrite(int index){//�޸��û�
	double choice;
	int aim_index;
	char aim_id[20];
	char oldPasword[20];
	char newPaswordf[20];
	char newPaswords[20];
	char newPhoneNum[12];
	if(level==1){
		printf("�������û����֤�ţ�\n");
		scanf("%s",aim_id);
		aim_index=search_user(aim_id);
		while(aim_index==-1){
			printf("δ��ѯ�����û����Ƿ������ѯ��\n");
			printf("1.������ѯ\n");
			printf("2.�˳�\n");
			scanf("%lf",&choice);
			if(choice==2){
				printf("�������û����֤�ţ�\n");
				scanf("%s",aim_id);
			}
			else
				return;
		}
	}
	else
		aim_index=index;
	printf("��ѡ����Ҫ�޸ĵ���Ϣ��\n");
	printf("1.����\n");
	printf("2.�ֻ���\n");
	scanf("%lf",&choice);
	while(choice<1||choice>2||choice!=(int)choice){
		printf("����ʧ�ܣ����������룡\n");
		scanf("%lf",&choice);
	}
	if(choice==1){
		printf("������ԭ���룺\n");
		scanf("%s",oldPasword);
		while(strcmp(oldPasword,userArr[aim_index].password)!=0){
			printf("ԭ��������Ƿ�����޸ģ�\n");
			printf("1.�����޸�		2.�˳��޸�\n");
			scanf("%lf",&choice);
			while(choice<1||choice>2||choice!=(int)choice){
				printf("����ʧ�ܣ����������룡\n");
				scanf("%lf",&choice);
			}
			if(choice==1){
				printf("������ԭ���룺\n");
				scanf("%s",oldPasword);
			}
			else
				return;
		}
		printf("�����������룺\n");
		scanf("%s",newPaswordf);
		printf("���ٴ����������룺\n");
		scanf("%s",newPaswords);
		while(strcmp(newPaswordf,newPaswords)!=0){
			for(int i=0;i<strlen(newPaswords);i++)
				newPaswords[i]='\0';
			printf("�������벻һ�£����ٴ����������룺\n");
			scanf("%s",newPaswords);
		}
		strcpy(userArr[aim_index].password,newPaswords);
	}
	else{
		printf("�������µ��ֻ��ţ�\n");
		scanf("%s",newPhoneNum);
		while(strlen(newPhoneNum)!=strlen(userArr[aim_index].phoneNum)){
			printf("�ֻ����쳣�����������룺\n");
			scanf("%s",newPhoneNum);
		}
		strcpy(userArr[aim_index].phoneNum,newPhoneNum);
	}
	printf("�û���Ϣ�޸ĳɹ���\n");
	return;
}

void change(){//�޸ĺ���
	int index;
	char aim_flightNum[10];
	char reup_time[17];//���ʱ�� 
	char reoff_time[17];//����ʱ�� 
	char year[5];
	char month[3];
	char day[3];
	char hour[3];
	char minute[3];
	double reprice;//Ʊ�� 
	double rediscount;//�ۿ� 
	double choice;
	printf("�����뺽��ţ�\n");
	scanf("%s",aim_flightNum);
	index=search_flight(aim_flightNum);
	while(index==-1){
		printf("����Ų����ڣ����������룺\n");
		scanf("%s",aim_flightNum);
		index=search_flight(aim_flightNum);
	}
	printf("��ѡ����Ҫ�޸ĵĺ�����Ϣ��\n"); 
	printf("1.�������ʱ��		2.���ཱུ��ʱ��\n");
	printf("3.����Ʊ��			4.�����ۿ�\n");
	scanf("%lf",&choice);
	while(choice<1||choice>4||choice!=(int)choice){
		printf("����ʧ�ܣ����������룡\n");
		scanf("%lf",&choice);
	}
	if(choice==1){
		printf("�������µ����ʱ�䣺\n");
		scanf("%s",reup_time);
		while(strlen(reup_time)!=16){
			printf("�����ʽ����ȷ�����������룺\n");
			scanf("%s",reup_time);
		}
		while(strcmp(reup_time,flightArr[index].off_time)>=0){
			printf("��Ч���룬���������룺\n");
			scanf("%s",reup_time);
		}
		for(int i=0;i<16;i++){
			if(reup_time[i]=='/'){
				if(i!=4||i!=7||i!=10){
					printf("�����ʽ����ȷ�����������룺\n");
					scanf("%s",reup_time);
					i=0;
					continue;
				}
			}
			else if(reup_time[i]==':'){
				if(i!=13){
					printf("�����ʽ����ȷ�����������룺\n");
					scanf("%s",reup_time);
					i=0;
					continue;
				}
			}
			else{
				if(reup_time[i]<'0'||reup_time[i]>'9'){
					printf("�����ʽ����ȷ�����������룺\n");
					scanf("%s",reup_time);
					i=0;
					continue;
				}
				for(int j=0;j<4;j++)
					year[j]=reup_time[j];
				month[0]=reup_time[5];month[1]=reup_time[6];
				day[0]=reup_time[8];day[1]=reup_time[9];
				hour[0]=reup_time[11];hour[1]=reup_time[12];
				minute[0]=reup_time[14];minute[1]=reup_time[15];
				if(strcmp(month,"01")<0||strcmp(month,"12")>0||strcmp(day,"01")<0||strcmp(day,"31")>0||
					strcmp(hour,"00")<0||strcmp(hour,"23")>0||strcmp(minute,"00")<0||strcmp(minute,"59")>0||
					strcmp(year,"2022")<0||strcmp(year,"2023")>0){
					printf("�����ʽ����ȷ�����������룺\n");
					scanf("%s",reup_time);
					i=0;
					continue;
				}
				else if(strcmp(month,"02")==0&&strcmp(day,"29")>0){
					printf("�����ʽ����ȷ�����������룺\n");
					scanf("%s",reup_time);
					i=0;
					continue;
				}
			}
		}
		strcpy(flightArr[index].up_time,reup_time);
		//2022/12/12/14:23
	}
	else if(choice==2){
		printf("�������µĽ���ʱ�䣺\n");
		scanf("%s",reoff_time);
		while(strlen(reoff_time)!=16){
			printf("�����ʽ����ȷ�����������룺\n");
			scanf("%s",reoff_time);
		}
		while(strcmp(reoff_time,flightArr[index].up_time)<=0){
			printf("��Ч���룬���������룺\n");
			scanf("%s",reoff_time);
		}
		for(int i=0;i<16;i++){
			if(reoff_time[i]=='/'){
				if(i!=4||i!=7||i!=10){
					printf("�����ʽ����ȷ�����������룺\n");
					scanf("%s",reoff_time);
					i=0;
					continue;
				}
			}
			else if(reoff_time[i]==':'){
				if(i!=13){
					printf("�����ʽ����ȷ�����������룺\n");
					scanf("%s",reoff_time);
					i=0;
					continue;
				}
			}
			else{
				if(reoff_time[i]<'0'||reoff_time[i]>'9'){
					printf("�����ʽ����ȷ�����������룺\n");
					scanf("%s",reoff_time);
					i=0;
					continue;
				}
				for(int j=0;j<4;j++)
					year[j]=reoff_time[j];
				month[0]=reoff_time[5];month[1]=reoff_time[6];
				day[0]=reoff_time[8];day[1]=reoff_time[9];
				hour[0]=reoff_time[11];hour[1]=reoff_time[12];
				minute[0]=reoff_time[14];minute[1]=reoff_time[15];
				if(strcmp(month,"01")<0||strcmp(month,"12")>0||strcmp(day,"01")<0||strcmp(day,"31")>0||
					strcmp(hour,"00")<0||strcmp(hour,"23")>0||strcmp(minute,"00")<0||strcmp(minute,"59")>0||
					strcmp(year,"2022")<0||strcmp(year,"2023")>0){
					printf("�����ʽ����ȷ�����������룺\n");
					scanf("%s",reoff_time);
					i=0;
					continue;
				}
				else if(strcmp(month,"02")==0&&strcmp(day,"29")>0){
					printf("�����ʽ����ȷ�����������룺\n");
					scanf("%s",reoff_time);
					i=0;
					continue;
				}
			}
		}
		strcpy(flightArr[index].off_time,reoff_time);
	}
	else if(choice==3){
		printf("�������µ�Ʊ�ۣ�\n");
		scanf("%lf",&reprice);
		flightArr[index].price=reprice;
	}
	else{
		printf("�������µ��ۿۣ�\n");
		scanf("%lf",&rediscount);
		while(rediscount<0||rediscount>100){
			printf("�ۿ�ֵ����ȷ�����������룺\n");
			scanf("%lf",&rediscount);
		}
		flightArr[index].discount=rediscount;
	}
	printf("������Ϣ�޸ĳɹ���\n");
	return;
}

void checkOut(int index){//��Ʊ
	char ticket[10];
	char aim_id[20];
	int idx_passenger;
	int	idx_user;
	double choice; 
	if(level==1){
		printf("��������Ʊ�����֤��\n");
		scanf("%s",aim_id);
		idx_passenger=search_passenger(aim_id);
		while(idx_passenger==-1){
			printf("��ѯʧ�ܣ��Ƿ������ѯ��\n");
			printf("1.������ѯ		2.�˳���ѯ\n");
			scanf("%lf",&choice);
			while(choice<1||choice>2||choice!=(int)choice){
				printf("����������������룺\n");
				printf("1.������ѯ		2.�˳���ѯ\n");
				scanf("%lf",&choice);
			}
			if(choice==1){
				scanf("%s",aim_id);
				idx_passenger=search_passenger(aim_id);
			}
			else
				return;
		}
	}
	else{
		idx_user=index;
		idx_passenger=search_passenger(userArr[user].account)
		if(idx_passenger==-1){
			printf("��Ʊʧ�ܣ���δ����˺��࣡\n");
			return;
		}
	}
	for(int i=idx_passenger;i<passengerArr[0].num;i++){
		strcpy(passengerArr[i].id,passengerArr[i+1].id);
		strcpy(passengerArr[i].name,passengerArr[i+1].name);
		strcpy(passengerArr[i].phoneNum,passengerArr[i+1].phoneNum);
		strcpy(passengerArr[i].flightNum,passengerArr[i+1].flightNum);
	}
	passengerArr[0].num--;
	printf("��Ʊ�ɹ���\n");
	return; 
}

void delAcount(int index){//����Աɾ���û� ���û�ע���˻� 
	int aim_index;
	double choice;
	char aim_id[20];
	char aim_password[20];
	if(level==1){
		printf("�����뱻ע�������֤��\n");
		scanf("%s",aim_id);
		aim_index=search_user(aim_id);
		while(aim_index==-1){
			printf("��ѯע����ʧ�ܣ��Ƿ����ע����\n");
			printf("1.����ע��		2.�˳�ע��\n");
			scanf("%lf",&choice);
			while(choice<1||choice>2||choice!=(int)choice){
				printf("����������������룺\n");
				printf("1.����ע��		2.�˳�ע��\n");
				scanf("%lf",&choice);
			}
			if(choice==1){
				scanf("%s",aim_id);
				aim_index=search_user(aim_id);
			}
			else
				return;
		}
	}
	else
		aim_index=index;
	printf("�Ƿ�ȷ��ע�����˻���\n");
	printf("1.ȷ��ע��		2.�˳�ע��\n");
	scanf("%lf",&choice);
	while(choice<1||choice>2||choice!=(int)choice){
		printf("����������������룺\n");
		printf("1.ȷ��ע��		2.�˳�ע��\n");
		scanf("%lf",&choice);
	}
	if(choice==1){
		printf("�������˻�����ȷ����ݣ�\n");
		scanf("%s",aim_password);
		while(strcmp(aim_password,userArr[aim_index].password)!=0){
			printf("��������Ƿ��������룺\n");
			printf("1.��������		2.�˳�ע��\n");
			scanf("%lf",&choice);
			while(choice<1||choice>2||choice!=(int)choice){
				printf("����������������룺\n");
				printf("1.��������		2.�˳�ע��\n");
				scanf("%lf",&choice);
			}
			if(choice==1){
				scanf("%s",aim_password);
			}
			else
				return;
		}
		for(int i=aim_index;i<userArr[0].num;i++){
			strcpy(userArr[i].name,userArr[i+1].name);
			strcpy(userArr[i].id,userArr[i+1].id);
			strcpy(userArr[i].account,userArr[i+1].account);
			strcpy(userArr[i].password,userArr[i+1].password);
			strcpy(userArr[i].phoneNum,userArr[i+1].phoneNum);
		}
		userArr[0].num--;
		printf("ע���˻��ɹ���\n");
	}
	else
		return;
}

void  link(){
	int len=0;
	char account[17];
	scanf("%s",account);
	for(int i=0;i<16;i++)
		printf("%c",account[i]);
	printf("\n");
	printf("%d",strlen(account));
}
int main(){
	link();
}

