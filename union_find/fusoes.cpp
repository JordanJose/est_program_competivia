#include <bits/stdc++.h>

using namespace std;

int pai[110000];
void inicia(int n){
    for(int i = 1;i<=n;++i) pai[i] = i;
}
int id(int n){
    return pai[n] = (n==pai[n]? n:id(pai[n]));
}
void junta(int u, int v){
    u = id(u);
    v = id(v);
    if(u!=v){
        pai[u]=v;
    }
}
char consulta(int u, int v){
    u = id(u);
    v = id(v);
    if(u!=v){
        return 'N';
    }
    else return 'S';
}
int main(){
    int bancos,ope,x,y;
    char diga;
    cin >> bancos >> ope;
    inicia(bancos+1);
    for(int k = 0; k<ope; ++k){
        cin >> diga >> x >> y;
        if(diga == 'F'){
            junta(x,y);
        }
        else{
            cout << consulta(x,y) << endl;
        }
    }
    return 0;
}