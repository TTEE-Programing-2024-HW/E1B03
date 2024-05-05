#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// 函數聲明
void tri(char ch); // 畫出直角三角形的函數
void nin(int num); // 顯示乘法表的函數

int main (void)
{
	// 定義變量
	int password=2024,n,a=0,t,num;
	char abc,con,ch;
	
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
	
	do{
		system("cls");
		// 顯示主選單 
		printf("*********************************************************\n");
		printf("******                   主選單                    ******\n");
		printf("*********************************************************\n");
		printf("*                    a. 畫出直角三角形                  *\n");
		printf("*                    b. 顯示乘法表                      *\n");
		printf("*                    c. 結束                            *\n");
		printf("*********************************************************\n");
		printf("\n");
		// 輸入選項 
		printf("輸入一個選項:\n");
		scanf(" %c",&abc);
		printf("按下任意鍵繼續\n");
		getch();
		 
		switch (abc)
		{
			case 'A':
			case 'a':
				{
					system("cls");
					while (1)
					{
						printf("請輸入一個'a'到'n'的字元:");
						scanf(" %c",&ch);
						if(ch<'a'||ch>'n')
						{
							printf("輸入錯誤，請輸入'a'到'n'的字元\n");
							printf("按下任意鍵繼續\n");
						}
						else
						{
							tri(ch); // 執行畫直角三角形的函數
							break;
						}
						
					}
					
					break;
				}
			case 'B':
			case 'b':
				{
					system("cls");
					while (1)
					{
						printf("請輸入一個1~9的整數:\n");
						scanf("%d",&t);
						if(t<1||t>9)
						{
							printf("輸入錯誤，請輸入一個1~9的整數:\n");
							printf("按下任意鍵繼續\n");
						}
						else
						{
							nin(t); // 執行顯示乘法表的函數
							break;

						}
		
					}
					
					break;
				
				}
			case 'C':
			case 'c':
				{
					system("cls");
					printf("Continue? (y/n)\n");
					scanf("%c",&con);
					while (con!='y'&&con!='Y'&&con!='n'&&con!='N')
					{
						
						scanf(" %c",&con);
					}
					if(con=='n'||con=='N')
						return 0;
					else
						break;
				
				}
			default:
				printf("輸入錯誤，請重新輸入選項:");
				scanf(" %c",&abc);
				
				
		}
	}while (1);	
	return 0;
 } 
 
 void tri(char ch)
 {
 	int x=1,y=1;
 	for (char x = 'a'; x <= ch; x++) 
	 {
    	for (char y = 'a'; y <= x; y++) 
		{
        	printf("%c ", y);
    	}
    printf("\n");
 	}
 	printf("按下任意鍵繼續\n");
 	getch();
 }

 void nin(int num)
 {
 	int i=1,j=1;
 	while(i<=num)
 	{
 		while(j<=num)
 		{
 			printf("%d*%d=%2d",i,j,i*j);
 			j++;
		 }
		 printf("\n");
		 i++;
		 j=1;
	}
	printf("按下任意鍵繼續\n");
 	getch();
 }
 //剛開始做這個作業的時候我遇到很多困難，例如:我不知道怎麼上傳檔案所以一開始編譯的都沒有上傳還有明明修改過了，
 //但編譯的時候卻跳出沒修改的結果，重新開一個檔案把程式碼複製過去就可以，讓我不思其解；而且這次的程式比以前打
 //得還要大跟多，所以我在打的時候常常不小心漏打符號，括號也分不清楚哪個是哪個的，所以我花了很多時間來搞定這個
 //東西，希望之後再打程式的時候我可以細心一點，和學到更多東西使用在程式中，讓我用更少的程式達成一樣的目的。 
