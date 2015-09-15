int parent(int child){
  int parent = floor(child/2);
}

int left_child(int parent){
  int left_child = parent*2;
  return left_child;
}

int right_child(int parent){
  int right_child = parent*2+1;
  return right_child;
}

void insert_heap(int array[], int element, int size){
  array[size] = element;
  int i = size-1;
  while(i>1 && array[parent(i)]<array[i]){
    swap(array[i],array[parent(i)]);
  }
}

// Retorna o maior filho
int get_max(int array[], int left, int right, int root){
	int max_child = 0;
	if(array[left] > array[root]){max_child = left;}
  else{max_child = root;}
	if(array[right] > array[max_child]){max_child = right;}
	return max_child;
}

void extract_max(int array[],int sort[], int size){
  sort[size] = array[1];
  array[1] = array[size-1];
  int i = 1;
  array = (int*) realloc (array,sizeof(array)-1);
  while(i<size){
    int large = get_max(array,left_child(i),right_child(i),i);
    if(array[i] < array[large]){
      swap(array[i],array[large]);
    }
  }
}


void heapify(int array[], int i, int array_size) {
	int left = 2*i;
	int right = 2*i + 1;
	int max_child = 0;

	if(left < array_size && right < array_size){
		max_child = get_max(array, left, right, i);
		if(max_child != i){
			swap(array[i], array[max_child]);
			heapify(array, max_child, array_size);
		}
	}
}
