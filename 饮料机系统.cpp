#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000/*�����ṹ����������ֵ*/
int drink_numbers = 0;//ȫ�ֱ���
float total_sales = 0;

typedef struct Information /*����ṹ�崢��������Ϣ*/
{
	char name[30];	//��������
	float price;	//����
	int repertory;	//���
	int sold;	//��������
}information;

information drink[MAX];

/* ���˵� */
void MainMenu();
/* �û��˵� */
void UserMenu();
/* ����Ա�˵� */
void AdministratorMenu();
/* �û���ڣ����ڹ������� */
void User();
/* ��ӡ��ͷ */
void PrintHeader();
/* ��ӡһ�����ϵ���Ϣ */
void PrintOneDrink(int pos);
/* ����Ա��� */
void Administrator();
/* ����Ա��¼��֤ */
int AdministratorLogin();
/* 1---��ѯ���۶� */
void QuerySales();
/* 2---��ѯʣ���� */
void QueryRepertory();
/* 3---���� */
void Replenishment();
/* 4---������������ */
void AddDrink();
/* 5---��ѯ������Ϣ */
int FindDrink();
/* 6---�޸�������Ϣ */
void ChangeDrink();
/* 7---��ʾ����������Ϣ */
void DisplayDrink();
/* 8---ɾ������ */
void DeleteDrink();
/* ���ļ�����������Ϣ */
void InputDrinkFromFile();
/* ����������Ϣ���ļ� */
void SaveDrinkToFile();


int main(void)
{
	int value, OK = 0;
	
	system("color E");

	InputDrinkFromFile();/* ���ļ�����������Ϣ */

	printf("�밴�����������\n");
	fflush(stdin);
	getchar();

	while (1)
	{
		system("cls");
		MainMenu();		//���˵���ʾ
		
		scanf("%d", &value);
		
		system("cls");
		switch (value)//����value��ֵ��ִ����Ӧ�Ĳ��� 
		{
			case 1:
				User();
				break;
			case 2:
				Administrator();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("������Ϣ���󣡣�");
		}
		
		printf("�밴�����������\n");
		fflush(stdin);
		getchar();
	}

	return 0;
}

/* ���˵� */
void MainMenu()
{
	printf("\n");
	printf("|--------------------------------------------|\n");
	printf("|               �����Զ��ۻ���               |\n");
	printf("|--------------------------------------------|\n");
	printf("|                1---��������                |\n");
	printf("|                2---����Ա����ϵͳ          |\n");
	printf("|                0---�˳�ϵͳ                |\n");
	printf("|--------------------------------------------|\n");
	printf("��ѡ����Ҫִ�еĲ�����");
}

/* �û��˵� */
void UserMenu()
{
	printf("\n");
	printf("|--------------------------------------------|\n");
	printf("|                  ���Ϲ���                  |\n");
	printf("|--------------------------------------------|\n");
	printf("|                1---ѡ������                |\n");
	printf("|                2---Ͷ��                    |\n");
	printf("|                3---�ұ�                    |\n");
	printf("|                0---�����ϼ��˵�            |\n");
	printf("|--------------------------------------------|\n");
	printf("��ѡ����Ҫִ�еĲ�����");
}

/* ����Ա�˵� */
void AdministratorMenu()
{
	printf("\n");
	printf("|--------------------------------------------|\n");
	printf("|               ����Ա����ϵͳ               |\n");
	printf("|--------------------------------------------|\n");
	printf("|                1---��ѯ���۶�              |\n");
	printf("|                2---��ѯʣ����            |\n");
	printf("|                3---����                    |\n");
	printf("|                4---������������            |\n");
	printf("|                5---��ѯ������Ϣ            |\n");
	printf("|                6---�޸�������Ϣ            |\n");
	printf("|                7---��ʾ����������Ϣ        |\n");
	printf("|                8---ɾ������                |\n");
	printf("|                0---�����ϼ��˵�            |\n");
	printf("|--------------------------------------------|\n");
	printf("��ѡ����Ҫִ�еĲ�����");
}

