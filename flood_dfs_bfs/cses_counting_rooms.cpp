#include <bits/stdc++.h>

using namespace std;

int  n, m, answer;
char grid[1003][1003];
bool visited[1003][1003];

void floodfill(int i, int j){

    if(i < 0 || i >= n || j < 0 || j >= m){
        return;
    }

    if(grid[i][j] == '#' || visited[i][j]){
        return;
    }
    
    visited[i][j] = true;
    
    floodfill(i, j+1);
    floodfill(i+1, j);
    floodfill(i, j-1);
    floodfill(i-1, j);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (grid[i][j] != '#' && !visited[i][j]){
                floodfill(i, j);
                answer++;
            }
        }
    }
    cout << answer << endl;
    return 0;
}