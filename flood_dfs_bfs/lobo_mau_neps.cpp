#include <bits/stdc++.h>

using namespace std;

int N, M, ovelha, lobo, ovelhas_vivas, lobos_vivos;
char grid[1003][1003];
string str;
bool visited[1003][1003];

void floodfill(int i, int j){

    if(i < 0 || i >= N || j < 0 || j >= M){
        return;
    }

    if(grid[i][j] == '#' || visited[i][j]){
        return;
    }

    if(grid[i][j] == 'k'){
        ovelha++;
    } else if(grid[i][j] == 'v'){
        lobo++;
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
        cin >> str;
        for(int j = 0; j < M; j++){
            grid[i][j] = str[j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(grid[i][j] != '#' && !visited[i][j]){
                ovelha = 0;
                lobo = 0;
                floodfill(i, j);
                if(ovelha <= lobo){
                    lobos_vivos += lobo;
                } else{
                    ovelhas_vivas += ovelha;
                }
            }
        }
    }

    cout << ovelhas_vivas << ' ' << lobos_vivos << endl;

    return 0;
    
}