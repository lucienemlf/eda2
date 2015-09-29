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

int deep(Leaf *runs);
void pos_order(Leaf *leaf);
void pre_order(Leaf *leaf);
void in_order(Leaf *leaf);
int balancing_factor(Leaf *leaf);
void update_balancing_factor_right(Leaf *leaf, Tree *tree);
void update_balancing_factor_left(Leaf *leaf, Tree *tree);
void rotate_right_left(Leaf *root, Tree *tree);
void rotate_left_right(Leaf *root, Tree *tree);
void rotate_left(Leaf *root, Tree *tree);
void rotate_right(Leaf *root, Tree *tree);
void update_balancing_factor(Leaf *leaf, Tree *tree);
Leaf *init();
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


void update_balancing_factor(Leaf *leaf, Tree *tree){
printf("\nupdate_balancing_factor\n");
printf("antes - pai: %d\n", leaf->father->number);
    leaf->father->balancing_factor = balancing_factor(leaf->father);
printf("balancing_factor: %d\n", leaf->father->balancing_factor);
    if(leaf->father->balancing_factor == 2){
        if(leaf->father->right->balancing_factor < 0){
            rotate_right_left(leaf->father, tree);
        }else{
            rotate_left(leaf->father, tree);
        }
    }else if(leaf->father->balancing_factor == (-2)){
        if(leaf->father->left->balancing_factor > 0){
            rotate_left_right(leaf->father, tree);
        }else{
            rotate_right(leaf->father, tree);
        }
    }else if(leaf->father != tree->root){
        update_balancing_factor(leaf->father, tree);
    }
}

// Pai vira filho direita
void rotate_right(Leaf *root, Tree *tree) {
printf("\nRotate_right\n");
printf("\nPai: %d\n", root->number);

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
         //root->father->left = new_root;
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

int balancing_factor(Leaf *leaf){
    return deep(leaf->right) - deep(leaf->left);
}

// O pai vira filho da esquerda
void rotate_left(Leaf *root, Tree *tree) {
printf("\nRotate_left\n");
printf("\nPai: %d\n", root->number);
    Leaf *new_root;
    Leaf *temp;

    new_root = root->right;
    temp = new_root->left;
    root->right = temp;

    if(root->right){
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

//printf("\n Novo pai: %d\n", root->number);
//printf("\n Pai do novo pai: %d\n", root->father->number);

    if(root->left != NULL){
//printf("\nFilho esquerda: %d\n", root->left->number);
        if(root->left->left != NULL){
//printf("\nFilho esquerda de %d: %d\n", root->left->number, root->left->left->number);
        }
        if(root->left->right == NULL){
//printf("\nFilho direita de %d: %d\n", root->left->number, root->right->right->number);
        }
    }


    if(root->right != NULL){
//printf("\nFilho direita: %d\n", root->right->number);
        if(root->right->left){
//printf("\nFilho direita de %d: %d\n", root->right->number, root->right->left->number);
        }
        if(root->right->right){
//printf("\nFilho direita de %d: %d\n", root->right->number, root->right->right->number);
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

void in_order(Leaf *leaf){
    if(leaf != NULL){
        in_order(leaf->left);
        //printf("%d (%d), ", leaf->number, leaf->balancing_factor);
        printf("%d (%d)pai:(%d),  ", leaf->number, leaf->balancing_factor, leaf->father->number);
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
