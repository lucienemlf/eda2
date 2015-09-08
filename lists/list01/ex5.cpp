#include <stdio.h>
#include <stdlib.h>

/*
	Busca binaria em lista circular
*/

typedef struct node{
    int number;
    struct node *next;
}Node;

typedef struct list{
    Node *top;
    Node *tail;
}List;

void enqueue(List *list);
int empty(List *list);
void print_list(List *list);
void dequeue(List *list);
void clear(List *list);
Node *find_midle(Node *begin, Node* end);
Node *binary_search(List *list, int key);
void search(List *list);
void menu();



int main(){
    List *list = (List *)malloc(sizeof(List));
    list->top = list->tail = NULL;
    int option;

    do{
    	menu();
        scanf("%d",&option);
         
         switch(option) {
            case 1:
                enqueue(list);
                break;
            case 2:
            	if(!empty(list)){
                	dequeue(list);
            	}
                break;
            case 3:
            	if(!empty(list)){
            	    clear(list);
                }
                break;
            case 4:
            	if(!empty(list)){
                	print_list(list);
            	}
                break;
             case 5:
             	search(list);
             	break;       
         }
        
    }while(option != 6);
    
return 0;    
}

void menu() {
     printf("\n----------------Menu----------------\n");
     printf("1. Insert number\n"); 
     printf("2. Remove first number\n");
     printf("3. Empty line\n");  
     printf("4. Print elements\n");
     printf("5. Search for a value\n");
     printf("6. Exit\n");
     printf("\n--------------------------------------\n");
}



Node *find_midle(Node *begin, Node *end) {

	if(begin == NULL){
		return NULL;
	}

	Node *slow = begin;
	Node *fast = begin->next;

	while(fast != end) {
		fast =  fast->next;

		if(fast != end) {

			fast =  fast->next;
			slow = slow->next;
		}
	}

	return slow;
}


Node  *binary_search(List *list, int key) {
	Node *begin = list->top;
	Node *end = list->tail;

	while(begin != end) {
		Node *midle = find_midle(begin, end);
		
		if(midle == NULL) {
			return NULL;
		}

		if(midle->number ==  key){
			return midle;
		}else if(midle->number < key) {
			begin = midle->next;			
		}else {
			end = midle;
		}
	}

	// Number not present
	return NULL;
}

void search(List *list) {
	Node *result;
	int key;

 	printf("Enter the number you want to find:");
 	scanf("%d", &key);

 	result = binary_search(list, key);

 	if(result == NULL) {
 		printf("\nValue not found\n");
 	}else{
 		printf("\nElement %d found.\n", result->number);
 	}
}

void enqueue(List *list)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = NULL;
    
    printf("Enter a value: \n");
    scanf("%d", &temp->number);

    if(list->top == NULL)
    {
       list->top = list->tail = temp; 
       list->top->next = list->top;
    }
     else
     {
        list->tail->next = temp;
        list->tail = temp;
        temp->next = list->top;
     }   
    
}

int empty(List *list)
{
    if(!list->top){
        printf("a pilha esta vazia\n");
        return 1;
    }else{
    	return 0;
    }
}

void print_list(List *list)
{
    Node *temp = list->top;
        
    do {

      printf("Value: %d\n", temp->number);
      temp = temp->next;
    
    } while(temp != list->top);
      
}

void dequeue(List *list)
{
    Node *temp = list->top;

    if(list->top == list->tail){
    	free(list);
    	list->top = list->tail = NULL;
    }else{
	    list->top = list->top->next;
	    list->tail->next = list->top;
	    free(temp);        
    }
}

void clear(List *list){
    
	Node *node =  list->top; 
	Node *removed_node = NULL; 
	
	do {
		removed_node = node;
		node = node->next;
		free(removed_node);

	}while(node != list->top);


    printf("Deleted succeeded!\n");
    free(list);
    list->top = list->tail = NULL;
}
