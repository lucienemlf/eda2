#include <iostream>
#define COLUNA 12
#define LINHA 7
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;



int main(){
	int matriz[LINHA][COLUNA];
	vector<pair<int, int> > itens;
	itens.push_back(make_pair(0, 0)); // Sentinela
	itens.push_back(make_pair(1, 1)); r
	itens.push_back(make_pair(6, 2));
	itens.push_back(make_pair(18, 5));
	itens.push_back(make_pair(22, 6));
	itens.push_back(make_pair(28, 7));
	
	memset(matriz, 0, sizeof(matriz));	

	for(int i = 0; i < LINHA; i++){
		for(int j= 1; j < COLUNA; j++){
			if(itens[i].second > j){
				matriz[i][j] = matriz[i-1][j];
			}else{
			  if(i == 0){
					matriz[i][j] = 0;
				}else{
				// max(não levar, levar)
				matriz[i][j] = max(matriz[i-1][j], itens[i].first + matriz[i-1][j-itens[i].second]);
				}
			}
		}
	}

	for(int i = 0; i < LINHA; i++){
		for(int j = 1; j < COLUNA; j++){
			cout << matriz[i][j] << endl;
		}	
		cout << endl;
	}
	return 0;
}
