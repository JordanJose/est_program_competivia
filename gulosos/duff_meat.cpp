#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, cont = 0, preco = 200;
    cin >> n;
    vector<int> a(n), p(n);
    for(int i =0; i < n; i++){
        cin >> a[i] >> p[i];
    }
    for(int i = 0; i < n; i++){
        preco = min(preco, p[i]);
        cont += a[i] * preco;
    }
    cout << cont << endl;
}