#include <bits/stdc++.h>

using namespace std;

#define M ((int)1e9 + 7);

int main(){
    string abc;
    unsigned long long int resto = 0, pot26;
    long long int MOD = M;
    while(cin >> abc){
        resto = 0;
        for(int i = 0; i < abc.size(); i++){
            pot26 = (((26 % MOD) * (resto % MOD))%MOD);
            resto = ((pot26 % MOD) + ((abc[i]-'A')%MOD))%MOD;
        }
        cout << resto << endl;
    }
    return 0;
}