/* �û���ڣ����ڹ������� */
void User()
{
	int flag = 0;
	int i, n = 0;
	int choose;
	int cart[10][2];
	float money = 0, temp_money;
	float subtotal, total_price = 0;

	while(1)
	{
		UserMenu();

		scanf("%d", &choose);

		if(choose == 0)
		{
			break;
		}

		switch(choose)
		{
			case 1:
				printf("��ѡ���������£�\n");
				for(i = 0; i < drink_numbers; i++)
				{
					printf("%d.%s(%.1fԪ)\n", i+1, drink[i].name, drink[i].price);
				}
				while(1)
				{
					printf("��������������������(��������Ҫ�ٹ���ʱ������0)��");
					scanf("%d", &cart[n][0]);
					if(cart[n][0] == 0)
					{
						break;
					}
					while(1)
					{
						printf("����������Ҫ���ƿ����");
						scanf("%d", &cart[n][1]);

						if(cart[n][1] > drink[cart[n][0] - 1].repertory)
						{
							printf("������������������������ǰ�����Ϊ: %d ƿ�� ���������룡\n", drink[cart[n][0] - 1].repertory);
						}
						else
						{
							break;
						}
					}
					
					n++;
				}

				if(n != 0)
				{
					printf("�������������Ϣ���£�\n");
					printf("����\t\t����\tС��\n");
					for(i = 0; i < n; i++)
					{
						subtotal = drink[cart[i][0] - 1].price * cart[i][1];
						printf("%s\t%d\t%.1f\n", drink[cart[i][0] - 1].name, cart[i][1], subtotal);
						total_price += subtotal;

					}
					printf("�ܷ���Ϊ��%.1f\n", total_price);

					printf("���ڷ��غ�Ͷ�ҹ���\n");
				}
				break;
			case 2:
				if(total_price == 0)
				{
					printf("����ѡ�����ϣ�\n");
				}
				else
				{
					while(1)
					{
						printf("��Ͷ�ң�ֻ����5ë��1ԪӲ�Һ�5Ԫ��10Ԫֽ�ң�\n");
						scanf("%f", &temp_money);
						if(temp_money == 0.5 || temp_money == 1 || temp_money == 5 || temp_money == 10)
						{
							money += temp_money;
							if(money < total_price)
							{
								printf("���� %.1f Ԫ�������Ͷ�룡\n", total_price - money);
							}
							else
							{
								printf("����ɹ��������� %.1f Ԫ�����ڷ��غ�ѡ���˱ң�\n", money - total_price);
								for(i = 0; i < n; i++)
								{
									drink[cart[i][0] - 1].repertory -= cart[i][1];
									drink[cart[i][0] - 1].sold += cart[i][1];
									total_sales += drink[cart[i][0] - 1].price * cart[i][1];
								}
								n = 0;
								break;
							}
						}
						else
						{
							printf("��Ͷ��ı��ִ���\n");
						}
					}
				}
				break;
			case 3:
				if(money == 0)
				{
					printf("����û��Ͷ���καң�\n");
				}
				else
				{
					printf("�ѳɹ����� %.1f Ԫ����ӭ�´ι���\n", money - total_price);
					total_price = 0;
					money = 0;

					printf("�밴�����������\n");
					fflush(stdin);
					getchar();

					system("cls");
				}
				break;
		}
	}
}

/* ��ӡ��ͷ */
void PrintHeader()
{
	printf("����\t\t����\t���\t��������\n");
}

/* ��ӡһ�����ϵ���Ϣ */
void PrintOneDrink(int pos)
{
	printf("%s\t\t%.1f\t%d\t%d\n", drink[pos].name, drink[pos].price, drink[pos].repertory, drink[pos].sold);
}

