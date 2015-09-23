typedef struct leaf {
	int unsigned number;
	int balancing_factor;

	struct leaf *left;
	struct leaf *right;
}Leaf;
	
typedef struct tree {
	Leaf *root;
}Tree;


Leaf *init() {
	Leaf *new_leaf = (Leaf*)malloc(sizeof(Leaf));

	puts("Please enter a number: ");
	scanf("%d", &new_leaf->number);
	new_leaf->balancing_factor = 0;
	new_leaf->right = NULL;
	new_leaf->left = NULL;

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
		father->balancing_factor -= 1;
	} else {
		father->right = leaf;
		father->balancing_factor += 1;
	}
	
}

void rotate_right(Leaf *root) {
	Leaf *new_root;
	Leaf *temp;

	new_root = root->left;
	temp = new_root->right;

	new_root->right = root;
	root->left = temp;
	root = new_root;
}

void rotate_left(Leaf *root) {
	Leaf *new_root;
	Leaf *temp;

	new_root = root->right;
	temp = new_root->left;

	new_root->left = root;
	root->right = temp;
	root = new_root;
}

void rotate_left_right(Leaf *root){
	rotate_left(root->left);
	rotate_right(root);
}

void rotate_right_left(Leaf *root){
	rotate_left(root->right);
	rotate_right(root);
}


void remove_leaf(Tree *tree) {
	
}

void in_order(Leaf *leaf){
	if(leaf != NULL){
		in_order(leaf->left);
		printf("%d (%d), ", leaf->number, leaf->balancing_factor);
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

bool verify_AVL(Leaf *leaf) {
	int result = abs(deep(leaf->right) - deep(leaf->left));
	
	if(leaf == NULL){
		return 1;
	}

	if(result <= 1){
		return true;
	}else{
		return false;
	}
}