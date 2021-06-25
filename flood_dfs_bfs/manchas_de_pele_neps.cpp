#include <bits/stdc++.h>

using namespace std;

int N, M, ans;
int grid[1003][1003];
bool visited[1003][1003];

void floodfill(int i, int j){

    if(i < 0 || i >= N || j < 0 || j >= M){
        return;
    }

    if(grid[i][j] == 0 || visited[i][j]){
        return;
    }
    
    visited[i][j] = true;
    
    floodfill(i, j+1);
    floodfill(i+1, j);
    floodfill(i, j-1);
    floodfill(i-1, j);
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (grid[i][j] != 0 && !visited[i][j]){
                floodfill(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
    
}