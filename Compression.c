#include <stdio.h>    /*printf, scanf definitions*/   
#include <stdlib.h>   
#include <string.h>


#define MAX_INPUT_SIZE 50            /*conversion constant*/

#define MAX_USER_SIZE 50  /**user name length**/ /*Conversion constant*/
#define MAX_LIST_SIZE 10 /* max number of user */
#define MAX_NAME_SIZE 50 /* max length of user name */  


#define DB_FILE_NAME "database"
#define TREE "treefile"

struct date 
{
    unsigned int day;   /*day is the integer that the user inputs 
                          (unsigned integer between 1 and 31)*/

    unsigned int month; /*month is the integer that the user inputs 
                          (unsigned integer between 1 and 12)*/

    unsigned int year;  /*year is the integer that the user inputs 
                          (unsigned integer between 1800 and 2017)*/
};
typedef struct date date_t; /*date_t is a structure typedef for struct date*/


struct user
{
    char name[MAX_NAME_SIZE]; /*data type char represents an individual 
                                character value*/
    date_t birthday;
    
};
typedef struct user user_t;


struct login{  
    int username;
    char password[20];
};

typedef struct login login_t;

/*******************************************************************************
Function prototypes
*******************************************************************************/

void printMenu(void);
void useMenu(int* plistSize, user_t* puserlist);
void userdetails(int* plistSize, user_t* puserlist);
void withdrawlastuser(int* plistSize, user_t* puserlist);
void displayPersonaldetails(int* plistSize, user_t* puserlist);
void exitProgram();



void displayMenu(void);
void userLogin(void);
void adminLogin(void);
void createUser(void);
void defaultMessage(void);
void pencrypt(int username,char password[20]);
void pdecrypt(int username,char password[20]);

/*******************************************************************************
Structs for compression
*******************************************************************************/


struct struct_t 
{
	struct struct_t *left, *right;
	int frequency;
	char character;
};

typedef struct struct_t *node;

/*******************************************************************************
Function prototypes for compression
*******************************************************************************/

void printmenu(void);
node createnode(int frequency, char character, node a, node b);
void createqueue();
node cancelqueue();
void codebuilding();
void initiatecode();
void compress();
void decompress();
void savelist(int* plistSize, user_t* puserlist);
/*char readlist(int* plistSize, user_t* puserlist);
Not used due to time restraints*/
void quit(void);
/*******************************************************************************
Global variables/infromation for Compression
*******************************************************************************/

struct struct_t symbol[256] = {{0}};

node num[255], *q = num - 1;

int numnodes = 0;

int finishqueue = 1;

char *createdcode[128] = {0};

char buffer[1024];




int main(void)     /*main function returns an integer value*/
{
	

 int choice;

    displayMenu();
    scanf("%d",&choice);
    while(choice != 4){
        switch(choice){
            case 1: userLogin();break;
            case 2 : adminLogin();break;
            case 3 : createUser();break;
            case 4 : exit(0);break;
          default: printf("Invalid choice.\n");        
      }
       
  }
	
	return 0;
}


void displayMenu(void){  
    printf("\n\n******Welcome to SECURITY WORLD******\n");
    printf("Please make an appropriate selection from the below menu:\n");
    printf("1. User login\n");
    printf("2. Admin login\n");
    printf("3. Create new user login\n");
    printf("4. Exit\n");
    printf("**Please note there are limited features available**\n");
    printf("Enter choice:");
}

void userLogin(void){  
	/* TODO */
	int listSize = 0;             /*counts the number of users on the  list*/
	int* plistSize = &listSize;

	user_t userlist [MAX_INPUT_SIZE]; /*the list is stored as an array of struct type user*/
	user_t* puserlist = userlist;

    int username;
    char password[20];
    printf("Enter userID: ");
    scanf("%d",&username);
    printf("Enter password: ");
    scanf("%s",password);

    printf("You are now logged in and will be taken to the user menu.\n" 
    		"To view an example of encryption please create a new user login.\n\n");

	useMenu(plistSize, puserlist);
}

