/* Searches for the first element in the list whos title contains */
/*    the search text.                                            */
/* Returns the node with the title that matches the target text.  */
/* Returns nullptr if no match.                                   */
struct node searchTitle (struct node** headReference, char[] target){
	struct node* currNode = *headReference;
	
	/* Base case (empty list). */
	if(currNode == NULL){
		return null;
	} 
	
	/* Iterate through list. */
	while (currNode->next == NULL){
		/* Strstr looks for substring target in string node->title. */
		/* If there's a match, return the node that matches.        */
		if(strstr(currNode->title, target) != nullptr ){
			return currNode;
		}
		/* If there's no match, move to the next node. */
		currNode = currNode->next;
	}
	/* If there were no matches in the whole list, return a nullptr. */
	return nullptr;
}

/* Searches for the first element in the list whos username contains */
/*    the search text.                                               */
/* Returns the node with the title that matches the target text.     */
/* Returns nullptr if no match.                                      */
struct node searchUsername (struct_node** headReference, char[] target){
	struct node* currNode = *headReference;
	
	/* Base case (empty list). */
	if(currNode == NULL){
		return null;
	} 
	
	/* Iterate through list. */
	while (currNode->next == NULL){
		/* Strstr looks for substring target in string node->title. */
		/* If there's a match, return the node that matches.        */
		if(strstr(currNode->username, target) != nullptr ){
			return currNode;
		}
		/* If there's no match, move to the next node. */
		currNode = currNode->next;
	}
	/* If there were no matches in the whole list, return a nullptr. */
	return nullptr;
}

/* Performs a binary search to find a node based on its title.   */
/* ALWAYS SORT LIST BEFORE USING THIS FUNCTION OR IT WON'T WORK! */
struct node binarySearchTitle(struct node **headRef, char[] target) { 
    /* Define some start values. */
	struct node* startNode = *headRef; 
    struct node* lastNode = NULL;
	struct node* middleNode;
	struct node* fastIndex;		
	
	while(firstNode != lastNode){
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
		/* If the middle value contains the target as a substring, return that node. */
		if (strstr(middleNode->title, target) != nullptr ){
			return middleNode;
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
	/*   could not find the target in the list, therefore return nullptr.        */
	return nullptr;
}

/* Performs a binary search to find a node based on its usename. */
/* ALWAYS SORT LIST BEFORE USING THIS FUNCTION OR IT WON'T WORK! */
struct node binarySearchUsername(struct node **headRef, char[] target) { 
    /* Define some start values. */
	struct node* startNode = *headRef; 
    struct node* lastNode = NULL;
	struct node* middleNode;
	struct node* fastIndex;		
	
	while(firstNode != lastNode){
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
		/* If the middle value contains the target as a substring, return that node. */
		if (strstr(middleNode->username, target) != nullptr ){
			return middleNode;
		}
		/* Else, if the middle node is alphabetically after the target, perform */
		/*   a binary search on the first half of the linkedList.               */
		else if(strcmp(middleNode->user, target) < 0){
			lastNode = middleNode;
		}
		/* Else, if the middle node is alphabetically before the target, perform */
		/*   a binary search on the second half of the linkedList.               */
		else if(strcmp(middleNode->user, target) > 0){
			startNode = middleNode->next;
		}
    }
	/* If the Binary Search has made the same node First and Last, that means it */
	/*   could not find the target in the list, therefore return nullptr.        */
	return nullptr;
}  
