/* Lib to initialize a vector */

#define TOP_RANGE 10000
#define BOT_RANGE 10

// Alocates a random number on all vector
void preconfig(int vector[], int max_size){
  srand (time(NULL)); // Initialize random seed
  for(int i=0 ; i<max_size ; i++){
    int randm = rand() % TOP_RANGE + BOT_RANGE;
    vector[i] = randm;
  }
}
