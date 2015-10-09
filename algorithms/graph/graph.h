/**
  Simples direct graph
*/

typedef struct graph *Graph;

/**
  Create a new graph with 'n' vertices labeled 0..(n-1)
  and no edges
*/
Graph graph_create(int n);

/**
  Free all space used by graph
*/
void graph_destroy(Graph);

/**
  Add an edge to an existing graph
  Doing this more than once may have unpredictable
    results
*/
void graph_add_edge(Graph, int source, int sink);

/**
  Return the number of vertices/edges in the graph
*/
int graph_vertex_count(Graph);
int graph_edge_count(Graph);

/**
  Return the out-degree of the vertex
*/
int graph_out_degree(Graph, int source);

/**
  Return 1 if edge (source,sink) exists, 0 otherwise
*/
int graph_has_edge(Graph,int source, int sink);

/**
  Invoke 'f' on all edges (u,v) with source 'u'
  Supplying data as final parameter to 'f'
  No particular order is guaranteed
*/
void graph_foreach(Graph g, int source,
  void (*f)(Graph g, int source, int sink, void *data),
  void *data);
