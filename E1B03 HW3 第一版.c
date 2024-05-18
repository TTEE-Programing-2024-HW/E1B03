#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> 

#define row 9
#define col 9


void startseats(char seats[row][col]);
void mainmenu();
void displayseats(char seats[row][col]);
void canuseseats(char seats[row][col]);
void arrangeseats(char seats[row][col]);
int main()
{
	char choice;

	srand(time(0));
	
	// 顯示程序開始的畫面
	printf("*********************************************************\n");
	printf("*****              **********   ********         ********\n");
	printf("*****  ********************  *  ********  *******  ******\n");
	printf("*****  *******************  **  ********  ********  *****\n");
	printf("*****  ******************  ***  ********  *********  ****\n");
	printf("*****  ***********************  ********  **********  ***\n");
	printf("*****              ***********  ********            *****\n");
	printf("*****  ***********************  ********  ***************\n");
	printf("*****  ***********************  ********  **********  ***\n");
	printf("*****  ***********************  ********  *********  ****\n");
	printf("*****  ***********************  ********  ********  *****\n");
	printf("*****              *******          ****          *******\n");
	printf("*********************************************************\n");
	printf("*********************************************************\n");
	printf("*****              *********             ****************\n");
	printf("*****  **********  ********************  ****************\n");
	printf("*****  **********  ********************  ****************\n");
	printf("*****  **********  ********************  ****************\n");
	printf("*****  **********  ********************  ****************\n");
	printf("*****  **********  *********             ****************\n");
	printf("*****  **********  ********************  *****************\n");
	printf("*****  **********  ********************  ****************\n");
	printf("*****  **********  ********************  *****************\n");
	printf("*****  **********  ********************  ****************\n");
	printf("*****              *********             ****************\n");
	printf("*********************************************************\n");
	
	// 輸入密碼 
	while(a<3)
	{
		printf("請輸入 4 個數字的密碼:");
		scanf("%d",&n);
		if(n==password)
		{
			break;
		}
		else
		{
			a++;
			printf("密碼錯誤，剩下%d次機會\n",3-a);
		}
	}
	if(a==3)
	{
		printf("錯誤次數超過3次，程序退出\n");
		return 0;
	}
	char seats[row][col];
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<row;++j)
			seats[i][j]='-'//將未佔位座位標記為- 
	}
	startseats(seats);
	
	do
	{
		system("cls");
		mainmenu();
		choice=getchar();
		getchar();
		
		switch(choice)
		{
			case 'a':
				canuseseats(seats);
				break;
			case 'b':
				
				break;
			case 'c':
				
				break;
			case 'd':
				
				break;
			default:
				printf("無效選擇，請重新輸入\n");
	
		}
		
	}
	while(1);
	
	return 0;
}
//隨機生成初始座位 
void startseats(char seats[row][col])
{
	int bookcount=0;
	while(bookcount<10)
	{
		int row=rand() % row;
		int col=rand() % col;
		if(seats[row][col]=='-')
		{
			seats[row][col]='*'
			bookcount++;
		}
	}
		
}
//顯示主選單 
void mainmenu()
{
	printf("----------[Booking System]----------\n");
	printf("|    a. Available seats            |\n");
	printf("|    b. Arrange for you            |\n");
	printf("|    c. Choose by yourself         |\n");
	printf("|    d. Exit                       |\n");
	printf("------------------------------------\n");
	printf("請輸入你的選擇:")
}
//顯示座位表 
void displayseats(char seats[row][col])
{
	printf("123456789\n");
	for(int i=0;i<row;i++)
	{
		printf("%d".row-1);
		for(int j=0;j<col;j++)
			printf("%c",seats[i][j]);
			printf("\n");
	}
}
//處理現有座位 
void canuseseats(char seats[row][col])
{
	system("cls");
	displayseats(seats);
	printf("按任意鍵返回主選單\n");
	getchar();
}
//自動安排座位 
void arrangeseats(char seats[row][col])
{
	system("cls");
	int needseat;
	printf("你需要幾個座位（1~4）?\n");
	scanf("%d",&needseat);
	getchar();
	if(needseat<1||needseat>4)
	{
		printf("無效座位數\n");
		return;
	}
}
