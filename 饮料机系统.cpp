#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000/*给定结构体数组的最大值*/
int drink_numbers = 0;//全局变量
float total_sales = 0;

typedef struct Information /*定义结构体储存饮料信息*/
{
	char name[30];	//饮料名称
	float price;	//单价
	int repertory;	//库存
	int sold;	//已销售量
}information;

information drink[MAX];

/* 主菜单 */
void MainMenu();
/* 用户菜单 */
void UserMenu();
/* 管理员菜单 */
void AdministratorMenu();
/* 用户入口，用于购买饮料 */
void User();
/* 打印表头 */
void PrintHeader();
/* 打印一种饮料的信息 */
void PrintOneDrink(int pos);
/* 管理员入口 */
void Administrator();
/* 管理员登录验证 */
int AdministratorLogin();
/* 1---查询销售额 */
void QuerySales();
/* 2---查询剩余库存 */
void QueryRepertory();
/* 3---补货 */
void Replenishment();
/* 4---增加饮料种类 */
void AddDrink();
/* 5---查询饮料信息 */
int FindDrink();
/* 6---修改饮料信息 */
void ChangeDrink();
/* 7---显示所有饮料信息 */
void DisplayDrink();
/* 8---删除饮料 */
void DeleteDrink();
/* 从文件导入饮料信息 */
void InputDrinkFromFile();
/* 导出饮料信息到文件 */
void SaveDrinkToFile();


int main(void)
{
	int value, OK = 0;
	
	system("color E");

	InputDrinkFromFile();/* 从文件导入饮料信息 */

	printf("请按任意键继续！\n");
	fflush(stdin);
	getchar();

	while (1)
	{
		system("cls");
		MainMenu();		//主菜单显示
		
		scanf("%d", &value);
		
		system("cls");
		switch (value)//根据value的值来执行相应的操作 
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
				printf("输入信息错误！！");
		}
		
		printf("请按任意键继续！\n");
		fflush(stdin);
		getchar();
	}

	return 0;
}

/* 主菜单 */
void MainMenu()
{
	printf("\n");
	printf("|--------------------------------------------|\n");
	printf("|               饮料自动售货机               |\n");
	printf("|--------------------------------------------|\n");
	printf("|                1---购买饮料                |\n");
	printf("|                2---管理员操作系统          |\n");
	printf("|                0---退出系统                |\n");
	printf("|--------------------------------------------|\n");
	printf("请选择所要执行的操作：");
}

/* 用户菜单 */
void UserMenu()
{
	printf("\n");
	printf("|--------------------------------------------|\n");
	printf("|                  饮料购买                  |\n");
	printf("|--------------------------------------------|\n");
	printf("|                1---选择饮料                |\n");
	printf("|                2---投币                    |\n");
	printf("|                3---找币                    |\n");
	printf("|                0---返回上级菜单            |\n");
	printf("|--------------------------------------------|\n");
	printf("请选择所要执行的操作：");
}

/* 管理员菜单 */
void AdministratorMenu()
{
	printf("\n");
	printf("|--------------------------------------------|\n");
	printf("|               管理员操作系统               |\n");
	printf("|--------------------------------------------|\n");
	printf("|                1---查询销售额              |\n");
	printf("|                2---查询剩余库存            |\n");
	printf("|                3---补货                    |\n");
	printf("|                4---增加饮料种类            |\n");
	printf("|                5---查询饮料信息            |\n");
	printf("|                6---修改饮料信息            |\n");
	printf("|                7---显示所有饮料信息        |\n");
	printf("|                8---删除饮料                |\n");
	printf("|                0---返回上级菜单            |\n");
	printf("|--------------------------------------------|\n");
	printf("请选择所要执行的操作：");
}

