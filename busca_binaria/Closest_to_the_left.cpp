//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B

#include <bits/stdc++.h>

using namespace std;

vector <long long> a;

int p(long long idx, long long x){
    // cout << "Indice: " << idx << " Valor: " << a[idx] << " Numero: " << x << " Resposta: " << (a[idx] <= x) << endl;
    return a[idx] <= x;
}

long long busca_binaria(long long lo, long long hi, long long x){
    long long md;
    while(lo < hi){
        md = lo + (hi-lo)/2;
        if(p(md, x)) lo = md + 1;
        else hi = md;
    }
    return lo;
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
        indc = busca_binaria(0, n, aux);
        // cout << "Aux: " << aux << " Indc: " << indc << endl;
        cout << indc << endl;
    }
    return 0;
}