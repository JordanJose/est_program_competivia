#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, cont = 0;
    int disp[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, (1*1024), (2*1024), (4*1024), (8*1024)};
    cin >> T;

    for(int i = 13; i >= 0; i--){
        while(disp[i] <= T){
            T -= disp[i];
            cont++;
        }
    }
    cout << cont << endl;
    return 0;
}