/* 用户入口，用于购买饮料 */
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
				printf("可选的饮料如下：\n");
				for(i = 0; i < drink_numbers; i++)
				{
					printf("%d.%s(%.1f元)\n", i+1, drink[i].name, drink[i].price);
				}
				while(1)
				{
					printf("请输入您想买的饮料序号(当您不需要再购买时，输入0)：");
					scanf("%d", &cart[n][0]);
					if(cart[n][0] == 0)
					{
						break;
					}
					while(1)
					{
						printf("请输入您需要买的瓶数：");
						scanf("%d", &cart[n][1]);

						if(cart[n][1] > drink[cart[n][0] - 1].repertory)
						{
							printf("您购买的数量超过库存量，当前库存量为: %d 瓶， 请重新输入！\n", drink[cart[n][0] - 1].repertory);
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
					printf("您购买的饮料信息如下：\n");
					printf("名称\t\t数量\t小计\n");
					for(i = 0; i < n; i++)
					{
						subtotal = drink[cart[i][0] - 1].price * cart[i][1];
						printf("%s\t%d\t%.1f\n", drink[cart[i][0] - 1].name, cart[i][1], subtotal);
						total_price += subtotal;

					}
					printf("总费用为：%.1f\n", total_price);

					printf("请在返回后投币购买！\n");
				}
				break;
			case 2:
				if(total_price == 0)
				{
					printf("请先选择饮料！\n");
				}
				else
				{
					while(1)
					{
						printf("请投币（只接受5毛、1元硬币和5元、10元纸币）\n");
						scanf("%f", &temp_money);
						if(temp_money == 0.5 || temp_money == 1 || temp_money == 5 || temp_money == 10)
						{
							money += temp_money;
							if(money < total_price)
							{
								printf("还差 %.1f 元！请继续投入！\n", total_price - money);
							}
							else
							{
								printf("购买成功！您可退 %.1f 元！请在返回后选择退币！\n", money - total_price);
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
							printf("您投入的币种错误！\n");
						}
					}
				}
				break;
			case 3:
				if(money == 0)
				{
					printf("您还没有投入任何币！\n");
				}
				else
				{
					printf("已成功退您 %.1f 元！欢迎下次购买！\n", money - total_price);
					total_price = 0;
					money = 0;

					printf("请按任意键继续！\n");
					fflush(stdin);
					getchar();

					system("cls");
				}
				break;
		}
	}
}

/* 打印表头 */
void PrintHeader()
{
	printf("名称\t\t单价\t库存\t已销售量\n");
}

/* 打印一种饮料的信息 */
void PrintOneDrink(int pos)
{
	printf("%s\t\t%.1f\t%d\t%d\n", drink[pos].name, drink[pos].price, drink[pos].repertory, drink[pos].sold);
}

/* 管理员入口 */
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
			SaveDrinkToFile();/* 导出饮料信息到文件 */
			break;
		}

		switch(choose)
		{
			case 1:
				QuerySales();/* 1---查询销售额 */
				break;
			case 2:
				QueryRepertory();/* 2---查询剩余库存 */
				break;
			case 3:
				Replenishment();/* 3---补货 */
				break;
			case 4:
				AddDrink();/* 4---增加饮料种类 */
				break;
			case 5:
				FindDrink();/* 5---查询饮料信息 */
				break;
			case 6:
				ChangeDrink();/* 6---修改饮料信息 */
				break;
			case 7:
				DisplayDrink();/* 7---显示所有饮料信息 */
				break;
			case 8:
				DeleteDrink();/* 8---删除饮料 */
				break;
		}

		printf("请按任意键继续！\n");
		fflush(stdin);
		getchar();
	}
}

/* 管理员登录验证 */   
int AdministratorLogin()
{
	int cnt = 1;
	char user1[] = "lijiangyu";
	char key1[] = "2190280207";
	char user2[100], key2[100];
	
	printf("|--------------------------------------------|\n");
	printf("|                  系统登录                  |\n");
	printf("|--------------------------------------------|\n");
	
	while (cnt <= 3)
	{
		printf("请输入用户名\n");
		scanf("%s", user2);
		printf("请输入密码：\n");
		scanf("%s", key2);
		if (strcmp(user1, user2) != 0 || strcmp(key1, key2) != 0)
		{
			if (cnt == 3)
			{
				printf("用户名或密码错误！您的机会已经用完\n");
				return 0;
			}
			else
				printf("用户名或密码错误！请重新输入，您还有 %d 次机会\n", 3 - cnt);
		}
	
		if (strcmp(user1, user2) == 0 && strcmp(key1, key2) == 0)
		{
			printf("登录成功！\n");
			return 1;
		}
		cnt++;
	}
    return 0;
}

/* 1---查询销售额 */
void QuerySales()
{
	int i;

	printf("此台机器的销售情况如下：\n");
	printf("名称\t\t销售数量\n");
	for(i = 0; i < drink_numbers; i++)
	{
		printf("%s\t\t%d\n", drink[i].name, drink[i].sold);
	}
	printf("销售总额为：%.1f\n", total_sales);
}

/* 2---查询剩余库存 */
void QueryRepertory()
{
	int i;
	printf("名称\t\t剩余库存\n");
	for(i = 0; i < drink_numbers; i++)
	{
		printf("%s\t\t%d\n", drink[i].name, drink[i].repertory);
	}
}

/* 3---补货 */
void Replenishment()
{
	int i;
	int temp;

	printf("请在各饮料名称后面输入补充的数量：\n");
	for(i = 0; i < drink_numbers; i++)
	{
		printf("%s：", drink[i].name);
		scanf("%d", &temp);
		drink[i].repertory += temp;
	}
}

