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

node createnode(int frequency, char character, node a, node b);
void createqueue();
node cancelqueue();
void codebuilding();

struct struct_t symbol[256] = {{0}};

node num[255], *q = num - 1;

int numnodes = 0;

int finishqueue = 1;

char *createdcode[128] = {0};

char buffer[1024];

/* To compress the given input */
void Compress ();

/* To reverse/decompress */ 
void Decompress ();

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