void adminLogin(void){  
    int username;
    char password[20];
    printf("Enter adminID: ");
    scanf("%d",&username);
    printf("Enter password: ");
    scanf("%s",password);
    
    printf("You are now logged in and will be taken to the admin menu.\n" 
    		"To view an example of encryption please create a new user login.\n\n");

}

void createUser(void){  
    int i =0;

    login_t loginlist[100];

    printf("\nEnter new user ID: ");

    scanf("%d",&loginlist[i].username);

    printf("Enter new password: ");

    scanf("%s",loginlist[i].password);

    pencrypt(loginlist[i].username,loginlist[i].password);

    pdecrypt(loginlist[i].username,loginlist[i].password);

    printf("New user with username %d has been added\n\n\n",loginlist[i].username);
    i++;
    
}

void defaultMessage(void){  
    printf("Incorrect Input");
    displayMenu();
}

void pencrypt(int username,char password[20]){  
    int i;
    for(i=0;i<strlen(password);i++){
        password[i] = password[i] - username;
    }
    printf("The encrypted password is : %s\n",password);
}

void pdecrypt(int username,char password[20]){  
    int i ;
    for(i=0;i<strlen(password);i++){
        password[i] = password[i] + username;
    }
    printf("The decrypted password is : %s\n",password);
}


/*******************************************************************************
printMenu 
This function is used to print menu with all instructions on how to use this
program.
inputs:
- none
outputs:
- none
*******************************************************************************/
void printMenu(void)   
{
	printf("\n\n"       /*2 empty lines will be printed before the choice list*/
	    "1. Add in user details\n"
	    "2. Display personal details\n"
	    "3. Save user details\n"
	    "4. Read database\n"
	    "5. Quit\n"
	    "Enter your choice>");
}

/*******************************************************************************
useMenu  
This function displays the menu above so you can run a funtion by choosing an 
integer from 1-6.
inputs:
- int* plistSize, user_t* puserlist
outputs:
- none
*******************************************************************************/
void useMenu(int* plistSize, user_t* puserlist)
{
	int choice;
	do
	    {
	    printMenu();
	    scanf("%d", &choice); /*reads the users choice (integer from 1-4)*/

	switch (choice)
	    {
	    case 1:
            if (*plistSize < MAX_INPUT_SIZE) /*SECURITY WORLD can only have 50 users
             maximum*/
		    {
		    userdetails(plistSize, puserlist);
		    }
		    else
		    {
		    printf("Enrolment is full\n");    /*Can't have more than 50 users
		     enrolled at SECURITY WORLD*/
		    useMenu(plistSize, puserlist);
		    scanf("%d", &choice);         
		    /*reads the users choice (integer from 1-4)*/
		    break;
		    }
		    break;

	    case 2: 
            if (*plistSize <1)
		    {
		    printf("Enrolment is empty\n");   /*print this because a user 
		    can't be deleted from an empty list*/
		    useMenu(plistSize, puserlist);
		    scanf("%d", &choice);         
		    /*reads the users choice (integer from 1-4)*/
		    break;
		    }
		    else
		    {
		    withdrawlastuser
        (plistSize, puserlist);
		    break;
		    }
		    break;

	    case 3: 
            if (*plistSize <1)
		    {
		    printf("Enrolment is empty\n");   /*print this because a user
		     can't be deleted from an empty list*/
		    useMenu(plistSize, puserlist);
		    scanf("%d", &choice);         /*reads the users choice (integer
		     from 1-4)*/
		    break;
		    }
		    else
		    {
		    displayPersonaldetails(plistSize, puserlist);
		    break;
		    }
		    break;
		case 4:
		savelist(plistSize, puserlist);
		break;

		case 5:
		printf("Currently Not Available");
		/*readlist(plistSize, puserlist);*/
		break;

	    case 6: 
            exit(0);

	   default: printf("Invalid choice.");  /*this will be printed when an 
	   option out of the bounadaries is selected*/
		    useMenu(plistSize, puserlist);
		    scanf("%d", &choice);       /*reads the users choice (integer 
		    from 1-4)*/
		    break;
	    }
	}
	while (choice<1 || choice > 6); /*between 1 and 4 (inclusive)*/
	
	}
