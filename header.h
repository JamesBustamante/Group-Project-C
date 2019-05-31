
/* Our Header File that contains the our library of function prototypes */

/********************************/
/* Encryption/Decipher - RSA    */
/********************************/

/*Check whether a given number is prime or not*/
int checkPrime(int n);

/*to find gcd*/
int gcd(int a, int h);

void Encrypt();

void Decrypt();

int getPublicKeys();

int getPrivateKeys();

/************************************************/
/* Compression/Decompress - Run Length Encoding */
/************************************************/

/* To compress the given input */
void Compress ();

/* To reverse/decompress */ 
void Decompress ();

/********************************/
/* Data Structure - Linked List (JAMES BUSTAMANTE -12900926) */
/********************************/
struct node
{ /* Setup struct for linked list */
    char *title;
    char *username;
    char *password;
    struct node *next;
};

/*typedef struct node *head;*/

/* the read linked list section of the menu where you can search or sort or view */
void print_search_sort(struct node **node);

/* Insert log in details into the linked list */
void insertDetails(struct node **, char *title, char *username, char *password);

struct node ** insert(struct node **node, char *title, char *username, char *password);

/* Insert log in details into the linked list */
struct node ** insertDetailsInput(struct node **);

/* Print out the entire linked list */
void print(struct node *node);

/* Save the contents of a linked list*/
void saveLinkedList(struct node *node);

/* Load the contents into linked list*/
void LoadContentsInLinkedList(struct node **node);

/* Reads input from the user to add to linked list */
char *readWord();

/* used to ask whether user wants add to the linked list or not */
struct node ** tempMenu(struct node **node);

/* menu select for the user */
void selection(struct node **node);

/* This function prints the initial menu with all instructions on how to use */
void print_menu(void);
/********************************/
/* Sorting - Merge Sort         */
/********************************/
/* Determines whether the first node is ahead of the second, alphabetically by node title. */
/* Returns 1 if 'node1' is first, -1 if 'node2' is first, 0 if nodes have the same title.  */
int alphabeticalOrderTitle(struct node* node1, struct node* node2);

/* Merge Sort main function, recursively calls itself to sort a provided linkedlist. */
void mergeSortMainTitle(struct node** headReference);

/* Merge Sort split function, finds the mid point of an array and splits it into two. */
void mergeSortSplitTitle(struct node* list, struct node** frontPtr, struct node** backPtr);

/* Merge Sort merge function, orders elements alphabetically and merges them. */
struct node* mergeSortMergeTitle(struct node* node1, struct node* node2);

int alphabeticalOrderUsername(struct node* node1, struct node* node2);

/* Merge Sort main function, recursively calls itself to sort a provided linkedlist. */
void mergeSortMainUsername(struct node** headReference);

/* Merge Sort split function, finds the mid point of an array and splits it into two. */
void mergeSortSplitUsername(struct node* list, struct node** frontPtr, struct node** backPtr);

/* Merge Sort merge function, orders elements alphabetically and merges them. */
struct node* mergeSortMergeUsername(struct node* node1, struct node* node2);

/* FUNCTION PROTOTYPES */
void searchTitle (struct node** headReference, char* target);
void searchUsername (struct node** headReference, char* target);
void binarySearchTitle(struct node **headRef, char* target);
void binarySearchUsername(struct node **headRef, char* target); 

/*************************************/
/* Reading & Writing to files - Menu */
/*************************************/
void printMenu(void);