/* 4---增加饮料种类 */
void AddDrink()
{
	int i;

	printf("请按照提示输入如下信息，当你不想录入的时候，在填写名称的地方填写*\n");
	for (i = drink_numbers; ; i++)
	{
		printf("请录入饮料的名称：\n");
		scanf("%s", drink[i].name);
		if (strcmp(drink[i].name, "*") == 0)	//输入的与*对比，如果输入是*，则退出输入
		{
			printf("增加成功!\n");
			break;
		}
		printf("请录入该饮料的单价：\n");
		scanf("%f", &drink[i].price);
		printf("请录入该饮料的库存：\n");
		scanf("%d", &drink[i].repertory);
		
		drink[i].sold = 0;

		drink_numbers++;
	}
}

/* 5---查询饮料信息 */
int FindDrink()
{
 	int i, flag = 0;
 	char a[20];
 	printf("请输入您需要查询的饮料名称\n");
 	scanf("%s", a);
 	for (i = 0; i < drink_numbers; i++)
 	{
 		if (strcmp(a, drink[i].name) == 0)
 		{
 			printf("已找到该饮料，信息如下：\n");
 			PrintHeader();
 			PrintOneDrink(i);
 			return i;
 		}
 	}

 	printf("未找到该饮料信息！\n");
 	return -1;
}

/* 6---修改饮料信息 */   
void ChangeDrink()
{
	int choose;
	char temp[5];
	int pos;
	
	printf("请先找到需要修改的饮料：\n");
	pos = FindDrink();
	if(pos != -1)
	{
		printf("是否确定修改（是：y 否：n）: ");
		scanf("%s", temp);
		if(strcmp(temp, "y") == 0)
		{
			while(1)
			{
				printf("请输入需要修改的内容编号：\n");
			 	printf("1.名称\n");
			 	printf("2.单价\n");
			 	printf("3.库存\n");
			 	printf("4.已销售量\n");
			 	printf("0.退出修改，返回主菜单\n");
	
			 	scanf("%d", &choose);
	
			 	if(choose == 0)
			 	{
			 		break;
			 	}
	
			 	switch(choose)
			 	{
			 		case 1:
			 			printf("请输入新的名称：\n");
			 			scanf("%s", drink[pos].name);
			 			break;
			 		case 2:
			 			printf("请输入新的单价：\n");
			 			scanf("%f", &drink[pos].price);
			 			break;
			 		case 3:
			 			printf("请输入新的库存：\n");
			 			scanf("%d", &drink[pos].repertory);
			 			break;
			 		case 4:
			 			printf("请输入新的已销售量：\n");
			 			scanf("%d", &drink[pos].sold);
			 			break;
			 		default:
			 			printf("输入错误！\n");
			 			break;
			 	}
				printf("\n修改成功!\n");
			} 
		}
		else
		{
			printf("\n取消修改成功！\n");
			return;
		}
	}
	printf("请按任意键继续！\n");
	getchar();
}

/* 7---显示所有饮料信息 */   
void DisplayDrink()
{
	int i;

	PrintHeader();
	for(i = 0; i < drink_numbers; i++)
	{
		PrintOneDrink(i);
		if((i + 1) % 10 == 0)
		{
			printf("请输入任意键翻页！\n");
			getchar();
			system("cls");
			PrintHeader();
		}
	}
}

/* 8---删除饮料 */        
void DeleteDrink()
{
	int i, pos;
	char temp[5];

	printf("请先查找到需要删除的饮料：\n");
	pos = FindDrink();

	if(pos != -1)
	{
		printf("是否确定注销（是：y 否：n）: ");
		scanf("%s", temp);
		if(strcmp(temp, "y") == 0)
		{
			for(i = pos; i < drink_numbers; i++)
			{
				drink[i] = drink[i + 1];
			}
			drink_numbers--;
			printf("\n注销成功!\n");
		}
		else
		{
			printf("\n取消注销成功！\n");
			return;
		}
	}
}

/* 从文件导入饮料信息 */        
void InputDrinkFromFile()
{
	
	char temp[100];

	FILE *fp;

	fp = fopen("drink.txt", "rb");
	
	if(fp == NULL)
	{
		printf("文件打开失败，请检查文件是否存在！\n");
		return;
	}
	else
	{
		fgets(temp, 100, fp);
		while(fscanf(fp, "%s%f%d%d", drink[drink_numbers].name, &drink[drink_numbers].price, &drink[drink_numbers].repertory, &drink[drink_numbers].sold) == 4)
		{
			drink_numbers++;
		}
	
		printf("成功导入 %d 个饮料信息！\n", drink_numbers);
		fclose(fp);
	}
}

/* 导出饮料信息到文件 */      
void SaveDrinkToFile()
{
	int i;

	FILE *fp;

	fp = fopen("drink.txt", "w");

	fprintf(fp, "姓名\t单价\t库存\t已销售量\n");
	for (i = 0; i < drink_numbers; i++)
	{
		fprintf(fp, "%s\t%.1f\t%d\t%d\n", drink[i].name, drink[i].price, drink[i].repertory, drink[i].sold);
	}

	fclose(fp); 
	printf("数据保存成功！\n");
}

