typedef struct leaf {
    int unsigned number;
    int balancing_factor;


    struct leaf *father;
    struct leaf *left;
    struct leaf *right;
}Leaf;
    
typedef struct tree {
    Leaf *root;
}Tree;

Leaf *init();
Leaf *search(Leaf *leaf, int number);
void pos_order(Leaf *leaf);
void pre_order(Leaf *leaf);
void in_order(Leaf *leaf);
void rotate_right_left(Leaf *root, Tree *tree);
void rotate_left_right(Leaf *root, Tree *tree);
void rotate_left(Leaf *root, Tree *tree);
void rotate_right(Leaf *root, Tree *tree);
void update_balancing_factor(Leaf *leaf, Tree *tree);
void update_balancing_factor_top_down(Leaf *leaf, Tree *tree);
Leaf *remove_leaf(Leaf *leaf, Tree *tree, int number);
int deep(Leaf *runs);
int balancing_factor(Leaf *leaf);
int insert(Tree *tree);


Leaf *init() {
    Leaf *new_leaf = (Leaf*)malloc(sizeof(Leaf));

    puts("Please enter a number: ");
    scanf("%d", &new_leaf->number);
    new_leaf->balancing_factor = 0;
    new_leaf->right = NULL;
    new_leaf->left = NULL;
    new_leaf->father = new_leaf;

    return new_leaf;
}

int insert(Tree *tree){
    Leaf *leaf = init();      // New leaf
    Leaf *father;             // Will receive the new leaf
    Leaf *runs = tree->root;  


    /*Localizar o pai abaixo do qual será inserido o novo nó*/
    while(runs) {
        father = runs; 

        if(leaf->number < runs->number) {

            runs = runs->left;

        }else if(leaf->number > runs->number) {

            runs = runs->right;

        }else { 
            return 1;
        }
    }

    /* Insert the node in the tree*/
    if(!tree->root) {
        tree->root = leaf;
    } else if(leaf->number < father->number) {
        father->left = leaf;
        leaf->father = father;
    	update_balancing_factor(leaf, tree);
    } else {
        father->right = leaf;
        leaf->father = father;
    	update_balancing_factor(leaf, tree);
    }
    
}

Leaf *remove_leaf(Leaf *leaf, Tree *tree, int number){
		
	if(leaf == NULL){
		return NULL;
	}else if(number < leaf->number){
printf("menor\n");
		leaf->left = remove_leaf(leaf->left, tree, number);
	}else if(number > leaf->number){
printf("maior\n");
		leaf->right = remove_leaf(leaf->right, tree, number);
	}else{
		if(leaf->left == NULL  && leaf->right == NULL){
printf("Sem filhos\n");
			free(leaf);
			leaf = NULL;
		}else if(leaf->right == NULL){
printf("Sem filho direito\n");
			Leaf *temp = leaf;
			leaf = leaf->left;
			leaf->father = temp->father;
			free(temp);
		}else if(leaf->left == NULL){
printf("Sem filho esquerdo\n");
			Leaf *temp = leaf;
			leaf = leaf->right;
			leaf->father = temp->father;
			free(temp);
		}else{
printf("com dois filhos\n");
			Leaf *temp = leaf->left;

			// Acha o imediatamente menor
			while(temp->right != NULL){
				temp = temp->right;
			}

			leaf->number = temp->number;
			temp->number = number;
			leaf->left = remove_leaf(leaf->left, tree, number);
		}	

	}

	return leaf;
}

// ----------------------- Balanceamento ---------------------------------------

void update_balancing_factor(Leaf *leaf, Tree *tree){
printf("\nupdate_balancing_factor\n");

printf("Leaf: %d\n", leaf->number);
    leaf->balancing_factor = balancing_factor(leaf);
printf("balancing_factor: %d\n", leaf->father->balancing_factor);
    if(leaf->balancing_factor == 2){
        if(leaf->right->balancing_factor < 0){
            rotate_right_left(leaf, tree);
        }else{
            rotate_left(leaf, tree);
        }
    }else if(leaf->balancing_factor == (-2)){
        if(leaf->left->balancing_factor > 0){
            rotate_left_right(leaf, tree);
        }else{
            rotate_right(leaf, tree);
        }
    }else if(leaf != tree->root){
        update_balancing_factor(leaf->father, tree);
    }
}



void update_balancing_factor_top_down(Leaf *leaf, Tree *tree){
 printf("Leaf: %d\n", leaf->number);  
 printf("balancing_factor antes: %d\n", leaf->balancing_factor);  
    if(leaf->balancing_factor == 2){
        if(leaf->right->balancing_factor < 0){
 printf("2\n");  
            leaf = rotate_right_left(leaf, tree);
        }else{
 printf("3\n");  
            leaf = rotate_left(leaf, tree);
        }
    }else if(leaf->balancing_factor == (-2)){
        if(leaf->left->balancing_factor > 0){
 printf("4\n");  
            leaf = rotate_left_right(leaf, tree);
        }else{
 printf("5\n");  
           left = rotate_right(leaf, tree);
        }
    }

 printf("6\n");  
 printf("balancing_factor deppois: %d\n", leaf->balancing_factor);  
    leaf->balancing_factor = balancing_factor(leaf);

    if(leaf->left != NULL){
 printf("7\n");  
        update_balancing_factor_top_down(leaf->left, tree);
    }

    if(leaf->right != NULL){
 printf("8\n");  
        update_balancing_factor_top_down(leaf->right, tree);
    }
}

