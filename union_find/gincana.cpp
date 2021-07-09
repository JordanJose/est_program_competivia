#include <bits/stdc++.h>

using namespace std;

int pai[1000123],cont;

void init(int n){
    for(int i=1;i<=n;++i) pai[i]=i;
}

int id(int n){
    return pai[n]=(n==pai[n] ? n:id(pai[n]));
}

void join(int u,int v){
    u=id(u);
    v=id(v);
    if(u!=v){
        pai[u]=v;
        ++cont;
    }
}

int main(){
    int n,m,u,v,totcon;
    cin>>n>>m;
    init(n+1);
    totcon=n;
    for(int i=0;i<m;++i){
        cin>>u>>v;
        join(u,v);
    }
    cout<<totcon-cont<<endl;

    return 0;
}