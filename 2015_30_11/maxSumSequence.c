#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *next;
};


struct testcases{

	int numbers[20];
	int length;
	int result;

}tests[5] = {

	{
		{1,2,3,4,5,6,7,8},
		8,
		36
	},

	{
		{-1,-1,-1,-1,-1},
		5,
		-1
	},

	{
		{-1,-2,-3,3,3,4},
		6,
		10
	},
	{
		{4,5,9,-1,-6,-7},
		6,
		18
	},
	{
		{-1,0,0,1,-2,0,0,2},
		8,
		2
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

int sumSequence(struct node *head, int length){

	int i;
	int j;
	int k;
	struct node *curr = head;
	struct node *temp;
	int max = 0;
	int sum = 0;
	
	i = 0;
	curr = head;
	max = curr->data;
	
	while(curr != NULL){
	
	
		if(max < curr->data){
			max = curr->data;
		}
		
		curr = curr->next;
		
	}
	

	temp =head;
	for(k = 0;k <length;k++){
		
	
		if(temp->next == NULL)
			break;
		for (i = 1; i < length - k; i++){
			curr = temp;
			sum = 0;
			
		
			for (j = 0; j <=i && curr != NULL; j++){
				sum = sum + curr->data;
				curr = curr->next;
			}

			if(max < sum)
				max = sum;
		}
		temp = temp->next;
	}
	return max;
}

void test(int n_tests){

	int k;
	int i;
	int result;


	struct node *head = NULL;



	for (k = 0; k < n_tests; k++){

		int flag = 1;
		head = NULL;

		head = allocate(tests[k].numbers, tests[k].length);

		result = sumSequence(head,tests[k].length);
		

		if (result == tests[k].result)
			flag = 1;

		else
			flag = 0;

		if (flag == 1)
			printf("\nPASS");
		else
			printf("\nFAIL");

	}
}

void main(){

	int n_tests = 5;
	test(n_tests);

	getchar();
}
