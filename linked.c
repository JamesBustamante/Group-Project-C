#define _GNU_SOURCE
#include <stdio.h>  /* printf, scanf */
#include <string.h> /* strcpy, strcmp, strlen, strcat */
#include <stdlib.h> /* malloc */
#include <math.h>
#include "header.h"
#define DB_NAME "database"

/* Determines whether the first node is ahead of the second, alphabetically by node title. */
/* Returns 1 if 'node1' is first, -1 if 'node2' is first, 0 if nodes have the same title.  */
int alphabeticalOrder(struct node* node1, struct node* node2);

/* Merge Sort main function, recursively calls itself to sort a provided linkedlist. */
void mergeSortMain(struct node** headReference);

/* Merge Sort split function, finds the mid point of an array and splits it into two. */
void mergeSortSplit(struct node* list, struct node** frontPtr, struct node** backPtr);

/* Merge Sort merge function, orders elements alphabetically and merges them. */
struct node* mergeSortMerge(struct node* node1, struct node* node2);

int alphabetOrder (struct node* a, struct node* b) {
	char* aString = a->title;
	char* bString = b->title;
	int y = 0;
	int j = 0;

	/* Incrememnt through both strings, setting them to all lowercase. */
	while (aString[y] != '\0') {
     	if (aString[y] >= 'A' && aString[y] <= 'Z') {
        	aString[y] = aString[y] + 32;
     	}
    	y++;
    }
    while (bString[j] != '\0'){
    	if (bString[j] >= 'A' && bString[j] <= 'Z') {
        	bString[j] = bString[j] + 32;
     	}
    	j++;
    }

	int i = 0;

	while(aString[i] != '\0' && bString[i] != '\0'){
		if((aString[i] < bString[i]) || (aString[i] == '\0' && bString[i] != '\0')) {
			/* First string is alphabetically first, so return 1. */
			return 1;
		}
		else if((aString[i] > bString[i]) || (aString[i] != '\0' && bString[i] == '\0')) {
			/* Second string is alphabetically first, so return 2. */
			return 2;
		}
		else{
			/* This character is identical, so increment to the next character. */
			i++;
		}
	}
	/* Both strings are identical, so return 0. */
	return 0;
}

void mergeSortMain(struct node** headReference){
	struct node* head = *headReference;
	struct node* firstHalf;
	struct node* lastHalf;

	/* Check the base case (list length 0 or 1). */
	if(head == NULL || head->next == NULL){
		return;
	}

	/* Split the list into two lists. */
	mergeSortSplit(head, &firstHalf, &lastHalf);

	/* Sort each half of the list recursively. */
	mergeSortMain(&firstHalf);
	mergeSortMain(&lastHalf);

	/* Merge the newly sorted lists. */
	*headReference = mergeSortMerge(firstHalf, lastHalf);

}

void mergeSortSplit(struct node* source, struct node** frontReference, struct node** backReference){
	struct node* fastIndex = source->next;
	struct node* slowIndex = source;

	/* Until the fastIndex hits the end of the list... */
	while(fastIndex != NULL){
		/* Increment fastIndex. */
		fastIndex = fastIndex->next;
		if(fastIndex != NULL){
			/* Then, if valid, increment it again. */
			fastIndex = fastIndex->next;
			/* And also increment slowIndex. */
			slowIndex = slowIndex->next;

			/* This means fastIndex moves twice every time slowIndex moves. */
			/* By the time slowIndex reaches halfway, fastIndex will hit    */
			/*   the end of the list. This makes slowIndex a halfway mark.  */
		}
	}
	/* Set the first half to directly reference the source of the list. */
	*frontReference = source;
	/* And the back half to start one after the midpoint of the list. */
	*backReference = slowIndex->next;
	/* Then split the list by removing the middle link. */
	slowIndex->next = NULL;
}

struct node* mergeSortMerge(struct node* a, struct node* b){
	struct node* result = NULL;

	/* Cover base cases. */
	if(a == NULL){
		return b;
	}
	if(b == NULL){
		return a;
	}

	/* Get the alphabet order int. */
	int alphabeticalOrder = alphabetOrder(a, b);

	/* If the first string comes first, add that. */
	if(alphabeticalOrder == 1){
		result = a;
		result-> next = mergeSortMerge(a->next, b);
	}
	else if (alphabeticalOrder == 2){
		result = b;
		result -> next = mergeSortMerge(a, b->next);
	}
	return result;

}


int main()
{
    struct node *head = NULL;
    /*
    struct node *insertNode = (struct node *)malloc(sizeof(struct node));
    insertNode->title = "title";
    insertNode->username = "username";
    insertNode->password = "password";

    insertNode->next = (head);

    (head) = insertNode;

    insertNode = (struct node *)malloc(sizeof(struct node));
    insertNode->title = "abba";
    insertNode->username = "username";
    insertNode->password = "password";

    insertNode->next = (head);

    (head) = insertNode;

    insertNode = (struct node *)malloc(sizeof(struct node));
    insertNode->title = "b";
    insertNode->username = "username";
    insertNode->password = "password";

    insertNode->next = (head);

    (head) = insertNode;*/
    /*
     insertDetails(&head, "Google Login", "John@gmail.com", "qwerty");
    insertDetails(&head, "Yahoo Login", "John@yahoo.com", "1234");
    insertDetails(&head, "apple Login", "testy.com", "rtr");*/

    selection(&head);
    
   

    /* tempMenu(&head);
    
    
    saveLinkedList(head); */
    
    return 0;
}


