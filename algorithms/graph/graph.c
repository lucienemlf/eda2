#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(){
  int num_vertices = 5;

  Graph* undir = create_graph(num_vertices, UNDIRECTED);
  Graph* dir = create_graph(num_vertices, DIRECTED);

  add_edge(undir,0,1);
  add_edge(undir,0,4);
  add_edge(undir,1,2);
  add_edge(undir,1,3);
  add_edge(undir,1,4);
  add_edge(undir,2,3);
  add_edge(undir,3,4);

  add_edge(dir,0,1);
  add_edge(dir,0,4);
  add_edge(dir,1,2);
  add_edge(dir,1,3);
  add_edge(dir,1,4);
  add_edge(dir,2,3);
  add_edge(dir,3,4);

  printf("\nUndirected Graph");
  display_graph(undir);

  printf("\nDirected Graph");
  display_graph(dir);

  return 0;
}

AdjNode* create_node(int vertex){
  AdjNode* new_node = (AdjNode*)malloc(sizeof(AdjNode));
  if(!new_node) err_exit("Unable to allocate memory for node!");
  new_node->vertex = vertex;
  new_node->next = NULL;
  return new_node;
}

Graph* create_graph(int num_vertices, Type type){
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  if(!graph) err_exit("Unable to allocate memory for graph!");
  graph->num_vertices = num_vertices;
  graph->type = type;

  // Creating a array of adjacency lists
  int i = 0;
  graph->adjlist_arr = (AdjList*)malloc(num_vertices*sizeof(AdjList));
  if(!graph->adjlist_arr) err_exit("Unable to allocate memory for adjlist");
  for(i=0; i<num_vertices; i++){
    graph->adjlist_arr[i].head = NULL;
    graph->adjlist_arr[i].num_members = 0;
  }
  return graph;
}

void destroy_graph(Graph* graph){
  if(graph){
    if(graph->adjlist_arr){
      int v = 0;
      for(v=0; v<graph->num_vertices;v++){
        AdjNode* adjlist = graph->adjlist_arr[v].head;
        while(adjlist){
          AdjNode* tmp = adjlist;
          adjlist = adjlist->next;
          free(tmp);
        }
      }
      free(graph->adjlist_arr);
    }
    free(graph);
  }
}

void add_edge(Graph* graph, int src, int dest){
  AdjNode* new_node = create_node(dest);
  new_node->next = graph->adjlist_arr[src].head;
  graph->adjlist_arr[src].head = new_node;
  graph->adjlist_arr[src].num_members++;

  if(graph->type == UNDIRECTED){
    new_node = create_node(src);
    new_node->next = graph->adjlist_arr[dest].head;
    graph->adjlist_arr[dest].head = new_node;
    graph->adjlist_arr[dest].num_members++;
  }
}

void display_graph(Graph* graph){
  int i = 0;
  for(i=0;i<graph->num_vertices;i++){
    AdjNode* adjlist = graph->adjlist_arr[i].head;
    printf("\n%d: ", i);
    while(adjlist){
      printf("%d->", adjlist->vertex);
      adjlist = adjlist->next;
    }
  }
}

