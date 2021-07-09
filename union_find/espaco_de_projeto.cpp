#include <bits/stdc++.h>

using namespace std;

int pai[1000152],tam[1000152];


void init(int n){
    for(int i = 1;i<=n;i++){
        pai[i] = i;
        tam[i] = 1;
    }
}

int id(int n){
    return pai[n] = (pai[n]==n? n:id(pai[n]));
}

void join(int u,int v){
    u = id(u); v = id(v);
    if(u==v) return;
    if(tam[u]>tam[v]) swap(u,v);
    pai[u] = v;
    tam[v] += tam[u];
}

struct aresta{
    int u,v,w;
}; aresta vt[1000152];

bool cmpM(aresta a, aresta b){
    return a.w < b.w;
}

bool cmpG(aresta a, aresta b){
    return a.w > b.w;
}

int main(){
    int gal,maior=0,big = 0,low=0;
    cin >> gal;
    for(int i = 0;i<gal;i++){
        cin >> vt[i].u;
        if(vt[i].u>maior) maior = vt[i].u;
        cin >> vt[i].v;
        if(vt[i].v > maior) maior = vt[i].v;
        cin >> vt[i].w;
    }
    init(maior);
    sort(vt,vt+gal,cmpG);
    for(int i = 0;i<gal;++i){
        if(id(vt[i].u)!=id(vt[i].v)){
            join(vt[i].u,vt[i].v);
            big += vt[i].w;
        }
    }
    init(maior);
    sort(vt,vt+gal,cmpM);
    for(int i = 0;i<gal;++i){
        if(id(vt[i].u)!=id(vt[i].v)){
            join(vt[i].u,vt[i].v);
            low += vt[i].w;
        }
    }
    cout << big << endl << low << endl;
    return 0;
}