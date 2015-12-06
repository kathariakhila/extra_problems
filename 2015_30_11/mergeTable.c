#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *next;
};

struct testcases{

	int n1;
	int n2;
	int r;
	int exptResult;
	//int resLen;
}tests[2] = {

	{
		3,
		5,
		1,
		3
	},	
	
	{
		6,
		2,
		7,
		14
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

struct node * allocate(int n){

	struct node* head = NULL;
	int i;

	for (i = 1; i <= 10; i++){
		add(&head, n*i);
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
		//	printf("\n%d",curr->data);
		}
		
		else if(curr1->data < curr2->data){
		//	printf("\n%d",curr1->data);
			if(*res == NULL)
				curr = *res = curr1;
			
			else{
				
				curr->next = curr1;
				curr = curr->next;	
		//		printf("\n%d",curr->data);
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
		//		printf("\n%d",curr->data);
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
		//		printf("\n%d",curr->data);
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

int calculateValue(struct node* res,int r){
	
	struct node* curr = res;
	int i;
	
	for(i = 1;i < r && curr != NULL;i++){
		//printf("\n%d",curr->data);
		curr = curr->next;
	}
	return curr->data;
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
		int value;
		
		head1 = allocate(tests[k].n1);
		head2 = allocate(tests[k].n2);
		
		merge(head1,head2,&res);
		//printf("\nOutSide the merge");
		
		value = calculateValue(res,tests[k].r);

		if(value = tests[k].exptResult)
			flag = 1;
				
		
		else
			flag = 0;
			
		
		

		if (flag == 1)
			printf("\nPASS");
		else
			printf("\nFAIL");

	}
}

int main(){

	int n_tests = 2;
	test(n_tests);
	getchar();

}

