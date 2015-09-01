#include <stdio.h>
#include <stdlib.h>

/*
	Método da transposição -  Sempre que uma busca obtiver exito
	o valor encontrado é trocado com o valor anterior;

	cuidado! = quando dois valores são acessados alternadamente, pode ocorrer 
	dos valores ficarem trocando de posição entre si, sem que cheguem a primeira opção.
*/


void menu() {
	puts("1. Insert one value");
	puts("2. Search one value");
	puts("3. Print array");
	puts("4. exit");
}

void print_array(int array[], int size) {
	int i;
	for (i = 0; i < size; ++i) {
		printf("Posição %d, Valor: %d \n", i, array[i]);
	}
}

int sequential_search(int array[], int key, int size) {
	int i = 0;
	int result = -1;
	int swap = 0;

	for(i = 0; i < size; i++) {
		if(array[i] == key){
			if(i != 0) {
				swap = array[i-1];
				array[i-1] =  key;
				array[i] = swap;
			}
			
			result = i;
			break;
		}
	}

	return result;
}

void search(int array[], int size) {
	int key = 0; 

	puts("\nPlease insert the key you want to find");
	scanf("%d", &key);

	int result = sequential_search(array, key, size);

	if(result < 0) {
		puts("\nThe value was not found");
	}else {
		printf("\nThe value was found on %d position\n", result);
	}
}

int *init_array(int array[], int size, int i) { 

	if(i < size){
		printf("Insert %d element: \n", i+1);
		scanf("%d", &array[i]);
	}else{
		puts("The array is full");
	}

	return array;
}

int main() {
	int i = 0;
	int size;
	int option;

	puts("Please insert the size of the array:");
	scanf("%d", &size);

	int array[size];

	do {
		menu();
		scanf("%d", &option);

		switch(option) {
			case 1:
				init_array(array, size, i);
				i++;
				break;
			case 2:
				search(array, size);
				break;
			case 3:
				print_array(array, size);
				break;
			case 4:
				puts("Bye!");
				break;
		}

	}while(option != 4);

	return 0;
}