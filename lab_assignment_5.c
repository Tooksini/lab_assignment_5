#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head){
	node* tmp = head;
	int count = 0;

	if(tmp == NULL){
		return count;
	} else{
		while(tmp != NULL){
			tmp = tmp->next;
			count++;
		}
	}
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head){
	int len = length(head);
	int i = 0;

	char* str = (char*)malloc((len + 1) * sizeof(char));
	node* curr = head;

	while(curr != NULL){
		str[i] = curr->letter;
		curr = curr->next;
		i++;
	}
	str[i] = '\0';
	
	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c){
	node* newNode = (node*)malloc(sizeof(node));

	if(newNode == NULL){
		return;
	}
	newNode->letter = c;
	newNode->next = NULL;

	node* tmp = *pHead;
	while((tmp != NULL)&&(tmp->next != NULL)){
		tmp = tmp->next;
	}
	if(tmp != NULL){
		tmp->next = newNode;
	} else{
		*pHead = newNode;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead){
	node* curr = *pHead;
	node* next;

	if(*pHead == NULL){
		return;
	} else{
		while(curr != NULL){
			next = curr->next;
			free(curr);
			curr = next;
		}
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}