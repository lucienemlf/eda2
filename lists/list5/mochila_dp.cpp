#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
// Falta otimizar, para quando achar um valor que já foi calculado não calcular de novo 

int values[12][6];


int knapsack(int capacity, int item, vector<pair<int, int> > itens)
{
    // Base Case
    if (item == 0 || capacity == 0)
       return 0;
  
    if (values[item][capacity] != -1)
       return values[item][capacity];

    // If weight of the nth item is more than Knapsack capacity W, then
    // this item cannot be included in the optimal solution
	if(itens[item-1].second > capacity){
			return knapsack(capacity, item-1, itens);
	}
	
    // Return the maximum of two cases:  (1) not included (2) nth item included
	else{
		int result = max(knapsack(capacity, item-1, itens), itens[item-1].first + knapsack(capacity-itens[item-1].second, item-1, itens));
		values[item][capacity] = result; 
		return result;
	}

}
	

int main(){
	vector<pair<int, int> > itens;
	int max_weight  = 11; // 0 1 2 ... 11
  	int qtd_itens = 5; 
	
	itens.push_back(make_pair(0, 0)); // Sentinela
	itens.push_back(make_pair(1, 1)); 
	itens.push_back(make_pair(6, 2));
	itens.push_back(make_pair(18, 5));
	itens.push_back(make_pair(22, 6));
	itens.push_back(make_pair(28, 7));
	
	memset(values, -1, sizeof(values));	
	
	int result  = knapsack(max_weight, qtd_itens, itens);
 	cout << "Valor: " << result << endl; 
 
	return 0;
}