/*******************************************************************************
enrolUser
This function adds a new user to the list.
inputs:
- int* plistSize, user_t* puserlist
outputs:
- users
*******************************************************************************/
void userdetails (int* plistSize, user_t* puserlist)
{



    printf("Enter name>");
    scanf("%s", puserlist[*plistSize].name);

    unsigned int day;
    printf("Enter birthday: day>"); /*enter day of birth*/
    scanf("%d", &day);              /*placeholder for int variable type (day)*/
    while (day<1 || day >31)	    /*between 1 and 31 (inclusive)*/
    {
	printf("Invalid day. " "Enter birthday: day>"); /*display error for invalid input*/
	scanf("%d", &day);
    }
    puserlist[*plistSize].birthday.day = day;

    unsigned int month;
    printf("Enter birthday: month>");   /*enter month of birth*/
    scanf("%d", &month);                /*placeholder for int variable type (month)*/
    while (month<1 || month >12)	/*between 1 and 12*/
    {
	printf("Invalid month. " "Enter birthday: month>"); /*display error for invalid input*/
	scanf("%d", &month);
    }
    puserlist[*plistSize].birthday.month = month;

    unsigned int year;
    printf("Enter birthday: year>");    /*enter year of birth*/
    scanf("%d", &year);                 /*placeholder for int variable type (year)*/
    while (year<1800 || year >2017)	/*between 1800 and 2017*/
    {
	printf("Invalid year. " "Enter birthday: year>");  /*display error for invalid input*/
	scanf("%d", &year);                /*placeholder for int variable type (year)*/
    }
    puserlist[*plistSize].birthday.year = year;
	

   

 ++*plistSize;
    useMenu(plistSize, puserlist);


}


/*******************************************************************************
withdrawlastuser 
This function deletes the last user added to the list.
inputs:
- int* plistSize, user_t* puserlist
outputs:
- none
*******************************************************************************/
void withdrawlastuser (int* plistSize, user_t* puserlist)
{
    int c = *plistSize;
    if (c >0)
    {
        c--; /*can decrement*/
    }
    *plistSize = c;
    useMenu(plistSize, puserlist);
}

/*******************************************************************************
displayPersonaldetails  
This function displays the user list.
inputs:
- int* plistSize, user_t* puserlist
outputs:
- none
*******************************************************************************/
void displayPersonaldetails (int* plistSize, user_t* puserlist)
{
    int i, len, amount;


    printf("Name       Birthday   \n");
    printf("---------- ---------- \n"); /*displays list in this form*/

    for (i = 0; i < *plistSize; i++)
    {
    
    printf("%s",              puserlist[i].name);   /*prints the name*/

    {
    len = strlen(puserlist[i].name);  /*calculate white space*/
    amount = 11 - len;
    printf("%*s", amount, " ");
    }

    printf("%02d-%02d-%04d ", puserlist[i].birthday.day,    /*prints the day*/
                              puserlist[i].birthday.month,  /*prints the month*/
                              puserlist[i].birthday.year);  /*prints the year*/


    }

    useMenu(plistSize, puserlist);


}
/*******************************************************************************
savelist-
This function to save the user details to the database file, determined in
 by the DB_FILE_NAME.



*******************************************************************************/
void savelist()
{
	FILE *textp, *textq;
	char character[1000];
	
	textp=fopen(DB_FILE_NAME, "w");

	

 
    /*To show error when oppening database if it does not exist*/
			   if ((textp = fopen(DB_FILE_NAME, "r")) == NULL)
   				 {

        		 printf("No file exists\n");
    			}

    			fscanf(textp,"%[^/] ", character);

   				fclose(textp);

				const char *string = character;
        		char buffer[1024];
 				
 				/*used to start creating the required binary values*/
				initiatecode(string);
    			
    			/* compression begins*/
    			compress(string, buffer);

    			/* Used as a test save without rewining the current database
				textq=fopen(TESTFILE, "w");

				save the database as a compressed file*/
				textq=fopen(DB_FILE_NAME, "w");

				fprintf(textq,"%s", buffer);

				fclose(textq);
}

