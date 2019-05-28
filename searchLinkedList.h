/* Searches for the first element in the list whos title contains */
/*    the search text.                                            */
/* Returns the node with the title that matches the target text.  */
/* Returns nullptr if no match.                                   */
struct node searchTitle (node_t** headReference, char[] target){
	(struct node)* node = *headReference;
	
	/* Base case (empty list). */
	if(node == NULL){
		return null;
	} 
	
	/* Iterate through list. */
	while (node->next == NULL){
		/* Strstr looks for substring target in string node->title. */
		/* If there's a match, return the node that matches.        */
		if(strstr(node->title, target) != nullptr ){
			return node;
		}
		/* If there's no match, move to the next node. */
		node = node->next;
	}
	/* If there were no matches in the whole list, return a nullptr. */
	return nullptr;
}

/* Searches for the first element in the list whos username contains */
/*    the search text.                                               */
/* Returns the node with the title that matches the target text.     */
/* Returns nullptr if no match.                                      */
struct node searchUsername (node_t** headReference, char[] target){
	(struct node)* node = *headReference;
	
	/* Base case (empty list). */
	if(node == NULL){
		return null;
	} 
	
	/* Iterate through list. */
	while (node->next == NULL){
		/* Strstr looks for substring target in string node->title. */
		/* If there's a match, return the node that matches.        */
		if(strstr(node->username, target) != nullptr ){
			return node;
		}
		/* If there's no match, move to the next node. */
		node = node->next;
	}
	/* If there were no matches in the whole list, return a nullptr. */
	return nullptr;
}
