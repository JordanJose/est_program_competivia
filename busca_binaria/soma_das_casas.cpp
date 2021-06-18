//https://neps.academy/br/exercise/255

#include <bits/stdc++.h>

using namespace std;

int busca_binaria(int* vet, int tam, int val){
    int achou = 0;
    int meio;
    int inicio = 0;
    int fim = tam;
        while (!achou){
            if (fim < inicio){
                return -1;
            }
            meio = (int)(inicio+fim)/(2);
            if(vet[meio] == val){
                return meio;
            }
            if(vet[meio] > val){
                fim = meio-1;
            }
            else{
                inicio = meio+1;
            }
        }
}

int main(){

    int num_casas, soma, A, B, other_num;
    cin >> num_casas;
    int casas[num_casas];
    for(int i = 0; i < num_casas; i++){
        cin >> A;
        casas[i] = A;
    }
    cin >> soma;
    for(int i = 0; i < num_casas; i++){
        other_num = soma - casas[i];
        A = casas[i];
        B = busca_binaria(casas, num_casas, other_num);
        if(B != -1){
            B = casas[B];
            break;
        }
    }
    cout << min(A, B) << ' ' << max(A, B) << endl;

    return 0;
}