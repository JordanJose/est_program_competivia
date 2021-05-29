#include <bits/stdc++.h>

using namespace std;

string renas[9] = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};

int main(){
    int soma = 0, A, indice;
    for(int i = 0; i < 9; i++){
        cin >> A;
        soma += A;
    }
    indice = (soma-1)%9;
    cout << renas[indice] << endl;
}