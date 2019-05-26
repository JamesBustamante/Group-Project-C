#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Determines whether the first node is ahead of the second, alphabetically by node title. */
/* Returns 1 if 'node1' is first, -1 if 'node2' is first, 0 if nodes have the same title.  */
int alphabeticalOrder(node_t* node1, node_t* node2);

/* Merge Sort main function, recursively calls itself to sort a provided linkedlist. */
void mergeSortMain(node_t** headReference);

/* Merge Sort split function, finds the mid point of an array and splits it into two. */
void mergeSortSplit(node_t* list, node_t** frontPtr, node_t** backPtr);

/* Merge Sort merge function, orders elements alphabetically and merges them. */
node_t* mergeSortMerge(node_t* node1, node_t* node2);

int alphabetOrder (node_t* a, node_t* b) {
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

void mergeSortMain(node_t** headReference){
	node_t* head = *headReference;
	node_t* firstHalf;
	node_t* lastHalf;

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

void mergeSortSplit(node_t* source, node_t** frontReference, node_t** backReference){
	node_t* fastIndex = source->next;
	node_t* slowIndex = source;

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

node_t* mergeSortMerge(node_t* a, node_t* b){
	node_t* result = NULL;

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

int main (void){
	node_t* node1 = malloc(sizeof(node_t));
	node1->title = "Google";
	node1->username = "test1";
	node1->password = "test1pass";

	node_t* node2 = malloc(sizeof(node_t));
	node2->title = "Facebook";
	node2->username = "test2";
	node2->password = "test2pass";

	node_t* node3 = malloc(sizeof(node_t));
	node3->title = "Whatever";
	node3->username = "test3";
	node3->password = "test3pass";

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printf("%s %s %s \n", node1->title, node1->username, node1->password);
	printf("%s %s %s \n", node2->title, node2->username, node2->password);

	/* mergeSortMain(&node1); */

	return 0;
}
