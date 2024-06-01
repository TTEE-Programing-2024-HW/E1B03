#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> 

#define ROW 9
#define COL 9


void startseats(char seats[ROW][COL]);
void mainmenu();
void displayseats(char seats[ROW][COL]);
void canuseseats(char seats[ROW][COL]);
void arrangeseats(char seats[ROW][COL]);
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
	char seats[ROW][COL];
	for(int i=0;i<ROW;++i)
	{
		for(int j=0;j<ROW;++j)
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
void startseats(char seats[ROW][COL])
{
	int bookcount=0;
	while(bookcount<10)
	{
		int row=rand() % ROW;
		int col=rand() % COL;
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
void displayseats(char seats[ROW][COL])
{
	printf("123456789\n");
	for(int i=0;i<ROW;i++)
	{
		printf("%d".ROW-1);
		for(int j=0;j<COL;j++)
			printf("%c",seats[i][j]);
			printf("\n");
	}
}
//處理現有座位 
void canuseseats(char seats[ROW][COL])
{
	system("cls");
	displayseats(seats);
	printf("按任意鍵返回主選單\n");
	getchar();
}
//自動安排座位 
void arrangeseats(char seats[ROW][COL])
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
	int suggest[4][2];
	int found=0;
	for(int row=0;row<ROW&&!found;++row)
	{
		for(int col=0;col<=COL-needseat&&!found;++col)
		{
			int available=1;
			for(int k;k<needseat;++k)
			{
				if(seats[ROW][COL+k]!='-')
				{
					available=0;
					break;
				}
			}
			if(available)
			{
				for(int k=0;k<needseat;++k)
				{
					suggest[k][0]=row;
					suggest[k][1]=col+k;
				}
				found=1;
			}
		}
	}
	if(!found&&needseat==4)
	{
		for(int row=0;row<R0W-1&&!found;++row)
		{
			for(int col=0;col<COL&&!found;++col)
			{
				if(seats[row][col]=='-'&&seats[row+1][col]=='-'&&seats[row][col+1]=='-'&&seats[row+1][col+1]=='-')
				{
					suggest[0][0]=row;
					suggest[0][1]=col;
					suggest[1][0]=row;
					suggest[1][1]=col+1;
					suggest[2][0]=row+1;
					suggest[2][1]=col;
					suggest[3][0]=row+1;
					suggest[3][1]=col+1;
					found =1;
				}
			}
		}
	}
	if(!found)
	{
		printf("沒有適合的座位。返回主選單\n");
		return;
	}
	char temseats[ROW][COL];
	
	
}
