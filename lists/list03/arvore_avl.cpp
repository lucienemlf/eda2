#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void menu(){
	puts("");
	puts("1. Insert an number");
	puts("2. Print numbers ordered");
	puts("3. Delete leaf");
	puts("4. Exit");
}


int main (){
	int option = 0;
	int number = 0;
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
				puts("Please inform the number to be deleted: ");
				scanf("%d", &number);

				//remove_leaf(tree->root, number);
				break;
			case 4:
				puts("bye!");
				break;
		}

	}while(option != 4);

	return 0;
}