/* ����Ա��� */
void Administrator()
{
	int choose;

	if(AdministratorLogin() == 0)
	{
		return;
	}

	while(1)
	{
		system("cls");

		AdministratorMenu();

		scanf("%d", &choose);

		if(choose == 0)
		{
			SaveDrinkToFile();/* ����������Ϣ���ļ� */
			break;
		}

		switch(choose)
		{
			case 1:
				QuerySales();/* 1---��ѯ���۶� */
				break;
			case 2:
				QueryRepertory();/* 2---��ѯʣ���� */
				break;
			case 3:
				Replenishment();/* 3---���� */
				break;
			case 4:
				AddDrink();/* 4---������������ */
				break;
			case 5:
				FindDrink();/* 5---��ѯ������Ϣ */
				break;
			case 6:
				ChangeDrink();/* 6---�޸�������Ϣ */
				break;
			case 7:
				DisplayDrink();/* 7---��ʾ����������Ϣ */
				break;
			case 8:
				DeleteDrink();/* 8---ɾ������ */
				break;
		}

		printf("�밴�����������\n");
		fflush(stdin);
		getchar();
	}
}

/* ����Ա��¼��֤ */   
int AdministratorLogin()
{
	int cnt = 1;
	char user1[] = "lijiangyu";
	char key1[] = "2190280207";
	char user2[100], key2[100];
	
	printf("|--------------------------------------------|\n");
	printf("|                  ϵͳ��¼                  |\n");
	printf("|--------------------------------------------|\n");
	
	while (cnt <= 3)
	{
		printf("�������û���\n");
		scanf("%s", user2);
		printf("���������룺\n");
		scanf("%s", key2);
		if (strcmp(user1, user2) != 0 || strcmp(key1, key2) != 0)
		{
			if (cnt == 3)
			{
				printf("�û���������������Ļ����Ѿ�����\n");
				return 0;
			}
			else
				printf("�û���������������������룬������ %d �λ���\n", 3 - cnt);
		}
	
		if (strcmp(user1, user2) == 0 && strcmp(key1, key2) == 0)
		{
			printf("��¼�ɹ���\n");
			return 1;
		}
		cnt++;
	}
    return 0;
}

/* 1---��ѯ���۶� */
void QuerySales()
{
	int i;

	printf("��̨����������������£�\n");
	printf("����\t\t��������\n");
	for(i = 0; i < drink_numbers; i++)
	{
		printf("%s\t\t%d\n", drink[i].name, drink[i].sold);
	}
	printf("�����ܶ�Ϊ��%.1f\n", total_sales);
}

/* 2---��ѯʣ���� */
void QueryRepertory()
{
	int i;
	printf("����\t\tʣ����\n");
	for(i = 0; i < drink_numbers; i++)
	{
		printf("%s\t\t%d\n", drink[i].name, drink[i].repertory);
	}
}

/* 3---���� */
void Replenishment()
{
	int i;
	int temp;

	printf("���ڸ��������ƺ������벹���������\n");
	for(i = 0; i < drink_numbers; i++)
	{
		printf("%s��", drink[i].name);
		scanf("%d", &temp);
		drink[i].repertory += temp;
	}
}

/* 4---������������ */
void AddDrink()
{
	int i;

	printf("�밴����ʾ����������Ϣ�����㲻��¼���ʱ������д���Ƶĵط���д*\n");
	for (i = drink_numbers; ; i++)
	{
		printf("��¼�����ϵ����ƣ�\n");
		scanf("%s", drink[i].name);
		if (strcmp(drink[i].name, "*") == 0)	//�������*�Աȣ����������*�����˳�����
		{
			printf("���ӳɹ�!\n");
			break;
		}
		printf("��¼������ϵĵ��ۣ�\n");
		scanf("%f", &drink[i].price);
		printf("��¼������ϵĿ�棺\n");
		scanf("%d", &drink[i].repertory);
		
		drink[i].sold = 0;

		drink_numbers++;
	}
}

/* 5---��ѯ������Ϣ */
int FindDrink()
{
 	int i, flag = 0;
 	char a[20];
 	printf("����������Ҫ��ѯ����������\n");
 	scanf("%s", a);
 	for (i = 0; i < drink_numbers; i++)
 	{
 		if (strcmp(a, drink[i].name) == 0)
 		{
 			printf("���ҵ������ϣ���Ϣ���£�\n");
 			PrintHeader();
 			PrintOneDrink(i);
 			return i;
 		}
 	}

 	printf("δ�ҵ���������Ϣ��\n");
 	return -1;
}

