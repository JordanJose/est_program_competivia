#include <bits/stdc++.h>
#define MAXN 1000123
using namespace std;
long long pai[MAXN],tam[MAXN];

void init(int n){
    for(int i = 0;i<n;i++){
        pai[i] = i;
        tam[i] = 1;
    }
}

struct aresta{
    int u,v,w;
};
aresta adj[MAXN];
bool cmp(aresta a, aresta b){
    return (a.w < b.w);
}

int id(int n){
    return pai[n]=(n==pai[n] ? n:id(pai[n]));
}

void join(int u, int v){
    u = id(u); v = id(v);
    if(u==v) return;
    if(tam[u]>tam[v]) swap(u,v);
    pai[u] = v;
    tam[v] += tam[u];
}

int main(){
    long long m,n,soma=0,mst;
    while(cin >> m >> n && (m or n)){
        soma=0;
        mst=0;
        init(m);
        for(int i = 0;i<n;i++){
            cin >> adj[i].u >> adj[i].v >> adj[i].w;
        }
        sort(adj,adj+n,cmp);
        for(int i = 0;i<n;i++){
            if(id(adj[i].u)!=id(adj[i].v)){
                join(adj[i].u,adj[i].v);
                mst+= adj[i].w;
            }
        }
        cout << mst << endl;
    }
    return 0;
}