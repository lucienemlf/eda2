#include <stdio.h>
#include <stdlib.h>

typedef struct leaf {
	int unsigned age;

	struct leaf *left;
	struct leaf *right;
}Leaf;

typedef struct tree {
	Leaf *root;
}Tree;

void menu(){
	puts("");
	puts("1. Insert an age");
	puts("2. Print ages ordered");
	puts("9. Remover age");
	puts("10. exit");

}

Leaf *init() {
	Leaf *new_leaf = (Leaf*)malloc(sizeof(Leaf));

	puts("Please enter an age: ");
	scanf("%d", &new_leaf->age);

	new_leaf->right = NULL;
	new_leaf->left = NULL;

	return new_leaf;
}

int deep(Leaf *runs){
	int count_right;
	int count_left;

	if(runs == NULL){
		return 0;
	}

	count_left = 1 + deep(runs->left);
	count_right =1 + deep(runs->right); 

	return count_right > count_left ? count_right : count_left;
}

int count_leaf(Leaf *runs) {
	int leaf;

	if(runs == NULL){
		return 0;
	}

	if((runs->left == NULL) && (runs->right == NULL)){
		return 1;
	}

	leaf = count_leaf(runs->left) + count_leaf(runs->right);

	return leaf;
}

int insert(Tree *tree){
	Leaf *leaf = init();      // New leaf
	Leaf *father;             // Will receive the new leaf
	Leaf *runs = tree->root;  


	/*Localizar o pai abaixo do qual será inserido o novo nó*/
	while(runs) {
		father = runs; 

		if(leaf->age < runs->age) {

			runs = runs->left;

		}else if(leaf->age > runs->age) {

			runs = runs->right;

		}else { 
			return 1;
		}
	}

	/* Insert the node in the tree*/
	if(!tree->root) {
		printf("arvore vazia");
		tree->root = leaf;
	} else if(leaf->age < father->age) {
		printf("esquerda");
		
		father->left = leaf;
	} else {
		printf("direita");
		father->right = leaf;
	}
	
}

void in_order(Leaf *leaf){
	if(leaf != NULL){
		in_order(leaf->left);
		printf("%d, ", leaf->age);
		in_order(leaf->right);
	}
}

void pre_order(Leaf *leaf){
	if(leaf != NULL){
		printf("%d, ", leaf->age);
		pre_order(leaf->left);
		pre_order(leaf->right);
	}
}

void pos_order(Leaf *leaf){
	if(leaf != NULL){
		pos_order(leaf->right);
		printf("%d, ", leaf->age);
		pos_order(leaf->left);
	}
}

Leaf *search(Leaf *leaf, int age){

	if(leaf->age == age){
		return leaf;
	}else if(age < leaf->age){
		search(leaf->left, age);
	}else if(age > leaf->age){
		search(leaf->right, age);
	}else{
		return NULL;
	}
}


Leaf *remove_leaf(Leaf *leaf, int age){

	if(leaf == NULL){
		printf("Valor não encontrado!\n");
		return NULL;
	}else if(age < leaf->age){
		leaf->left = remove_leaf(leaf->left, age);
	}else if(age > leaf->age){
		leaf->right = remove_leaf(leaf->right, age);
	}else{
		
		if(leaf->left == NULL  && leaf->right == NULL){
printf("Sem filhos\n");
			free(leaf);
			leaf = NULL;
		}else if(leaf->right == NULL){
printf("Sem filho direito\n");
			Leaf *temp = leaf;
			leaf = leaf->left;
			//temp->left = NULL;
			free(temp);
			//leaf->father = temp->father;
		}else if(leaf->left == NULL){
printf("Sem filho esquerdo\n");
			Leaf *temp = leaf;
			leaf = leaf->right;
			//temp->right = NULL;
			free(temp);
			//leaf->father = temp->father;
		}else{
printf("com dois filhos\n");
			Leaf *temp = leaf->left;

			// Acha o imediatamente menor
			while(temp->right != NULL){
				temp = temp->right;
			}

			leaf->age = temp->age;
			temp->age = age;
			leaf->left = remove_leaf(leaf->left, age);
		}
	}

	if(leaf == NULL){
		printf("NULLO\n");		
	}else{
		printf("LEAF %d\n", leaf->age);
	}
	return leaf;
}

int main (){
	int result;
	int leafs;
	int option = 0;
	int age = 0;
	Tree *tree = (Tree*)malloc(sizeof(Tree));

	do{
		menu();
		scanf("%d", &option);

		switch(option){
			case 1:
				insert(tree);
				break;
			case 2:
				in_order(tree->root);
				break;
			case 3:
				pre_order(tree->root);
				break;
			case 4:
				pos_order(tree->root);
				break;
			case 5:
				result = deep(tree->root);
				printf("Deep: %d\n", result);
				break;
			case 6:
				leafs = count_leaf(tree->root);
				printf("Leafs: %d\n", leafs);
				break;
			case 7:
				puts("bye!");
				break;
			case 8:
				puts("Please inform the age");
				scanf("%d", &age);

				search(tree->root, age);
				break;
			case 9:
				puts("Please inform the age to be deleted");
				scanf("%d", &age);

				remove_leaf(tree->root, age);
				break;

		}

	}while(option != 10);

	return 0;
}