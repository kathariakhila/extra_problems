#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *next;
};

struct testcases{

	int numbers[100];
	int len;
	int result[100];
	
}tests[5] = {

	{
		{1,2,5,4,3},
		5,
		{1,2,3,4,5}
			
	},
	{
		{5,2,3,4,1},
		5,
		{1,2,3,4,5}
		
	},
	{
		{1,2,3,5,4,6},
		6,
		{1,2,3,4,5,6}
		
	},
	{
		{1,2,3,4,5,6},
		6,
		{1,2,3,4,5,6}
		
	},
	{
		{3,2,1,4,5,6},
		6,
		{1,2,3,4,5,6}
		
		
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
		(*head)->next = NULL;
	}
	else{
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = createNode(p);
		temp->next->next = NULL;
	}
	
}

struct node * allocate(int *numbers, int len){

	struct node* head = NULL;
	int i;

	for (i = 0; i < len; i++){
		add(&head, numbers[i]);
	}
	
	return head;
}

void swap(struct node *n1,struct node *n2){
	
	int temp;
	
	temp = n1->data;
	n1->data = n2->data;
	n2 -> data = temp;
}

void sort(struct node *head){
	

	struct node *curr = head;
	struct node * temp,*prev;
	
	while (curr->data < curr->next->data && curr->next->next != NULL){
	
		curr = curr->next;
	}
	
	temp = curr;
	prev = curr;
	curr = curr->next;
	
	while(curr != NULL && curr->data < temp->data){
		prev = curr;
		curr = curr->next;
	}
	
	
	swap(temp,prev);
	
}

void test(int n_tests){

	int k;
	int i;
	
	struct node *curr = NULL;
	struct node *head = NULL;

	for (k = 0; k < n_tests; k++){
		
		int flag = 1;
		head = NULL;
	
		head = allocate(tests[k].numbers, tests[k].len);
	
	
		sort(head);
		
		curr = head;
		for (i = 0; i<tests[k].len; i++){

			if (curr->data == tests[k].result[i]){
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