void insertDetails(struct node **node, char *title, char *username, char *password)
{
    struct node *insertNode = (struct node *)malloc(sizeof(struct node));
    insertNode->title = title;
    insertNode->username = username;
    insertNode->password = password;

    insertNode->next = (*node);

    (*node) = insertNode;
}

struct node ** insert(struct node **node, char *title, char *username, char *password)
{
    struct node *insertNode = (struct node *)malloc(sizeof(struct node));
    insertNode->title = title;
    insertNode->username = username;
    insertNode->password = password;

    insertNode->next = (*node);

    (*node) = insertNode;
    return node;
}

struct node ** insertDetailsInput(struct node **node){
    struct node *insertNode = (struct node *)malloc(sizeof(struct node));

        char *title = malloc(200);
        char *username = malloc(200);
        char *password = malloc(200);
        printf("Enter title login details:");
        scanf("%s", title);
        printf("Enter username:");
        scanf("%s", username);
        printf("Enter password:");
        scanf("%s", password);
        insertNode->title = title;
        insertNode->username = username;
        insertNode->password = password;


    insertNode->next = (*node);

    (*node) = insertNode;
    return node;
}

void print(struct node *node)
{
    int count = 0;
    while (node != NULL)
    {
        printf("%d", ++count);
        printf("%s\n", node->title);
        printf("%s\n", node->username);
        printf("%s\n", node->password);
        node = node->next;
    }
}

void saveLinkedList(struct node *node)
{
    FILE *fp;
    fp = fopen(DB_NAME, "w"); /*open the database for writing*/
    if (fp != NULL)           /*checks whether file can be read or not*/
    {
        int count = 0;
        while (node != NULL)
        {
            fprintf(fp, "%d\n", ++count);
            fprintf(fp, "%s\n", node->title);
            fprintf(fp, "%s\n", node->username);
            fprintf(fp, "%s\n", node->password);
            node = node->next;
        }
        fclose(fp); /*close the file*/
    }
}

struct node ** tempMenu(struct node **node) {
    while (1) {
        char* exite = malloc(200);
        printf("Add another listing? (Y/N)");
        scanf("%s", exite);
        if (*exite == 'n') 
            return node;
        insertDetailsInput(node);
    }
}

void LoadContentsInLinkedList(struct node **node){
    struct node *current = *node;
    struct node *temp;
    while(current != NULL)
    {
         temp = current;
         current = current->next;
         free(temp);
    }
    *node = NULL;
    /*First clear current linked list above */
        FILE* myfile = fopen(DB_NAME, "r");
    int ch, number_of_lines = 0;
    do
    {
    ch = fgetc(myfile);
    if(ch == '\n')
        number_of_lines++;
    }
    while (ch != EOF);
    if(ch != '\n' && number_of_lines != 0)
        number_of_lines++;
    fclose(myfile);
    /*find number of lines in the file we're trying to load above */

    /*printf("%d", number_of_lines);*/
    FILE *fp;
    fp = fopen(DB_NAME, "r");
    int count = 0; /*open the database for writing*/
    int stepCount = 0; /*number time the while loop has been gone through*/

    if (fp != NULL)           /*checks whether file can be read or not*/
    {
            
            while (number_of_lines-2 > stepCount*4)  {
                char *title = malloc(200);
            char *username = malloc(200);
            char *password = malloc(200);
                stepCount++;
                fscanf(fp, "%d\n%s\n%s\n%s\n", &count,title,username,password);
                /*
                printf("%d\n", count);
                printf("%s\n", title);
                printf("%s\n", username);
                printf("%s\n", password);*/
              
                 insertDetails(node,title,username,password);
                title = "";
                username = "";
                password = "";
            }
        fclose(fp); /*close the file*/
    }
}

void print_menu(void)
{
    printf("\n"
           "1. Enter a new account\n"
           "2. Read accounts from file\n"
           "3. View accounts in memory\n"
           "4. Encrypt accounts in memory\n"
           "5. Read encrypted file\n"
           "6. Exit\n"
           "Enter number between 1-6\n");
}

void selection(struct node **node){
    char *selection = malloc(10);
    /*
    struct node* insertNode = (struct node *)malloc(sizeof(struct node));
    insertNode->title = "b";
    insertNode->username = "username";
    insertNode->password = "password";
    insertNode->next = (*node);

    (*node) = insertNode;*/

    /*head = *insert(&head, "tr Login", "testy.com", "rtr");*/
    while (1) /*condition is true*/
    {
        print_menu();
        scanf(" %s", selection);
        switch (*selection)
        {
        case '1':
            tempMenu(node);
            break;
        case '2':
            LoadContentsInLinkedList(node);
            break;
        case '3':
            mergeSortMain(node);
            print(*node);
            break;
        case '4':
            saveLinkedList(*node);
            break;
        case '5':
            break;
        case '6':
            exit(0); /*terminates the program*/
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}