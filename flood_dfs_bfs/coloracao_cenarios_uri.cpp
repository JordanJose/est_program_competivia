#include <bits/stdc++.h>

#define TAM 1050

using namespace std;

int N, M, ans;
char grid[TAM][TAM];
int visited[TAM][TAM];

void floodfill(int i, int j){

    if(i < 0 || i >= N || j < 0 || j >= M){
        return;
    }

    if(grid[i][j] == 'o' || visited[i][j]){
        return;
    }
    
    visited[i][j] = 1;
    
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
            if (grid[i][j] != 'o' && !visited[i][j]){
                floodfill(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
    
}