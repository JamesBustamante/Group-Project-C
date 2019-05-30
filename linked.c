#define _GNU_SOURCE
#include <stdio.h>  /* printf, scanf */
#include <string.h> /* strcpy, strcmp, strlen, strcat */
#include <stdlib.h> /* malloc */
#include <math.h>
#include "header.h"
#include "mergeSort.h"
#define DB_NAME "database"

int main()
{
    struct node *head = NULL;
    
    selection(&head);
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

void print_search_sort(struct node **node){
	char *selection = malloc(10);
	char *target = malloc(32);
	printf("\n"
		   "1. Sort by title\n"
		   "2. Sort by username\n"
		   "3. Search by title\n"
		   "4. Search by username\n"
		   "Enter number between 1-4\n");
	scanf(" %s", selection);
	while(1){
		switch(*selection){
			case '1':
				mergeSortMainTitle(node);
				break;
			case '2':
				mergeSortMainUsername(node);
				break;
			case '3':
				printf("\n"
					   "Enter title to search for\n");
				scanf(" %s", target);
				searchTitle(node, target);
				break;
			case '4':
				printf("\n"
					   "Enter username to search for\n");
				scanf(" %s", target);
				searchUsername(node, target);
				break;
			default: 
				printf("Invalid choice\n");
				break;
		}
	}
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
            print_search_sort();
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
