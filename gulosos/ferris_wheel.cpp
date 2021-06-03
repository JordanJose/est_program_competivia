#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long n, x, i, sum, cont, aux, j;
    cin >> n >> x;
    vector<long long> p(n);
    for(i = 0; i < n; i++){
        cin >> p[i];
    }
    sum = i = cont = aux = 0;
    j = n-1;
    sort(p.begin(), p.end());
    while(i <= j){
        if(i == j){
            cont++;
            break;
        }
        if((p[i] + p[j]) > x){
            cont++;
            j--;
        } else if((p[i] + p[j]) <= x){
            cont++;
            i++;
            j--;
        }
    }
    cout << cont << endl;
}