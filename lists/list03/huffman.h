#include<vector>
#include<cmath>
#include<map>

using namespace std;

typedef struct node Node;
typedef struct tree Tree;

void init_tree(Tree* tree);
void insert_heap(char letter, int frequence, vector<Node*> *heap);
void swap_nodes(vector<Node*> *heap, int a_pos, int b_pos);
void heapify_up(vector<Node*> *heap);
void print_heap(vector<Node*> heap);
void update_nodes(vector<Node*> *heap);
void build_heap(vector<Node*> *heap);
int parent(int child);
int left_child(int parent);
int right_child(int parent);

struct node{
  char letter;
  unsigned int frequency;
  Node* left;
  Node* right;
};

struct tree{
  Node* root;
};

void init_tree(Tree* tree){
  tree = (Tree*)malloc(sizeof(Tree));
}

void insert_heap(char letter, int frequency, vector<Node*> *heap){
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->letter = letter;
  new_node->frequency = frequency;
  new_node->left = NULL;
  new_node->right = NULL;
  heap->push_back(new_node);
}

void swap_nodes(vector<Node*> *heap, int a_pos, int b_pos){
  Node* tmp = heap->at(a_pos);
  heap->at(a_pos) = heap->at(b_pos);
  heap->at(b_pos) = tmp;
}

void heapify_up(vector<Node*> *heap){
  int index = heap->size() - 1;
  int dad = parent(index+1);
  while(index>0){
    if(heap->at(index)->frequency < heap->at(dad-1)->frequency)
      swap_nodes(heap,index,dad-1);
    index/=2;
  }
}

void update_nodes(vector<Node*> *heap){
  int size = heap->size();
  bool there_is_right = false;
  if(size%2 != 0) there_is_right = true;
  
  for(int i=0; i<size/2 ; i++){
    int left = left_child(i+1);
    int right = right_child(i+1);
    heap->at(i)->left = heap->at(left-1);
    if(there_is_right) heap->at(i)->right = heap->at(right-1);
  }
}

void print_heap(vector<Node*> heap){
  int size = heap.size();
  for(int i = 0; i<size ; i++){
    cout << "Position: "<< i << endl;
    cout << "Letter: " << heap.at(i)->letter << endl;
    cout << "Frequency: " << heap.at(i)->frequency << endl;
    cout << "Right: " << heap.at(i)->right << endl;
    cout << "Left: " << heap.at(i)->left << endl << endl;
  }
}

void build_heap(vector<Node*> *heap){
  int size = heap->size();
  int there_is_right = false;
  if(size%2 != 0) there_is_right = true;
  
  for(int i=(size/2) - 1 ; i>=0 ; i--){
    int left = left_child(i+1) - 1;
    int right = right_child(i+1) - 1;

    if(heap->at(i)->frequency > heap->at(left)->frequency)
      swap_nodes(heap,i,left);
    if(there_is_right)
      if(heap->at(i)->frequency > heap->at(right)->frequency)
        swap_nodes(heap,i,right);
  }
}

Node extract_min(vector<Node*> *heap){
  Node extract = **heap->begin();
  int last = heap->size() - 1;
  swap_nodes(heap,0,last);
  heap->pop_back();
  build_heap(heap);
  update_nodes(heap);
  return extract;
}

void insert_node(Tree* huffman){
  
}

/*
enquanto tamanho(alfabeto) > 1:
  S0 := retira_menor_probabilidade(alfabeto)
  S1 := retira_menor_probabilidade(alfabeto)
  iX  := novo_nó
  X.filho0 := S0
  X.filho1 := S1
  X.probabilidade := S0.probabilidade + S1.probabilidade
  insere(alfabeto, X)
fim enquanto

X = retira_menor_símbolo(alfabeto) # nesse ponto só existe um símbolo.

para cada folha em folhas(X):
  código[folha] := percorre_da_raiz_até_a_folha(folha)
fim para
*/

void huffman(vector<Node*> *heap){
  char alfa = 0; 
  while(alfa>1){
    Node left = extract_min(heap);
    Node right = extract_min(heap);
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->frequency = right.frequency + left.frequency;
    new_node->left = &left;
    new_node->right = &right;
    
    insert_heap('0',new_node->frequency,heap);
  }
}


int parent(int child){
  int parent = floor(child/2);
  return parent;
}

int left_child(int parent){
  int left_child = parent*2;
  return left_child;
}
  
int right_child(int parent){
  int right_child = parent*2+1;
  return right_child;
}

