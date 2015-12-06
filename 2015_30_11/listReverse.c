#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *next;
};

struct testcases{

	int numbers[100];
	int len;
//	int n;
	int res[100];
		
}tests[4] = {

	{
		{1,2,5,6,7},
		5,
		
		{7,6,5,2,1}
		
	},
	
	{
		{1,2,5,6,8},
		5,
		{8,6,5,2,1}
		
	},
	{
		{1,2,3,4,5},
		5,
		{5,4,3,2,1}
		
	},
	
	{
		{1,2,3,4,5,6},
		6,
		{6,5,4,3,2,1}
		
		
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
		
		add(&head,numbers[i]);
	}
	
	return head;
}

struct node *reverse(struct node *head){

//	printf("\nInside reverse");
    struct node *revHead;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    revHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL; 

    return revHead;
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
	
		//printf("\nAfter allocation");
		head = reverse(head);
		curr = head;
		
		for (i = 0; i<tests[k].len; i++){

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

	int n_tests = 4;
	test(n_tests);
	getchar();

}

