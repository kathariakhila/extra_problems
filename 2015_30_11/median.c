#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *next;
};

struct testcases{

	int numbers[100];
	int length;
	int exptresult;

}tests[4] = {

		{
			{1,2,3,4,5},
			5,
			3
		},
		{
			{4,5,6,7},
			4,
			5

		},
		{
			{0,0,0,0,0},
			5,
			0
		},

		{
			{1,2,3,4,6,7,8},
			7,
			4
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

int medianCalc(struct node* head){

	int i = 1;
	int len = 0;
	struct node *curr = head;
	
	while (curr != NULL){
		len++;
		curr = curr->next;
	}

	curr = head;
	//printf("\n%d",curr->data);
	if (len % 2 == 1){
		while (i <= len / 2){
			curr = curr->next;
			//printf("\n%d",i);
			i++;
		}
		//printf("\n%d",curr->data);
		return curr->data;

	}

	else{
		i = 1;
		while (i < len / 2){
		//	printf("\n%d",curr->data);
			curr = curr->next;
			i++;
		}

		int res = curr->data;
		curr = curr->next;
		res = res+curr->data;
		res = res/2;
		return  res;
	}


}


void test(int n_tests){

	int k;
	int result;

	struct node *head = NULL;

	for (k = 0; k < n_tests; k++){
		int flag = -1;
		head = NULL;
		head = allocate(tests[k].numbers, tests[k].length);

		result = medianCalc(head);

		if (result == tests[k].exptresult)
			flag = 1;
		else
			flag = -1;

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

