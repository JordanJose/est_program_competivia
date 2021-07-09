#include <bits/stdc++.h>

using namespace std;
int tam[10510],pai[10510];
struct pessoa{
    double x,y;
};

struct aresta{
    int u,v;
    double w;
};

void init(int n){
    for(int i = 0;i<=n;i++){
        pai[i]=i;
        tam[i]=1;
    }
}

int id(int n){
    return pai[n] = (n==pai[n]? n:id(pai[n]));
}

void join(int u,int v){
    u = id(u); v = id(v);
    if(u==v) return;
    if(tam[u]>tam[v]) swap(u,v);
    pai[u] = v;
    tam[v] += tam[u];
}
bool cmp(aresta a, aresta b){
    return a.w < b.w;
}
pessoa p[510];
aresta adj[500000];
int pd[510][510];
int main(){
    int casos,nump;
    cin >> casos;
    for(int i = 0; i<casos;i++){
        memset(pd,1,sizeof(pd));
        double mst = 0;
        cin >> nump;
        init(nump);
        for(int j = 1; j<=nump;j++){
            cin >> p[j].x >> p[j].y;
        }
        int pos = 0;
        for(int j = 1;j<=nump;j++){
            for(int k = 1;k<=nump;k++){
                if(k!=j && (pd[j][k] or pd[k][j])){
                    pd[j][k] = 0;
                    pd[k][j] = 0;
                    adj[pos].u = j;
                    adj[pos].v = k;
                    adj[pos].w = (sqrt(pow((p[k].x-p[j].x),2)+pow((p[k].y-p[j].y),2)));
                    pos++;
                }
            }
        }
        sort(adj,adj+pos,cmp);
        for(int j = 0;j<pos;++j){
            if(id(adj[j].u) != id(adj[j].v)){
                join(adj[j].u,adj[j].v);
                mst += adj[j].w;
            }
        }
        cout.precision(2);
        cout << fixed << mst/100.0 << endl;
    }
    return 0;
}