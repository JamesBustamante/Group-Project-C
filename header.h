/*Our Header File that contains the our library of function prototypes*/

/********************************/
/* Encryption/Decipher - RSA */
/********************************/

void Encrypt();

void Decrypt();

int getPublicKeys();

int getPrivateKeys();

/********************************/
/* Compression/Decompress - Run Length Encoding */
/********************************/

/********************************/
/* Data Structure - Linked List */ 
/********************************/
struct node{ /*Setup struct for linked list*/
    char* title;
    char* username;
    char* password;
    struct node *next;
};
typedef struct node *head;

/*Insert log in details into the linked list*/
void insertDetails(char* title, char* username, char* password);

/*Print out the entire linked list*/
void print(); 

/*Reads input from the user to add to linked list*/
char* readWord();

/********************************/
/* Sorting - Merge Sort */
/********************************/

/********************************/
/* Reading & Writing to files - Menu */
/********************************/