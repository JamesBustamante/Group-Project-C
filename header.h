/* Our Header File that contains the our library of function prototypes */

/********************************/
/* Encryption/Decipher - RSA    */
/********************************/

/*Check whether a given number is prime or not*/
int checkPrime(int n)

/*to find gcd*/
int gcd(int a, int h)

void Encrypt();

void Decrypt();

int getPublicKeys();

int getPrivateKeys();

/************************************************/
/* Compression/Decompress - Run Length Encoding */
/************************************************/
struct struct_t 
{
	struct struct_t *left, *right;
	int frequency;
	char character;
};

typedef struct struct_t *node;

/* Function Prototype */

void printMenu(void);
void useMenu(int* plistSize, user_t* puserlist);
void userdetails(int* plistSize, user_t* puserlist);
void displayPersonaldetails(int* plistSize, user_t* puserlist);
void exitProgram();


void displayMenu(void);
void userLogin(void);
void adminLogin(void);
void createUser(void);
void defaultMessage(void);
void pencrypt(int username,char password[20]);
void pdecrypt(int username,char password[20]);


/* function prototype for compression */


void printmenu(void);
node createnode(int frequency, char character, node a, node b);
void createqueue();
node cancelqueue();
void codebuilding();
void initiatecode();
void compress();
void decompress();
void savelist(int* plistSize, student_t* pstudentlist);
/*char readlist(int* plistSize, student_t* pstudentlist);
Not used due to time restraints*/
void quit(void);


/* global variables for compression */


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
            case 3 : createuser();break;
            case 4 : exit(0);break;
          default: printf("Invalid choice.\n");        
      }
       
  }
	
	return 0;
}


void displayMenu(void){   
    printf("\n\n******Welcome to UTS******\n");
    printf("Please make an appropriate selection from the below menu:\n");
    printf("1. Student login\n");
    printf("2. Admin login\n");
    printf("3. Create new user login\n");
    printf("4. Exit\n");
    printf("**Please note there are limited features available**\n");
    printf("Enter choice:");
}

void userLogin(void){ 
	/* TODO */
	int listSize = 0;             /*counts the number of students on the enrollment list*/
	int* plistSize = &listSize;

	student_t studentlist [MAX_ENROLMENT_SIZE]; /*the list is stored as an array of struct type student*/
	student_t* pstudentlist = studentlist;

    int username;
    char password[20];
    printf("Enter studentID: ");
    scanf("%d",&username);
    printf("Enter password: ");
    scanf("%s",password);

    printf("You are now logged in and will be taken to the student menu.\n" 
    		"To view an example of encryption please create a new student login.\n\n");

	useMenu(plistSize, pstudentlist);
}

void adminLogin(void){  
    int username;
    char password[20];
    printf("Enter adminID: ");
    scanf("%d",&username);
    printf("Enter password: ");
    scanf("%s",password);
    
    printf("You are now logged in and will be taken to the admin menu.\n" 
    		"To view an example of encryption please create a new student login.\n\n");

   adminMenu();
}

void createUser(void){  
    int i =0;

    login_t loginlist[100];

    printf("\nEnter new studends ID: ");

    scanf("%d",&loginlist[i].username);

    printf("Enter new password: ");

    scanf("%s",loginlist[i].password);

    pencrypt(loginlist[i].username,loginlist[i].password);

    pdecrypt(loginlist[i].username,loginlist[i].password);

    printf("New User with username %d has been added\n\n\n",loginlist[i].username);
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
/* To compress the given input */
void Compress(const char *s, char *out)
{

	while (*s) 
	{
		strcpy(out, createdcode[(unsigned char)*s]);

		out += strlen(createdcode[(unsigned char)*s++]);
	}

}

/* To reverse/decompress */ 
void Decompress(const char *s, node t)
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

/********************************/
/* Data Structure - Linked List */ 
/********************************/
struct node{ /* Setup struct for linked list */
    char* title;
    char* username;
    char* password;
    struct node *next;
};
typedef struct node *head;

/* Insert log in details into the linked list */
void insertDetails(char* title, char* username, char* password);

/* Print out the entire linked list */
void print(); 

/* Reads input from the user to add to linked list */
char* readWord();

/********************************/
/* Sorting - Merge Sort         */
/********************************/

/* Determines whether the first node is ahead of the second, alphabetically by node title. */
/* Returns 1 if 'node1' is first, -1 if 'node2' is first, 0 if nodes have the same title.  */
int alphabeticalOrder(struct node* node1, struct node* node2);

/* Merge Sort main function, recursively calls itself to sort a provided linkedlist. */
void mergeSortMain(struct node** headReference);

/* Merge Sort split function, finds the mid point of an array and splits it into two. */
void mergeSortSplit(struct node* list, struct node** frontPtr, struct node** backPtr);

/* Merge Sort merge function, orders elements alphabetically and merges them. */
struct node* mergeSortMerge(struct node* node1, struct node* node2);

/*************************************/
/* Reading & Writing to files - Menu */
/*************************************/
void printMenu(void);
