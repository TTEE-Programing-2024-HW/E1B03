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
	
	// ��ܵ{�Ƕ}�l���e��
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
	
	// ��J�K�X 
	while(a<3)
	{
		printf("�п�J 4 �ӼƦr���K�X:");
		scanf("%d",&n);
		if(n==password)
		{
			break;
		}
		else
		{
			a++;
			printf("�K�X���~�A�ѤU%d�����|\n",3-a);
		}
	}
	if(a==3)
	{
		printf("���~���ƶW�L3���A�{�ǰh�X\n");
		return 0;
	}
	char seats[ROW][COL];
	int i,j;
	for(i=0;i<ROW;++i)
	{
		for(j=0;j<COL;++j)
			seats[i][j]='-';//�N������y��аO��- 
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
				printf("�L�Ŀ�ܡA�Э��s��J\n");
	
		}
		
	}
	while(1);
	
	return 0;
}
//�H���ͦ���l�y�� 
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
//��ܥD��� 
void mainmenu()
{
	printf("----------[Booking System]----------------------\n");
	printf("|    a. Available seats     (�i�ήy��)         |\n");
	printf("|    b. Arrange for you     (�۰ʿ��)         |\n");
	printf("|    c. Choose by yourself  (��ʿ��)         |\n");
	printf("|    d. Exit                (���})             |\n");
	printf("------------------------------------------------\n");
	printf("�п�J�A�����:");
}
//��ܮy��� 
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
//�B�z�{���y�� 
void canuseseats(char seats[ROW][COL])
{
	system("cls");
	displayseats(seats);
	printf("��Enter��^�D���\n");
	getchar();
}
//�۰ʦw�Ʈy�� 
void arrangeseats(char seats[ROW][COL])
{
	system("cls");
	int needseat;
	printf("�A�ݭn�X�Ӯy��]1~4�^?\n");
	scanf("%d",&needseat);
	clearinput();
	if(needseat<1||needseat>4)
	{
		printf("�L�Įy���\n");
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
		printf("�S���A�X���y��\n");
		printf("��Enter��^�D���\n");
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
	printf("�нT�{�o�Ǯy��(y/n):");
	char confirm=getchar();
	getchar();
	clearinput();
	
	if(confirm=='y'||confirm=='Y')
	{
		markseat(seats,suggest,needseat);
		printf("�w�w���\!");
		printf("\n");
	}
	else
	{
		printf("���w�w���\�C");
		printf("\n");
	}
	printf("��Enter��^�D���");
	getchar();
}
void chooseseat(char seats[ROW][COL])
{
	system("cls");
	displayseats(seats);
	int row,col;
	printf("�п�J�y�쪺���C�A�Ҧp 1-2�B 2-9 �N��[�C 1,�� 2]��[�C 2,�� 9]��Ӯy��");
	scanf("%d-%d",&row,&col);
	clearinput();
	
	row=row-1;
	col=col-1;
	if(row<0||row>=ROW||col<0||col>=COL||seats[row][col]!='-')
	{
		printf("�L�Ī��y��ήy��w�Q����");
		printf("\n");
	}
	else
	{
		seats[row][col]='*';
		printf("�w�w���\!");
		printf("\n");
		displayseats(seats);
	}
	
	printf("��Enter��^�D��� \n");
	getchar();
}
int confirmexit()
{
	printf("�A�T�w�n�h�X��?(y/n):");
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
