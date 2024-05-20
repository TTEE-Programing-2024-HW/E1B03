#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> 

#define ROW 9
#define COL 9

//Function prototypes
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
	
	// Display the initial program screen
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
	
	// Prompt user to enter password
	while(a<3)
	{
		printf("Please enter the 4-digit password:");
		scanf("%d",&n);
		if(n==password)
		{
			break;// Exit loop if password is correct
		}
		else
		{
			a++;
			printf("Incorrect password,%d attempts remaining\n",3-a);
		}
	}
	if(a==3)
	{
		printf("Exceeded maximum attempts, program exiting\n");
		return 0;// Exit program after 3 failed attempts
	}
	//Initialize seats
	char seats[ROW][COL];
	int i,j;
	for(i=0;i<ROW;++i)
	{
		for(j=0;j<COL;++j)
			seats[i][j]='-';//Mark nuoccupied seats as'-'
	}
	startseats(seats);// Generate initial booked seats
	
	//Main loop
	do
	{
		system("cls");// Clear the screen (may not work on all systems)
		mainmenu();// Display the main menu
		choice=getchar();
		getchar();//Consume the newline character
		clearinput();// Clear any remaining input
		
		switch(choice)
		{
			case 'a':
				canuseseats(seats);// Display available seats
				break;
			case 'b':
				arrangeseats(seats);// Automatically arrange seats
				break;
			case 'c':
				chooseseat(seats);// Manually choose a seat
				break;
			case 'd':
				if (confirmexit())
				{
					return 0;// Exit the program if confirmed
				}
				break;
			default:
				printf("Invalid choice, please try again\n");
	
		}
		
	}
	while(1);
	
	return 0;
}
//Randomly generate initial seats 
void startseats(char seats[ROW][COL])
{
	int bookcount=0;
	while(bookcount<10)
	{
		int row=rand() % ROW;
		int col=rand() % COL;
		if(seats[row][col]=='-')
		{
			seats[row][col]='*';// Mark seat as booked ('*')
			bookcount++;
		}
	}
		
}
//Dispiay main menu 
void mainmenu()
{
	printf("----------[Booking System]----------------------\n");
	printf("|    a. Available seats     (可用座位)         |\n");
	printf("|    b. Arrange for you     (自動選位)         |\n");
	printf("|    c. Choose by yourself  (手動選位)         |\n");
	printf("|    d. Exit                (離開)             |\n");
	printf("------------------------------------------------\n");
	printf("Please enter your choice:");
}
//Dispiay seats 
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
//Handle available seats 
void canuseseats(char seats[ROW][COL])
{
	system("cls");// Clear the screen (may not work on all systems)
	displayseats(seats);// Display the current seating chart
	printf("Press Enter to return to main menu\n");
	getchar();// Wait for user to press Enter
}
//Automatically arrange seats 
void arrangeseats(char seats[ROW][COL])
{
	system("cls");// Clear the screen (may not work on all systems)
	int needseat;
	printf("How many seats do you need（1~4）?\n");
	scanf("%d",&needseat);
	clearinput();// Clear any remaining input
	if(needseat<1||needseat>4)
	{
		printf("Invalid number of seats\n");
		return;
	}
	int suggest[4][2];// Array to store suggested seat positions
	int found=0;// Flag to indicate if suitable seats are found
	int row,col,k;
	// Search for consecutive available seats in a row
	for(row=0;row<ROW&&!found;++row)
	{
		for(col=0;col<=COL-needseat&&!found;++col)
		{
			int available=1;// Flag to check if seats are available
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
	// If 4 seats are needed and not found in a row, search in a 2x2 block
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
		printf("No suitable seats available\n");
		printf("Press Enter to return to main menu\n");
		getchar();// Wait for user to press Enter
		return;
	}
	char temseats[ROW][COL];// Temporary seating chart to display suggested seats
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
		temseats[suggest[i][0]][suggest[i][1]]='@';// Mark suggested seats with '@'
	}
	displayseats(temseats);// Display the seating chart with suggested seats
	printf("Please confirm these seats(y/n):");
	char confirm=getchar();
	getchar();
	clearinput();// Clear any remaining input
	
	if(confirm=='y'||confirm=='Y')
	{
		markseat(seats,suggest,needseat);// Mark the seats as booked
		printf("Booking successful!");
		printf("\n");
	}
	else
	{
		printf("Booking not successful.");
		printf("\n");
	}
	printf("Press Enter to return to main menu");
	getchar();// Wait for user to press Enter
}
//Manually choose a seat
void chooseseat(char seats[ROW][COL])
{
	system("cls");// Clear the screen (may not work on all systems)
	displayseats(seats);// Display the current seating chart
	int row,col;
	printf("Please enter the row and column of the seat,e.g., 1-2、 2-9 for[row 1,column 2]and[row 2,column 9]respectively\n");
	scanf("%d-%d",&row,&col);
	clearinput();// Clear any remaining input
	
	row=row-1;
	col=col-1;
	if(row<0||row>=ROW||col<0||col>=COL||seats[row][col]!='-')
	{
		printf("Invalid seat or seat already occupied\n");
		printf("\n");
	}
	else
	{
		seats[row][col]='*';/ Mark the seat as booked
		printf("Booking successful!");
		printf("\n");
		displayseats(seats);// Display the updated seating chart
	}
	
	printf("Press Enter to return to main menu \n");
	getchar();// Wait for user to press Enter
}
//Confirm exit
int confirmexit()
{
	printf("Are you sure you want to exit?(y/n):");
	char confirm=getchar();
	clearinput();// Clear any remaining input
	return (confirm=='y'||confirm=='Y');
}

//Mark seats as booked
void markseat(char seats[ROW][COL],int position[][2],int size)
{
	int i;
	for(i=0;i<size;++i)
	{
		seats[position[i][0]][position[i][1]]='*';// Mark the seat as booked
	}
}
//clear input butter
void clearinput()
{
	char ch;
	while((ch=getchar())!='\n'&&ch!=EOF);// Consume all characters until newline or EOF
}
//在打這次的作業的時候我打了很久，因為光是打函式就遇到了許多困難，
//所以我上網查了資料，重新改了很多次才成功執行，而且這次的程式需要
//打的程式很多還需要都用英文打，所以對我來說難度倍增，最終打出來可
//能還是有一些錯誤。 
