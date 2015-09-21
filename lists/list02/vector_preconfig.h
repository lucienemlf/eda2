/* Lib to initialize a vector */

#define TOP_RANGE 10000
#define BOT_RANGE 10

using namespace std;

// Generate radom number between TOP_RANGE and BOT_RANGE
int random_num(){
  srand(time(NULL));
  int randm = rand() % TOP_RANGE + BOT_RANGE;
  return randm;
}

// Alocates a random number on all vector
void preconfig(int vector[], int max_size){
  srand (time(NULL)); // Initialize random seed
  for(int i=0 ; i<max_size ; i++){
    vector[i] = random_num();
  }
}

// Print vector
void print_vector(int vector[], int max_size){
  for(int i=0 ; i<max_size ; i++){
    cout << vector[i] << " ";
  }
  cout << endl;
}
