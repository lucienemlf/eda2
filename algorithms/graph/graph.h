typedef enum {UNDIRECTED=0, DIRECTED} Type;

/* Adjacent list node */
typedef struct adjlist_node{
  int vertex; // index to adjacent list array
  struct adjlist_node* next; // pointer to the next node
}AdjNode;

/* Adjacent list */
typedef struct adjlist{
  int num_members;
  AdjNode *head;
}AdjList;

/* Graph struct */
typedef struct graph{
  Type type;
  int num_vertices;
  AdjList* adjlist_arr;
}Graph;

/* Exit function to handle fatal erros */
__inline void err_exit(char* msg){
  printf("[Fatal Error]: %s \nExiting...\n", msg);
  exit(1);
}

/* Function to create an adjacency list node */
AdjNode* create_node(int vertex);

/* Function to create a graph with n vertices
   Creates both directed and undirected */
Graph* create_graph(int num_vertices, Type type);

/* Destroy the graph */
void destroy_graph(Graph* graph);

/* Add a edge to a graph */
void add_edge(Graph* graph, int src, int dest);

/* Function to print the adjacency list of graph */
void display_graph(Graph* graph);