/* 6---�޸�������Ϣ */   
void ChangeDrink()
{
	int choose;
	char temp[5];
	int pos;
	
	printf("�����ҵ���Ҫ�޸ĵ����ϣ�\n");
	pos = FindDrink();
	if(pos != -1)
	{
		printf("�Ƿ�ȷ���޸ģ��ǣ�y ��n��: ");
		scanf("%s", temp);
		if(strcmp(temp, "y") == 0)
		{
			while(1)
			{
				printf("��������Ҫ�޸ĵ����ݱ�ţ�\n");
			 	printf("1.����\n");
			 	printf("2.����\n");
			 	printf("3.���\n");
			 	printf("4.��������\n");
			 	printf("0.�˳��޸ģ��������˵�\n");
	
			 	scanf("%d", &choose);
	
			 	if(choose == 0)
			 	{
			 		break;
			 	}
	
			 	switch(choose)
			 	{
			 		case 1:
			 			printf("�������µ����ƣ�\n");
			 			scanf("%s", drink[pos].name);
			 			break;
			 		case 2:
			 			printf("�������µĵ��ۣ�\n");
			 			scanf("%f", &drink[pos].price);
			 			break;
			 		case 3:
			 			printf("�������µĿ�棺\n");
			 			scanf("%d", &drink[pos].repertory);
			 			break;
			 		case 4:
			 			printf("�������µ�����������\n");
			 			scanf("%d", &drink[pos].sold);
			 			break;
			 		default:
			 			printf("�������\n");
			 			break;
			 	}
				printf("\n�޸ĳɹ�!\n");
			} 
		}
		else
		{
			printf("\nȡ���޸ĳɹ���\n");
			return;
		}
	}
	printf("�밴�����������\n");
	getchar();
}

/* 7---��ʾ����������Ϣ */   
void DisplayDrink()
{
	int i;

	PrintHeader();
	for(i = 0; i < drink_numbers; i++)
	{
		PrintOneDrink(i);
		if((i + 1) % 10 == 0)
		{
			printf("�������������ҳ��\n");
			getchar();
			system("cls");
			PrintHeader();
		}
	}
}

/* 8---ɾ������ */        
void DeleteDrink()
{
	int i, pos;
	char temp[5];

	printf("���Ȳ��ҵ���Ҫɾ�������ϣ�\n");
	pos = FindDrink();

	if(pos != -1)
	{
		printf("�Ƿ�ȷ��ע�����ǣ�y ��n��: ");
		scanf("%s", temp);
		if(strcmp(temp, "y") == 0)
		{
			for(i = pos; i < drink_numbers; i++)
			{
				drink[i] = drink[i + 1];
			}
			drink_numbers--;
			printf("\nע���ɹ�!\n");
		}
		else
		{
			printf("\nȡ��ע���ɹ���\n");
			return;
		}
	}
}

/* ���ļ�����������Ϣ */        
void InputDrinkFromFile()
{
	
	char temp[100];

	FILE *fp;

	fp = fopen("drink.txt", "rb");
	
	if(fp == NULL)
	{
		printf("�ļ���ʧ�ܣ������ļ��Ƿ���ڣ�\n");
		return;
	}
	else
	{
		fgets(temp, 100, fp);
		while(fscanf(fp, "%s%f%d%d", drink[drink_numbers].name, &drink[drink_numbers].price, &drink[drink_numbers].repertory, &drink[drink_numbers].sold) == 4)
		{
			drink_numbers++;
		}
	
		printf("�ɹ����� %d ��������Ϣ��\n", drink_numbers);
		fclose(fp);
	}
}

/* ����������Ϣ���ļ� */      
void SaveDrinkToFile()
{
	int i;

	FILE *fp;

	fp = fopen("drink.txt", "w");

	fprintf(fp, "����\t����\t���\t��������\n");
	for (i = 0; i < drink_numbers; i++)
	{
		fprintf(fp, "%s\t%.1f\t%d\t%d\n", drink[i].name, drink[i].price, drink[i].repertory, drink[i].sold);
	}

	fclose(fp); 
	printf("���ݱ���ɹ���\n");
}

