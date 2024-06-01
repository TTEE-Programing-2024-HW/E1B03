#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxstudent 10


void owndisplay();//�ӤH�ƭ��� 
int password();//��J�K�X 
void clearscreen();//�M���ù� 
void mainmenu();//��ܦ�e�� 
void entergrades();//�ﶵa,��J�ǥͦ��Z 
void displdygrades();//�ﶵb,��ܾǥͦ��Z
void searchgrades();//�ﶵc,�j�M�ǥͦ��Z
void graderanking();//�ﶵd,���Z�ƦW
void existsystem();//�ﶵe,�h�X�{��

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
		printf("�п�ܤ@�ӿﶵ: ");
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
				printf("�L�Ī���ܡA�Э��s��J\n");
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
		printf("�п�J�K�X:\n");
		scanf("%d",&input);
		if(input==key)
		{
			return 1;
		}
		else
		{
			a++;
			printf("�K�X���~�A�ѤU%d�����|\n",3-a);
		}
	}
	printf("�s����~�T���A�{������\n");
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
	printf("��J�ǥͼƶq(5~10):\n");
	scanf("%d",&n);
	if(n<5||n>10)
	{
		printf("�Э��s��J:\n");
		return;
	}
	for(i=0;i<n;i++)
	{
		printf("��J�ǥͩm�W�B�Ǹ��B�ƾǦ��Z�B���z���Z�B�^�妨�Z:");
		scanf("%s %d %d %d %d", students[studentcount].name,&students[studentcount].id,&students[studentcount].math,&students[studentcount].physics,&students[studentcount].english);
	
        
        if(students[studentcount].math<0||students[studentcount].math>100||students[studentcount].physics<0||students[studentcount].physics>100||students[studentcount].english<0||students[studentcount].english>100)
		{
			printf("�Э��s��J:\n");
			i--;
			continue;
		}
		students[studentcount].avg=(students[studentcount].math +students[studentcount].physics +students[studentcount].english) / 3.0;
		studentcount++;
	}
	printf("�ǥͦ��Z��J����!\n");
}

void displdygrades()
{
	int i;
	clearscreen();
	printf("�ǥͦ��Z:\n");
	printf("�m�W  �Ǹ�  �ƾ�  ���z  �^��  ����  \n");
	for(i=0;i<studentcount;i++)
	{
		printf("%s  %d  %d  %d  %d  %f  \n",students[i].name,students[i].id,students[i].math,students[i].physics,students[i].english,students[i].avg);
		printf("\n");
	} 
	printf("���U���N��H��^�D���\n");
	getchar();
	getchar();
}

void searchgrades()
{
	clearscreen();
	int f=0,i;
	char searchname[50];
	printf("��J�n�j�����m�W:\n");
	scanf("%s",searchname);
	
	for(i=0;i<studentcount;i++)
	{
		if(strcmp(students[i].name,searchname)==0)
		{
			printf("�m�W  �Ǹ�  �ƾ�  ���z  �^��  ����  \n");
			printf("%s  %d  %d  %d  %d  %f  \n",students[i].name,students[i].id,students[i].math,students[i].physics,students[i].english,students[i].avg);
			printf("\n");
			f=1;
			break;
		}
	}
	if(!f)
	{
		printf("��Ƥ��s�b\n");
	}
	printf("���U���N��H��^�D���\n");
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
	printf("�ǥͱƦW�p�U:\n");
	printf("�m�W  �Ǹ�  �ƾ�  ���z  �^��  ����  \n");
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
		printf("�T�w���}?(y/n)\n");
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
			printf("�L�Ŀﶵ�A�Э��s��J\n");
		}
	}
} 