/*******************************************************************************
initiate code 
*******************************************************************************/
void initiatecode(const char *s)
{
	int i, frequency[128] = {0};

	char character[16];

	FILE *textq;
 
	while (*s) frequency[(int)*s++]++;
 
	for (i = 0; i < 128; i++)
		if (frequency[i]) createqueue(createnode(frequency[i], i, 0, 0));
 
	while (finishqueue > 2) 
		createqueue(createnode(0, 0, cancelqueue(), cancelqueue()));
 
	codebuilding(q[1], character, 0);

	int j;

	textq=fopen(TREE, "w");

				
				/*save the tree*/
				for (j = 0; j < 128; j++)
					if (createdcode[j])
				fprintf(textq, "'%c': %s", j, createdcode[j]);

				fclose(textq);

}

/*******************************************************************************
createnode 
*******************************************************************************/
node createnode(int frequency, char character, node a, node b)
{
	node n = symbol + numnodes++;
	
	if (frequency) n->character = character, n->frequency = frequency;
	
	else {
	
		n->left = a, n->right = b;
	
		n->frequency = a->frequency + b->frequency;
		}
	
	return n;
}
 
/*******************************************************************************
createqueue 
This will create the priority of the symbols/digits/characteres
*******************************************************************************/
void createqueue(node n)
{
	int j, i = finishqueue++;
		while ((j = i / 2)) {
		
			if (q[j]->frequency <= n->frequency) break;
		
			q[i] = q[j], i = j;
			
			}
	q[i] = n;
}
 
/*******************************************************************************
cancelqueue 
*******************************************************************************/
node cancelqueue()
{
	int i, l;
	node n = q[i = 1];
 
	if (finishqueue < 2) return 0;

	finishqueue--;

	while ((l = i * 2) < finishqueue) {

		if (l + 1 < finishqueue && q[l + 1]->frequency < q[l]->frequency) l++;

		q[i] = q[l], i = l;
	
		}
	
	q[i] = q[finishqueue];
	
	return n;
}
 
/*******************************************************************************
codebuilding 
Going down the tree to put 1s and 0s 
*******************************************************************************/
void codebuilding(node n, char *s, int len)
{
	static char *out = buffer;

	if (n->character) {

		s[len] = 0;

		strcpy(out, s);

		createdcode[(unsigned char)n->character] = out;

		out += len + 1;

		return;
	}
 
	s[len] = '0'; codebuilding(n->left,  s, len + 1);

	s[len] = '1'; codebuilding(n->right, s, len + 1);
}

/*******************************************************************************
Compress 
*******************************************************************************/
void compress(const char *s, char *out)
{

	while (*s) 
	{
		strcpy(out, createdcode[(unsigned char)*s]);

		out += strlen(createdcode[(unsigned char)*s++]);
	}

}

/*******************************************************************************
Decompress and save to file 
*******************************************************************************/
void decompress(const char *s, node t)
{
	FILE *textq;
	node n = t;

	/* Used as a test save without rewining the current database
	textq = fopen(TESTFILE2, "w");

	save the database as a decompressed file*/
	textq=fopen(DB_FILE_NAME, "w");

	
	while (*s) 
	{
		if (*s++ == '0') n = n->left;

		else n = n->right;
		if (n->character) fputc(n->character, textq), n = t;
 

	}
 
	putchar('\n');

	fclose(textq);

}

/*******************************************************************************
quit
This function exits the program.
*******************************************************************************/
void quit(void)
{
	/* Termination of the program*/
	exit(0);
}
