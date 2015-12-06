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
			{1,2,3,4,5,6,7,8,9},
			9
		},
		{
			{1,2,3,4,5},
			{6,7,8,9,10},
			5,
			5,
			{1,2,3,4,5,6,7,8,9,10},
			10
			

		},
		{
			{1,5,7,10},
			{3,5,9},
			4,
			3,
			{1,3,5,7,9,10},
			6
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

void merge(struct node* head1,struct node* head2,struct node** res){
	
	struct node* curr1 = head1;
	struct node* curr2 = head2;
	
	struct node* curr = *res;
	
	while(curr1 != NULL && curr2 != NULL){
		
		if(curr1->data == curr2->data){
		//	printf("\n%d",curr1->data);
			if(*res== NULL)
				curr = *res = curr1;
				
			
			else{
			
				curr->next = curr1;	
				curr = curr->next;	
			}
			curr1 = curr1->next;
			curr2 = curr2->next;
			//printf("\n%d",curr->data);
		}
		
		else if(curr1->data < curr2->data){
		//	printf("\n%d",curr1->data);
			if(*res == NULL)
				curr = *res = curr1;
			
			else{
				
				curr->next = curr1;
				curr = curr->next;	
				//printf("\n%d",curr->data);
			}
			curr1 = curr1->next;
		}
		else{
		//	printf("\n%d",curr2->data);
			if(*res == NULL)
				curr = *res = curr2;
			
			else{
			
				curr->next = curr2;	
				curr = curr->next;
				//printf("\n%d",curr->data);
			}
			curr2 = curr2->next;
		}
		
		//printf("\n%d",curr->data);
		
	}
	
	while(curr1 != NULL){
	
			if(*res == NULL)
				curr = *res = curr1;
				
			
			else{
			
				curr->next = curr1;		
				curr = curr->next;
				//printf("\n%d",curr->data);
			}
			curr1 = curr1->next;	
	}
		
	while(curr2 != NULL){
		
		if(*res == NULL)
				curr = *res = curr2;
			
		else{
			
			curr->next = curr2;
			curr = curr->next;	
		//	printf("\n%d",curr->data);
		}
						
		curr2 = curr2->next;	
		
	}
	
	curr->next = NULL;
	return;
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
		
		merge(head1,head2,&res);

		for (i = 0; i<tests[k].resLen; i++){

			if (res->data == tests[k].result[i]){
				//printf("\n%d",res -> data);
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

