//https://www.urionlinejudge.com.br/judge/pt/problems/view/1520

#include <bits/stdc++.h>

using namespace std;

vector <long long> a;

int p(long long idx, long long x){
    return a[idx] >= x;
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

int ultima_posicao(int idx, int x){
    while(a[idx] == x){
        idx++;
    }
    return idx;
}

int main(){
    int N, X, Y, Num;
    long long int Tam;
    while(cin >> N){
        Tam = 0;
        for(int i = 0; i < N; i++){
            cin >> X >> Y;
            for(int j = X; j <= Y; j++){
                a.push_back(j);
                Tam++;
            }
        }
        sort(a.begin(), a.end());
        cin >> Num;
        int indc = busca_binaria(0, Tam-1, Num);
        if(a[indc] == Num){
            cout << Num << " found from " << indc << " to " << (ultima_posicao(indc, Num)-1) << endl;
        } else{
            cout << Num << " not found" << endl;
        }
        a.clear();
    }
    return 0;
}