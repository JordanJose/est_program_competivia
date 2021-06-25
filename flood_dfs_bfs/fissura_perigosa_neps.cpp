#include <bits/stdc++.h>

using namespace std;

int N, F;
string str;
int grid[1003][1003];
bool visited[1003][1003];

void floodfill(int i, int j){

    if(i < 0 || i >= N || j < 0 || j >= N){
        return;
    }

    if(grid[i][j] > F || visited[i][j]){
        return;
    }
    
    visited[i][j] = true;
    grid[i][j] = 0;
    
    floodfill(i, j+1);
    floodfill(i+1, j);
    floodfill(i, j-1);
    floodfill(i-1, j);
}

int main(){
    cin >> N >> F;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < N; j++){
            grid[i][j] = (str[j] - '0');
        }
    }

    floodfill(0,0);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j])
                cout << grid[i][j];
            else
                cout << '*';
        }
        cout << endl;
    }

    return 0;
    
}