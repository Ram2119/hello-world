
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} NODE;


NODE* insert(NODE *head, int numToInsert)
{
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	if (!newNode)
		return;	

	newNode->data = numToInsert;
/*
 * begin  
	newNode->next = head;
	head = newNode;
*/
	
/*
 *	end
	if (!head)
		head = newNode;
	else {
		NODE *tmp = head;	
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = newNode;
		newNode->next = NULL;
	}
*/

/*
 *	Middle
 */	
	if (!head)
		head = newNode;
	else {
		NODE *tmp1 = head;
		NODE *tmp2 = head;
		while (tmp2 && tmp2->next) {
			tmp2 = tmp2->next;
			if (!tmp2)
				break;
			tmp2 = tmp2->next;
			tmp1 = tmp1->next;
		}
	
		newNode->next = tmp1->next;
		tmp1->next = newNode;
	}

	return head;
}

void show(NODE *head)
{
	if (!head)
		printf("List empty!\n");
	else {	
		while(head) {
			printf("%d  ", head->data);
			head = head->next;
		}
		printf("\n");
	}
}

int main(void)
{
	NODE *head = NULL;

	while (1) {
		printf("Select\n");
		printf("1. Insert\n");	
		printf("2. Show\n");
		printf("3. Exit\n");
		int ch;
		scanf("%d", &ch);
		switch (ch) {
			case 1 :
				printf("Enter num to insert\n");
				int n;
				scanf("%d", &n);
				head = insert(head, n);
				break;
			case 2 :
				show(head);
				break;
			default:
				return 0;
		}
	} 

	return 0;
}
