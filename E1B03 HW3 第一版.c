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
	char seats[row][col];
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<row;++j)
			seats[i][j]='-'//�N������y��аO��- 
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
				printf("�L�Ŀ�ܡA�Э��s��J\n");
	
		}
		
	}
	while(1);
	
	return 0;
}
//�H���ͦ���l�y�� 
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
//��ܥD��� 
void mainmenu()
{
	printf("----------[Booking System]----------\n");
	printf("|    a. Available seats            |\n");
	printf("|    b. Arrange for you            |\n");
	printf("|    c. Choose by yourself         |\n");
	printf("|    d. Exit                       |\n");
	printf("------------------------------------\n");
	printf("�п�J�A�����:")
}
//��ܮy��� 
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
//�B�z�{���y�� 
void canuseseats(char seats[row][col])
{
	system("cls");
	displayseats(seats);
	printf("�����N���^�D���\n");
	getchar();
}
//�۰ʦw�Ʈy�� 
void arrangeseats(char seats[row][col])
{
	system("cls");
	int needseat;
	printf("�A�ݭn�X�Ӯy��]1~4�^?\n");
	scanf("%d",&needseat);
	getchar();
	if(needseat<1||needseat>4)
	{
		printf("�L�Įy���\n");
		return;
	}
}
