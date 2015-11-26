// Ordenar por ordem de início
// Ordenar por ordem de fim
// Menor número de overlap
// Ordenar por duração.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct tarefas{
	int inicio;
	int fim;
	int duracao;
	char nome;
}Tarefas;

void greedy(priority_queue<Tarefas> queue){
	vector<Tarefas> tarefas;

	for(int i=0; i < 8; i++){
		if(1){
		}
	
	}
}

void ordena_inicio(){}

void ordena_fim(){}

void ordena_duracao(){}

int main( ) {
	  Tarefas tarefas[8];

// como fazer priority_queue de struct
// ou vazer uma classe tarefa e ver como vou ordenar os elementos
// ou fazer uma função bool compare
		
    tarefas[0].nome = 'a';
		tarefas[0].inicio = 0;
		tarefas[0].fim = 6;
		tarefas[0].duracao = 6;

		tarefas[1].nome = 'b'; 
		tarefas[1].inicio = 1;
		tarefas[1].fim = 4;
		tarefas[1].duracao = 3;
	
		tarefas[2].nome = 'c';
		tarefas[2].inicio = 3;
		tarefas[2].fim = 5;
		tarefas[2].duracao = 2; 
	

    tarefas[3].nome = 'd';
		tarefas[3].inicio = 3;
		tarefas[3].fim = 8;
		tarefas[3].duracao = 5;
	
    tarefas[4].nome = 'e'; 
		tarefas[4].inicio = 4;
		tarefas[4].fim = 7;
		tarefas[4].duracao = 3;
	
   	tarefas[5].nome = 'f';
		tarefas[5].inicio = 5;
		tarefas[5].fim = 9;
		tarefas[5].duracao = 4;

		tarefas[6].nome = 'g'; 
		tarefas[6].inicio = 6;
		tarefas[6].fim = 10;
		tarefas[6].duracao = 4;
	
		tarefas[7].nome = 'h';
		tarefas[7].inicio = 8;
		tarefas[7].fim = 11;
		tarefas[7].duracao = 3; 
	

		// Ordenação
		priority_queue <Tarefas> inicio;
		for(int i = 0; i < 8; i++){
			inicio.push(tarefas[i]);
		}
	
		priority_queue <Tarefas> fim;
		for(int i = 0; i < 8; i++){
			inicio.push(tarefas[i]);
		}
		
		priority_queue <Tarefas> duracao;
		for(int i = 0; i < 8; i++){
			inicio.push(tarefas[i]);
		}
	
		greedy(inicio);
		greedy(fim);
		greedy(duracao);

	return 0;
}
