#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n, m, k, i, j, cont;
    bool flag;
    cin >> n >> m >> k;
    vector <long long int> app(n), apt(m);
    for(i = 0; i < n; i++){
        cin >> app[i];
    }
    for(i = 0; i < m; i++){
        cin >> apt[i];
    }
    sort(app.begin(), app.end());
    sort(apt.begin(), apt.end());
    cont = i = j = 0;
    while(i < m && j < n){
        flag = false;
        if(((apt[i] + k) >= app[j]) && ((apt[i] - k) <= app[j])){
            cont++;
            j++;
            i++;
        } else{
            if(apt[i] < app[j]){
                i++;
            } else if(apt[i] > app[j]){
                j++;
            }
        }
    }
    cout << cont << endl;
    return 0;
}