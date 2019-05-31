#define _GNU_SOURCE
#define DB_NAME "database"
#include <stdio.h>  /* printf, scanf */
#include <string.h> /* strcpy, strcmp, strlen, strcat */
#include <stdlib.h> /* malloc */
#include <math.h>
#include "RSA.h"
double sqroot(double square);
double sqroot(double square)
{
    double root = square / 3;
    int i;
    if (square <= 0)
        return 0;
    for (i = 0; i < 32; i++)
        root = (root + square / root) / 2;
    return root;
}


int prime(long int pr)
{
    int i;
    j = sqroot(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}
#include "header.h"
#include "mergeSort.h"

#include "searchLinkedList.h"
int main()
{
    	x = 3;
	flag = prime(x);

	y = 7;
	flag = prime(y);
    /* calculation of the modulus (n) and totient (t) */
		n = x*y;
		t = (x-1)*(y-1);
        char newstring[200] = "";
        strcpy(msg, newstring);

        for (i = 0; msg[i] != '\0'; i++)
		m[i] = msg[i];
        /* generation of encryption keys */
            encryption_key();
			encrypt();
			decrypt();

    struct node *head = NULL;

    selection(&head);
    return 0;
}

/* Insert log in details into the linked list */
void insertDetailsDECRYPT(struct node **node, int *title, char *username, char *password)
{
    /*creates the node with the contents of the struct to add to the linked list */
    struct node *insertNode = (struct node *)malloc(sizeof(struct node));
    char carray[sizeof(*title)];

    memcpy(title, carray, sizeof(*title));
    insertNode->title = carray; /*adds in the contents based upon what was passed in*/
    insertNode->username = username;
    insertNode->password = password;

    insertNode->next = (*node);
    /*append node to the create linked list that already exists*/
    (*node) = insertNode;
}

/* Insert log in details into the linked list */
void insertDetails(struct node **node, char *title, char *username, char *password)
{
    /*creates the node with the contents of the struct to add to the linked list */
    struct node *insertNode = (struct node *)malloc(sizeof(struct node));
    insertNode->title = title; /*adds in the contents based upon what was passed in*/
    insertNode->username = username;
    insertNode->password = password;

    insertNode->next = (*node);
    /*append node to the create linked list that already exists*/
    (*node) = insertNode;
}

/* Insert log in details into the linked list */
struct node **insert(struct node **node, char *title, char *username, char *password)
{
    /*creates the node with the contents of the struct to add to the linked list */
    struct node *insertNode = (struct node *)malloc(sizeof(struct node));
    insertNode->title = title; /*adds in the contents based upon what was passed in*/
    insertNode->username = username;
    insertNode->password = password;

    insertNode->next = (*node);
    /*append node to the create linked list that already exists*/
    (*node) = insertNode;
    return node; /*return the node that was created and apppended to the list*/
}

/* Insert log in details into the linked list based upon the user input */
struct node **insertDetailsInput(struct node **node)
{
    /*creates the node with the contents of the struct to add to the linked list */
    struct node *insertNode = (struct node *)malloc(sizeof(struct node));
    /*defines variables to store user input*/
    char *title = malloc(200);
    char *username = malloc(200);
    char *password = malloc(200);
    printf("Enter title login details:");
    scanf("%s", title);
    printf("Enter username:");
    scanf("%s", username);
    printf("Enter password:");
    scanf("%s", password);
    insertNode->title = title; /*adds in the contents based upon what was passed in*/
    insertNode->username = username;
    insertNode->password = password;

    /*append node to the create linked list that already exists*/
    insertNode->next = (*node);

    (*node) = insertNode;
    return node; /* Return the given node*/
}

/* Print out the entire linked list including all of its contents */
void print(struct node *node)
{
    int count = 0;
    /*iterates through each node in the linked list and prints out its contents */
    while (node != NULL)
    {
        printf("%d\n", ++count);
        printf("%s\n", node->title);
        printf("%s\n", node->username);
        printf("%s\n", node->password);
        node = node->next; /*goes to the next part of the list*/
    }
    /*exits the loop when the next node pointinng to is NULL*/
}

/* Save the contents of a linked list*/
void saveLinkedList(struct node *node)
{
    FILE *fp;
    fp = fopen(DB_NAME, "w"); /*open the database for writing*/
    if (fp != NULL)           /*checks whether file can be read or not*/
    {
        /*stores the contents of each node in the linked list, outputed to a database file*/
        int count = 0;
        while (node != NULL)
        {
            fprintf(fp, "%d\n", ++count);  
            fprintf(fp, "%s\n", node->title);
            fprintf(fp, "%s\n", node->username);
            char* newstring =  node->password;
        strcpy(msg, newstring);

        for (i = 0; msg[i] != '\0'; i++)
		m[i] = msg[i];

            encryption_key();
			encrypt();
			/*decrypt();*/
            /*strcpy(newstring, msg);*/
            for(i = 0; en[i] != -1; i++)
		fprintf(fp,"%c", en[i]);
            fprintf(fp, "\n");
            node = node->next; /* goes to the next node */
        }
        fclose(fp); /*close the file*/
    }
}
/* used to ask whether user wants add to the linked list or not */
struct node **tempMenu(struct node **node)
{
    while (1)
    {
        char *exite = malloc(200);
        printf("Add another listing? (Y/N)");
        scanf("%s", exite);
        if (*exite == 'n') /* exits back to the menu if the user doesn't want to add to the list*/
            return node;
        insertDetailsInput(node); /* else it'll prompt the user to add in new details*/
    }
}

/* Load the contents into linked list from the database*/
void LoadContentsInLinkedList(struct node **node)
{
    /* this first section empties out the linked list*/
    /* this essentially resets the data structure */
    struct node *current = *node;
    struct node *temp;
    while (current != NULL)
    {
        /* it goes through each node in the current list and frees some memory for it*/
        temp = current;
        current = current->next;
        free(temp); /* free the memory (the node) till reaches the head*/
    }
    *node = NULL;
    /*First clear current linked list above */
    FILE *myfile = fopen(DB_NAME, "r");
    int ch, number_of_lines = 0;
    do
    {   /* goes through each line of the file and counts how many lines it hase been through */
        ch = fgetc(myfile);
        if (ch == '\n') /*notifies that there's a next line */
            number_of_lines++;
    } while (ch != EOF);
    if (ch != '\n' && number_of_lines != 0) /*increase at the start of the file if empty*/
        number_of_lines++;
    fclose(myfile);
    /*find number of lines in the file we're trying to load above */

    /* Now we reopen the file for reading and placing the contents onto the linked list*/
    FILE *fp;
    fp = fopen(DB_NAME, "r");
    int count = 0;     /*open the database for writing*/
    int stepCount = 0; /*number time the while loop has been gone through*/

    if (fp != NULL) /*checks whether file can be read or not*/
    {
        /* it keeps reading thorugh the file while there is still contents to be read*/
        while (number_of_lines - 2 > stepCount * 4)
        {
            /* give some memory to store the contents of the file as we iterate*/
            char *title = malloc(200);
            char *username = malloc(200);
            char *password = malloc(200);
            stepCount++; /* increase the amount of steps we've made*/
            fscanf(fp, "%d\n%s\n%s\n%s\n", &count, title, username, password); /* scan an entire entry*/
            char* dnewstring =  password;
        strcpy(msg, dnewstring);

        printf("%s",msg);
        for (i = 0; msg[i] != '\0'; i++) {
		    m[i] = msg[i];
        }

            /*encryption_key();*/
			/*encrypt();*/
			decrypt();
            /*strcpy(newstring, msg);*/
            /*printf("%c\n",*m);*/
            insertDetails(node, title, username, password); /* insert those details into linked list*/
            title = ""; 
            username = "";
            password = "";
            /* reset the memory to empty */
        }
        fclose(fp); /*close the file*/
    }
}
/* This function prints the initial menu with all instructions on how to use */
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

void print_search_sort(struct node **node)
{
    char *selection = malloc(10);
    char *target = malloc(32);
    printf("\n"
           "1. Sort by title\n"
           "2. Sort by username\n"
           "3. Search by title\n"
           "4. Search by username\n"
           "5. View entire Linked List\n"
           "Enter number between 1-5\n");
    scanf(" %s", selection);
    int repeat = 1;
    while (repeat == 1)
    {
        switch (*selection)
        {
        case '1':
            mergeSortMainTitle(node);
            repeat = 0;
            break;
        case '2':
            mergeSortMainUsername(node);
            repeat = 0;
            break;
        case '3':
            printf("\n"
                   "Enter title to search for\n");
            scanf(" %s", target);
            binarySearchTitle(node, target);
            repeat = 0;
            break;
        case '4':
            printf("\n"
                   "Enter username to search for\n");
            scanf(" %s", target);
            binarySearchUsername(node, target);
            repeat = 0;
            break;
        case '5':
            printf("\n"
                   "Heres the entire list\n");
            print(*node);
            repeat = 0;
            break;
        default:
            printf("Invalid choice\n");
            repeat = 0;
            break;
        }
    }
}
/* menu select for the user */
void selection(struct node **node)
{
    char *selection = malloc(10);
    while (1) /*condition is true*/
    {
        print_menu();
        scanf(" %s", selection);
        switch (*selection)
        {
        case '1':
            tempMenu(node); /* add to the linked list*/
            break;
        case '2':
            LoadContentsInLinkedList(node); /* load the database into the linked list */
            break;
        case '3':
            print_search_sort(node); /* goes to the menu to sort, search or view */
            break;
        case '4':
            saveLinkedList(*node); /* save contents of linked list to database file */
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
