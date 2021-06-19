//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B

#include <bits/stdc++.h>

using namespace std;

vector <long long> a;

int p(long long idx, long long x){
    // cout << "Indice: " << idx << " Valor: " << a[idx] << " Numero: " << x << " Resposta: " << (a[idx] <= x) << endl;
    return a[idx] <= x;
}

int busca_binaria(long long lo, long long hi, long long x){
    long long md;
    while(lo < hi){
        md = lo + (hi-lo)/2;
        if(p(md, x)) hi = md;
        else lo = md + 1;
    }
    return lo; //indice do primeiro elemente em que o predicado é verdadeiro
}

int main(){
    long long n, k, aux, indc;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> aux;
        a.push_back(aux);
    }
    // for(int i = 0; i < a.size(); i++){
    //     cout << a[i] << ' ';
    // }
    for(int i = 0; i < k; i++){
        cin >> aux;
        indc = busca_binaria(0, (n-1), aux);
        // cout << "Aux: " << aux << " Indc: " << indc << endl;
        if(a[indc] > aux){
            cout << 0 << endl;
        } else{
            while(a[indc] <= aux && indc < n){
                indc++;
            }
            cout << indc << endl;
        }
    }
    return 0;
}