#include <bits/stdc++.h>

using namespace std;

vector <unsigned int> vetor;

int busca(int num,int tam){
    for(int i = 0;i<tam;i++){
        if(vetor[i]==num) return i;
    }
    return -1;
}

int main(){
    int casos=1,n,q,numero;
    while(cin >> n >> q && (n || q)){
        vetor.resize(n);
        for(int i = 0;i<n;i++){
            cin >> numero;
            vetor[i]=numero;
        }
        sort(vetor.begin(),vetor.end());
        cout << "CASE# " << casos << ":"<< endl;
        casos++;
        for(int i = 0; i<q;i++){
            cin >> numero;
            int eita = busca(numero,n)+1;
            if(eita){
                cout << numero << " found at " << eita << endl;
            }
            else cout << numero << " not found" << endl;
        }
    }
    return 0;
}