int balancing_factor(Leaf *leaf){
    return deep(leaf->right) - deep(leaf->left);
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

// ----------------------- Rotações ---------------------------------------

// Pai vira filho direita
void rotate_right(Leaf *root, Tree *tree) {															printf("\nRotate_right\n");
    Leaf *new_root;
    Leaf *temp;

    new_root = root->left;
    temp = new_root->right;
    root->left = temp;

    if(root->left){
        root->left->father = root;
    } 

    new_root->right = root;

    // Atualizando os pais
    if(root != tree->root){ 
        new_root->father = root->father;
        root->father->right = new_root;
    }else{
        new_root->father = new_root;
        tree->root  = new_root;
    }

    root->father = new_root;
    root = new_root;

										printf("\n Novo pai: %d\n", root->number);
										printf("\n Pai do novo pai: %d\n", root->father->number);

    if(root->left != NULL){
										printf("\nFilho esquerda: %d\n", root->left->number);
        if(root->left->left != NULL)
										printf("\nFilho esquerda de %d: %d\n", root->left->number, root->left->left->number);
        if(root->left->right != NULL)
										printf("\nFilho direita de %d: %d\n", root->left->number, root->right->right->number);
    }


    if(root->right != NULL){
										printf("\nFilho direita: %d\n", root->right->number);
        if(root->right->left)
										printf("\nFilho direita de %d: %d\n", root->right->number, root->right->left->number);
        if(root->right->right)
										printf("\nFilho direita de %d: %d\n", root->right->number, root->right->right->number);
    }



    root->right->balancing_factor = balancing_factor(root->right);
    root->balancing_factor = balancing_factor(root);

in_order(tree->root);
}


// O pai vira filho da esquerda
void rotate_left(Leaf *root, Tree *tree) {
	printf("\nRotate_left\n");
	printf("Leaf: %d\n", root->number);
    Leaf *new_root;
    Leaf *temp;

    new_root = root->right;
    temp = new_root->left;
    root->right = temp;

    if(root->right){
    	printf("root->right->father: %d\n",   root->right->father->number);
        root->right->father = root;
    }

    new_root->left = root;

    // Atualizando os pais
    if(root != tree->root){ 
        new_root->father = root->father;
        root->father->left = new_root;
    }else{
        new_root->father = new_root;
        tree->root = new_root;
    }

    root->father = new_root;
    root = new_root;

	printf("\n Novo pai: %d\n", root->number);
printf("\n Pai do novo pai: %d\n", root->father->number);

    if(root->left != NULL){
											printf("\nFilho esquerda: %d\n", root->left->number);
        if(root->left->left != NULL){
											printf("\nFilho esquerda de %d: %d\n", root->left->number, root->left->left->number);
        }
        if(root->left->right != NULL){
											printf("\nFilho direita de %d: %d\n", root->left->number, root->right->right->number);
        }
    }


    if(root->right != NULL){
											printf("\nFilho direita: %d\n", root->right->number);
        if(root->right->left){
											printf("\nFilho direita de %d: %d\n", root->right->number, root->right->left->number);
        }
        if(root->right->right){
											printf("\nFilho direita de %d: %d\n", root->right->number, root->right->right->number);
        }
    }

    root->left->balancing_factor = balancing_factor(root->left);
    root->balancing_factor = balancing_factor(new_root);
in_order(tree->root);
}

void rotate_left_right(Leaf *root, Tree *tree){
printf("\nRotate_left_right\n");
    rotate_left(root->left, tree);
    rotate_right(root, tree);
}

void rotate_right_left(Leaf *root, Tree *tree){
printf("\nROTATE_RIGHT_LEFT");
    rotate_right(root->right, tree);
    rotate_left(root, tree);
}

// ----------------------- Travessia ---------------------------------------

void in_order(Leaf *leaf){
    if(leaf != NULL){
        in_order(leaf->left);
        printf("Number: %d  Pai: %d ", leaf->number, leaf->father->number);
        if(leaf->left != NULL) printf("   Esquerdo: %d ", leaf->left->number);
		if(leaf->right != NULL) printf("   Direito: %d ", leaf->right->number);
		printf("  Balanceamento: %d\n", leaf->balancing_factor);
        in_order(leaf->right);
    }
}

void pre_order(Leaf *leaf){
    if(leaf != NULL){
        printf("%d (%d), ", leaf->number, leaf->balancing_factor);
        pre_order(leaf->left);
        pre_order(leaf->right);
    }
}

void pos_order(Leaf *leaf){
    if(leaf != NULL){
        pos_order(leaf->right);
        printf("%d (%d), ", leaf->number, leaf->balancing_factor);
        pos_order(leaf->left);
    }
}



Leaf *search(Leaf *leaf, int number){

	if(leaf->number == number){
		return leaf;
	}else if(number < leaf->number){
		search(leaf->left, number);
	}else if(number > leaf->number){
		search(leaf->right, number);
	}else{
		return NULL;
	}
	
}
