#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxstudent 10


void owndisplay();//個人化頁面 
int password();//輸入密碼 
void clearscreen();//清除螢幕 
void mainmenu();//顯示住畫面 
void entergrades();//選項a,輸入學生成績 
void displdygrades();//選項b,顯示學生成績
void searchgrades();//選項c,搜尋學生成績
void graderanking();//選項d,成績排名
void existsystem();//選項e,退出程式

struct student
{
	char name[50];
	int id;
	int math;
	int physics;
	int english;
	float avg;
};

struct student students[maxstudent];
int studentcount=0;

int main()
{
	owndisplay();
	if(!password())
		return 0;
		
	char choice;
	while(1)
	{
		mainmenu();
		printf("請選擇一個選項: ");
		scanf(" %c", &choice);
	
		switch(choice)
		{
			case 'a':
				entergrades();
				break;
			case 'b':
				displdygrades();
				break;
			case 'c':
				searchgrades();
				break;
			case 'd':
				graderanking();
				break;
			case 'e':
				existsystem();
				break;

			default:
				printf("無效的選擇，請重新輸入\n");
				break;
		}
	}
	return 0;
}
void owndisplay()
{
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
    printf("*****  **********  ********************  ****************\n");
    printf("*****  **********  ********************  ****************\n");
    printf("*****  **********  ********************  ****************\n");
    printf("*****  **********  ********************  ****************\n");
    printf("*****              *********             ****************\n");
    printf("*********************************************************\n");
}

int password()
{
	int a=0,input,key=2024;
	while(a<3)
	{
		printf("請輸入密碼:\n");
		scanf("%d",&input);
		if(input==key)
		{
			return 1;
		}
		else
		{
			a++;
			printf("密碼錯誤，剩下%d次機會\n",3-a);
		}
	}
	printf("連續錯誤三次，程式結束\n");
	return 0;
}

void clearscreen()
{
	system("cls");
}

void mainmenu()
{
	clearscreen();
	printf("------------[Grade System]----------\n");
    printf("|  a. Enter student grades          |\n");
    printf("|  b. Display student grades        |\n");
    printf("|  c. Search for student grades     |\n");
    printf("|  d. Grade ranking                 |\n");
    printf("|  e. Exit system                   |\n");
    printf("------------------------------------\n");
} 

void entergrades()
{
	int n,i;
	clearscreen();
	printf("輸入學生數量(5~10):\n");
	scanf("%d",&n);
	if(n<5||n>10)
	{
		printf("請重新輸入:\n");
		return;
	}
	for(i=0;i<n;i++)
	{
		printf("輸入學生姓名、學號、數學成績、物理成績、英文成績:");
		scanf("%s %d %d %d %d", students[studentcount].name,&students[studentcount].id,&students[studentcount].math,&students[studentcount].physics,&students[studentcount].english);
	
        
        if(students[studentcount].math<0||students[studentcount].math>100||students[studentcount].physics<0||students[studentcount].physics>100||students[studentcount].english<0||students[studentcount].english>100)
		{
			printf("請重新輸入:\n");
			i--;
			continue;
		}
		students[studentcount].avg=(students[studentcount].math +students[studentcount].physics +students[studentcount].english) / 3.0;
		studentcount++;
	}
	printf("學生成績輸入完畢!\n");
}

void displdygrades()
{
	int i;
	clearscreen();
	printf("學生成績:\n");
	printf("姓名  學號  數學  物理  英文  平均  \n");
	for(i=0;i<studentcount;i++)
	{
		printf("%s  %d  %d  %d  %d  %f  \n",students[i].name,students[i].id,students[i].math,students[i].physics,students[i].english,students[i].avg);
		printf("\n");
	} 
	printf("按下任意鍵以返回主選單\n");
	getchar();
	getchar();
}

void searchgrades()
{
	clearscreen();
	int f=0,i;
	char searchname[50];
	printf("輸入要搜索的姓名:\n");
	scanf("%s",searchname);
	
	for(i=0;i<studentcount;i++)
	{
		if(strcmp(students[i].name,searchname)==0)
		{
			printf("姓名  學號  數學  物理  英文  平均  \n");
			printf("%s  %d  %d  %d  %d  %f  \n",students[i].name,students[i].id,students[i].math,students[i].physics,students[i].english,students[i].avg);
			printf("\n");
			f=1;
			break;
		}
	}
	if(!f)
	{
		printf("資料不存在\n");
	}
	printf("按下任意鍵以返回主選單\n");
	getchar();
	getchar();
}

void graderanking()
{
	clearscreen();
	int i,j;
	struct student t;
	for(i=0;i<studentcount-1;i++)
	{
		for(j=0;j<studentcount-i-1;j++)
		{
			if(students[j].avg<students[j+1].avg)
			{
				t=students[j];
				students[j]=students[j+1];
				students[j+1]=t;
			}
		}
	}
	printf("學生排名如下:\n");
	printf("姓名  學號  數學  物理  英文  平均  \n");
	for(i=0;i<studentcount;i++)
	{
		printf("%s  %d  %f  \n",students[i].name,students[i].id,students[i].avg);
		printf("\n");
	}
}

void existsystem()
{
	char choice;
	while(1)
	{
		printf("確定離開?(y/n)\n");
		scanf("%c",&choice);
		if(choice=='y'||choice=='Y')
		{
			exit(0);
		}
		else if(choice=='n'||choice=='N')
		{
			return;
		}
		else
		{
			printf("無效選項，請重新輸入\n");
		}
	}
} 
