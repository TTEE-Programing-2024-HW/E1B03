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
void chooseseat(char seats[ROW][COL]);
int confirmexit();
void markseat(char seats[ROW][COL],int position[][2],int size);
void clearinput();
int main()
{
	char choice;
	int password=2024,n,a=0;
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
	int i,j;
	for(i=0;i<ROW;++i)
	{
		for(j=0;j<COL;++j)
			seats[i][j]='-';//將未佔位座位標記為- 
	}
	startseats(seats);
	
	do
	{
		system("cls");
		mainmenu();
		choice=getchar();
		getchar();
		clearinput();
		
		switch(choice)
		{
			case 'a':
				canuseseats(seats);
				break;
			case 'b':
				arrangeseats(seats);
				break;
			case 'c':
				chooseseat(seats);
				break;
			case 'd':
				if (confirmexit())
				{
					return 0;
				}
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
			seats[row][col]='*';
			bookcount++;
		}
	}
		
}
//顯示主選單 
void mainmenu()
{
	printf("----------[Booking System]----------------------\n");
	printf("|    a. Available seats     (可用座位)         |\n");
	printf("|    b. Arrange for you     (自動選位)         |\n");
	printf("|    c. Choose by yourself  (手動選位)         |\n");
	printf("|    d. Exit                (離開)             |\n");
	printf("------------------------------------------------\n");
	printf("請輸入你的選擇:");
}
//顯示座位表 
void displayseats(char seats[ROW][COL])
{
	printf("  123456789\n");
	int i,j;
	for(i=0;i<ROW;i++)
	{
		printf("%d",i+1);
		for(j=0;j<COL;j++)
			printf("%c",seats[i][j]);
		printf("\n");
	}
}
//處理現有座位 
void canuseseats(char seats[ROW][COL])
{
	system("cls");
	displayseats(seats);
	printf("按Enter返回主選單\n");
	getchar();
}
//自動安排座位 
void arrangeseats(char seats[ROW][COL])
{
	system("cls");
	int needseat;
	printf("你需要幾個座位（1~4）?\n");
	scanf("%d",&needseat);
	clearinput();
	if(needseat<1||needseat>4)
	{
		printf("無效座位數\n");
		return;
	}
	int suggest[4][2];
	int found=0;
	int row,col,k;
	for(row=0;row<ROW&&!found;++row)
	{
		for(col=0;col<=COL-needseat&&!found;++col)
		{
			int available=1;
			for(k=0;k<needseat;++k)
			{
				if(seats[row][col+k]!='-')
				{
					available=0;
					break;
				}
			}
			if(available)
			{
				for(k=0;k<needseat;++k)
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
		for(row=0;row<ROW-1&&!found;++row)
		{
			for(col=0;col<COL&&!found;++col)
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
		printf("沒有適合的座位\n");
		printf("按Enter返回主選單\n");
		getchar();
		return;
	}
	char temseats[ROW][COL];
	int i,j;
	for(i=0;i<ROW;++i)
	{
		for(j=0;j<COL;++j)
		{
			temseats[i][j]=seats[i][j];
		}
	}
	for(i=0;i<needseat;++i)
	{
		temseats[suggest[i][0]][suggest[i][1]]='@';
	}
	displayseats(temseats);
	printf("請確認這些座位(y/n):");
	char confirm=getchar();
	getchar();
	clearinput();
	
	if(confirm=='y'||confirm=='Y')
	{
		markseat(seats,suggest,needseat);
		printf("預定成功!");
		printf("\n");
	}
	else
	{
		printf("未預定成功。");
		printf("\n");
	}
	printf("按Enter返回主選單");
	getchar();
}
void chooseseat(char seats[ROW][COL])
{
	system("cls");
	displayseats(seats);
	int row,col;
	printf("請輸入座位的行跟列，例如 1-2、 2-9 代表[列 1,行 2]及[列 2,行 9]兩個座位");
	scanf("%d-%d",&row,&col);
	clearinput();
	
	row=row-1;
	col=col-1;
	if(row<0||row>=ROW||col<0||col>=COL||seats[row][col]!='-')
	{
		printf("無效的座位或座位已被佔用");
		printf("\n");
	}
	else
	{
		seats[row][col]='*';
		printf("預定成功!");
		printf("\n");
		displayseats(seats);
	}
	
	printf("按Enter返回主選單 \n");
	getchar();
}
int confirmexit()
{
	printf("你確定要退出嗎?(y/n):");
	char confirm=getchar();
	clearinput();
	return (confirm=='y'||confirm=='Y');
}
void markseat(char seats[ROW][COL],int position[][2],int size)
{
	int i;
	for(i=0;i<size;++i)
	{
		seats[position[i][0]][position[i][1]]='*';
	}
}

void clearinput()
{
	char ch;
	while((ch=getchar())!='\n'&&ch!=EOF);
}
