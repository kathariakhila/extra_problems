#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *next;
};

struct testcases{

	int list1[100];
	int list2[100];
	int len1;
	int len2;
	int result[100];
	int resLen;

}tests[5] = {

		
		{
			{1,3,5,7,9},
			{2,4,6,8},
			5,
			4,
			{3,7,11,15,9},
			6
		},
		{
			{1,2,3,4,5},
			{6,7,8,9,10},
			5,
			5,
			{7,9,11,13,15},
			5
			

		},
		{
			{1,5,7,10},
			{3,5,9},
			4,
			3,
			{4,10,16,10},
			4
		},
		
		{
			{},
			{1,2,3},
			0,
			3,
			{1,2,3},
			3
		},
		{
			{1,9,10,20,30},
			{},
			5,
			0,
			{1,9,10,20,30},
			5
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

struct node * addition(struct node* head1,struct node *head2){
		struct node* curr1 = head1;
		struct node* curr2 = head2;
		struct node* lastNode = NULL;
		
		if(curr1 == NULL)
			return head2;
		
		if(curr2 == NULL)
			return head1;
		
		while(curr1 != NULL && curr2 != NULL){
			curr1->data = curr1->data + curr2->data;	
			
			lastNode = curr1;
			if(curr1->next == NULL)
				break;
			
			else if(curr2->next == NULL)
				break;
				
			curr1 = curr1->next;
			curr2 = curr2->next;
			
				
		}
		
		return head1;
		
	
}


void test(int n_tests){

	int k;
	int i;
	
	struct node *res = NULL;
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	
	for (k = 0; k < n_tests; k++){
		
		int flag = 1;
		head1 = NULL;
		head2 = NULL;
		res = NULL;
		
		head1 = allocate(tests[k].list1, tests[k].len1);
		head2 = allocate(tests[k].list2, tests[k].len2);
		
		res = addition(head1,head2);

		for (i = 0; i<tests[k].resLen; i++){

			if (res->data == tests[k].result[i]){

				
				if(res->next == NULL)
					break;
				else	
					res = res->next;
				
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

