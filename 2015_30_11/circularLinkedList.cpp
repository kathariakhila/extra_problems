#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *next;
};

struct testcases{

	int numbers[100];
	int len;
	int n;
	int res[100];
		
}tests[5] = {

	{
		{1,2,5,6,7},
		5,
		3,
		{1,2,3,5,6,7}
		
	},
	
	{
		{1,2,5,6,8},
		5,
		0,
		{0,1,2,5,6,8}
		
	},
	{
		{1,2,3,4,5},
		5,
		8,
		{1,2,3,4,5,8}
		
	},
	{
		
		{1,2,3,4,5,6},
		6,
		4,
		{1,2,3,4,4,5,6}
	
	},
	{
		{1,2,3,4,5,6},
		6,
		1,
		{1,1,2,3,4,5,6}
		
		
	}
};

struct node * createNode(int n1) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = n1;
	newNode->next = NULL;
	return newNode;
}

void add(struct node **head, int p){
	struct node *temp = *head;
	if (*head == NULL){
		
		(*head) = createNode(p);
		(*head)->next = *head;
	
	}
	else{
	
		while (temp->next != *head){
			temp = temp->next;
		}
	
		temp->next = createNode(p);
		temp->next->next = *head;
	}
	
}

struct node * allocate(int *numbers, int len){

	struct node* head = NULL;
	int i;

	for (i = 0; i < len; i++){
		
		add(&head,numbers[i]);
	}
	
	return head;
}


void insert(struct node **head,int n){
	
	struct node *prev = NULL;
	struct node *curr = *head;

	struct node *insertNode = createNode(n);
	//printf("\n%d",curr -> data);
	
	if(n <= curr->data){
	//	printf("\nFirst Node");
	
		while(curr->next != *head)
			curr = curr->next;
			
		insertNode->next = *head;
		*head = insertNode;
		curr->next = insertNode;
		
	}
	
	else{
	//	printf("\nSearching position");
		while(curr->data < n && curr->next != *head ){
	//		printf("\n%d",curr -> data);
			prev = curr;
			curr = curr->next;
					
		}
		
		if(curr->next == *head){
	//		printf("\nLast Node");
			curr->next = insertNode;
			insertNode = *head;
		}
		
		else{
			prev->next = insertNode;
			insertNode->next = curr; 
		}
	
	}
	
}

void test(int n_tests){

	int k;
	int i;
	
	
	struct node *head = NULL;
	struct node *curr = NULL;
	
	for (k = 0; k < n_tests; k++){
		
		int flag = 1;
		head = NULL;
		
		head = allocate(tests[k].numbers, tests[k].len);
	
	//	printf("\nAfter insertion");
		insert(&head,tests[k].n);
		curr = head;
		
		for (i = 0; i<tests[k].len+1; i++){

			if (curr->data == tests[k].res[i]){
				//printf("\n%d",res -> data);
				curr = curr->next;
				continue;
			}
			else{
			
				flag = 0;
				break;
			}
		}

		if (flag == 1)
			printf("\nPASS");
		else
			printf("\nFAIL");

	}
}

int main(){

	int n_tests = 5;
	test(n_tests);
	getchar();

}

