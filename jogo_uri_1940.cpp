#include <bits/stdc++.h>

using namespace std;

int jogadores[500];

int main(){
    int J, R, X, max, vencedor;
    cin >> J >> R;
    for(int i = 0; i < (J*R); i++){
        cin >> X;
        jogadores[(i%J)] += X;
    }
    max = 0;
    for(int i = 0; i < J; i++){
        if(jogadores[i] >= max){
            max = jogadores[i];
            vencedor = (i+1);
        }
    }
    cout << vencedor << endl;
}