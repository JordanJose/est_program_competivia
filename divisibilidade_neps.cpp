#include <bits/stdc++.h>

using namespace std;

int calcula_resto(string numero, int m){
    int resto = 0, pot10;
    for(int i = 0; i < numero.size(); i++){
        pot10 = ((10%m * resto%m)%m);
        resto = (pot10%m + (numero[i]-'0')%m)%m;
    }
    return resto;
}

int main(){
    string numero;
    cin >> numero;
    if(!calcula_resto(numero, 2)){
        cout << "S" << endl;
    } else{
        cout << "N" << endl;
    }
    if(!calcula_resto(numero, 3)){
        cout << "S" << endl;
    } else{
        cout << "N" << endl;
    }
    if(!calcula_resto(numero, 5)){
        cout << "S" << endl;
    } else{
        cout << "N" << endl;
    }
}