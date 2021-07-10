#include<bits/stdc++.h>
using namespace std;
#define N 1024
// 1 bilhão pra cima ta ok
#define INF 1000000009

int n, m, u, v, w, processed[N], serv;
vector<int> dist;
vector<pair<int, int> > adj[N];

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        processed[i] = 0;
    }
    dist[serv] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, serv });

    while(pq.size()) {
        int u = pq.top().second;
        pq.pop();

        if (processed[u]) {
            continue;
        }
        processed[u] = 1;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({ -dist[v], v });
            }
        }
    }

    // return dist[n];
}

int main() {
    cin >> n >> m;
    dist.resize(n+1);
    while (m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> serv;
    dijkstra();
    sort(dist.begin()+1, dist.end());
    // for(int i = 1; i <= n; i++){
    //     cout << "Dist[" << i << "] = " << dist[i] << endl;
    // }
    cout << dist[n] - dist[2] << endl;

    return 0;
}