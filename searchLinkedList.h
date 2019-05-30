/* FUNCTION PROTOTYPES */
void searchTitle (struct node** headReference, char* target);
void searchUsername (struct node** headReference, char* target);
void binarySearchTitle(struct node **headRef, char* target);
void binarySearchUsername(struct node **headRef, char* target); 

/* Searches for the first element in the list whos title contains */
/*    the search text.                                            */
/* Prints the node with the title that matches the target text.   */
/* Prints an error if there is no match.                          */
void searchTitle (struct node** headReference, char* target){
	struct node* currNode = *headReference;
	
	/* Base case (empty list). */
	if(currNode == NULL){
		printf("\n"
	       	       "List is empty\n");;
	} 
	
	/* Iterate through list. */
	while (currNode->next == NULL){
		/* Strstr looks for substring target in string node->title. */
		/* If there's a match, print the node that matches.         */
		if(strstr(currNode->title, target) != NULL ){
			printf("%s\n", currNode->title);
           		printf("%s\n", currNode->username);
            		printf("%s\n", currNode->password);
		}
		/* If there's no match, move to the next node. */
		currNode = currNode->next;
	}
	/* If there were no matches in the whole list, print an error message. */
	printf("\n"
	       "Target not found\n");
}

/* Searches for the first element in the list whos username contains */
/*    the search text.                                               */
/* Prints the node with the title that matches the target text.      */
/* Prints null if no match.                                          */
void searchUsername (struct node** headReference, char* target){
	struct node* currNode = *headReference;
	
	/* Base case (empty list). */
	if(currNode == NULL){
		printf("\n"
	               "List is empty\n");
	} 
	
	/* Iterate through list. */
	while (currNode->next == NULL){
		/* Strstr looks for substring target in string node->title. */
		/* If there's a match, print the node that matches.         */
		if(strstr(currNode->username, target) != NULL ){
			printf("%s\n", currNode->title);
           		printf("%s\n", currNode->username);
            		printf("%s\n", currNode->password);
		}
		/* If there's no match, move to the next node. */
		currNode = currNode->next;
	}
	/* If there were no matches in the whole list, print an error message. */
	printf("\n"
	       "Target not found\n");
}

/* Performs a binary search to find a node based on its title.   */
/* ALWAYS SORT LIST BEFORE USING THIS FUNCTION OR IT WON'T WORK! */
void binarySearchTitle(struct node **headRef, char* target) { 
    /* Define some start values. */
	struct node* startNode = *headRef; 
    struct node* lastNode = NULL;
	struct node* middleNode;
	struct node* fastIndex;		
	
	while(startNode != lastNode){
		/* (re)Set our list iterators. */
		middleNode = startNode;
		fastIndex = startNode->next;
		
		/* Until the fastIndex hits the end of the list... */
		while(fastIndex != lastNode){
			/* Increment fastIndex. */
			fastIndex = fastIndex->next;
			if(fastIndex != lastNode){
				/* Then, if valid, increment it again. */
				fastIndex = fastIndex->next;
				/* And also increment middleNode.      */
				middleNode = middleNode->next;

				/* This means fastIndex moves twice every time we increment middleNode. */
				/* By the time middleNodee reaches halfway, fastIndex will hit the end  */
				/*   of the list. This means the middleIndex is approximately halfway   */
				/*   through the list.                                                  */
			}
		}
		
		/* Now middleNode is our halfway node, we can compare the data.              */
		/* If the middle value contains the target as a substring, print that node.  */
		if (strstr(middleNode->title, target) != NULL ){
			printf("%s\n", middleNode->title);
           		printf("%s\n", middleNode->username);
            		printf("%s\n", middleNode->password);
		}
		/* Else, if the middle node is alphabetically after the target, perform */
		/*   a binary search on the first half of the linkedList.               */
		else if(strcmp(middleNode->title, target) < 0){
			lastNode = middleNode;
		}
		/* Else, if the middle node is alphabetically before the target, perform */
		/*   a binary search on the second half of the linkedList.               */
		else if(strcmp(middleNode->title, target) > 0){
			startNode = middleNode->next;
		}
    }
	/* If the Binary Search has made the same node First and Last, that means it */
	/*   could not find the target in the list, therefore print an error message.*/
	printf("\n"
	       "Target not found\n");
}

/* Performs a binary search to find a node based on its usename. */
/* ALWAYS SORT LIST BEFORE USING THIS FUNCTION OR IT WON'T WORK! */
void binarySearchUsername(struct node **headRef, char* target) { 
    /* Define some start values. */
	struct node* startNode = *headRef; 
    struct node* lastNode = NULL;
	struct node* middleNode;
	struct node* fastIndex;		
	
	while(startNode != lastNode){
		/* (re)Set our list iterators. */
		middleNode = startNode;
		fastIndex = startNode->next;
		
		/* Until the fastIndex hits the end of the list... */
		while(fastIndex != lastNode){
			/* Increment fastIndex. */
			fastIndex = fastIndex->next;
			if(fastIndex != lastNode){
				/* Then, if valid, increment it again. */
				fastIndex = fastIndex->next;
				/* And also increment middleNode.      */
				middleNode = middleNode->next;

				/* This means fastIndex moves twice every time we increment middleNode. */
				/* By the time middleNodee reaches halfway, fastIndex will hit the end  */
				/*   of the list. This means the middleIndex is approximately halfway   */
				/*   through the list.                                                  */
			}
		}
		
		/* Now middleNode is our halfway node, we can compare the data.              */
		/* If the middle value contains the target as a substring, print that node.  */
		if (strstr(middleNode->username, target) != NULL ){
			printf("%s\n", middleNode->title);
           		printf("%s\n", middleNode->username);
            		printf("%s\n", middleNode->password);
		}
		/* Else, if the middle node is alphabetically after the target, perform */
		/*   a binary search on the first half of the linkedList.               */
		else if(strcmp(middleNode->username, target) < 0){
			lastNode = middleNode;
		}
		/* Else, if the middle node is alphabetically before the target, perform */
		/*   a binary search on the second half of the linkedList.               */
		else if(strcmp(middleNode->username, target) > 0){
			startNode = middleNode->next;
		}
    }
	/* If the Binary Search has made the same node First and Last, that means it */
	/*   could not find the target in the list, therefore print an error message.*/
	printf("\n"
	       "Target not found\n");
}  
