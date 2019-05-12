/* Our Header File that contains the our library of function prototypes */

/********************************/
/* Encryption/Decipher - RSA    */
/********************************/

void Encrypt();

void Decrypt();

int getPublicKeys();

int getPrivateKeys();

/************************************************/
/* Compression/Decompress - Run Length Encoding */
/************************************************/

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
