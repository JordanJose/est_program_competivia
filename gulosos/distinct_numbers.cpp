#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N, i, cmp, cont;
    cin >> N;
    vector<long long int> numeros(N);
    for(i = 0; i < N; i++){
        cin >> numeros[i];
    }
    sort(numeros.begin(), numeros.end());
    cmp = numeros[0];
    cont = 1;
    for(i = 0; i < N; i++){
        if(numeros[i] != cmp){
            cmp = numeros[i];
            cont++;
        }
    }
    cout << cont << endl;
    return 0;

}