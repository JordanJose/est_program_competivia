#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<unsigned long long, unsigned long long> a, pair<unsigned long long, unsigned long long> b){
    return a.first < b.first;
}

int main(){
    unsigned long long n, x, i, j;
    cin >> n >> x;
    vector<pair<unsigned long long, unsigned long long>> a(n);
    for(i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end(), cmp);
    i = 0;
    j = n-1;
    while(i < j){
        if(a[i].first + a[j].first > x){
            j--;
        } else if(a[i].first + a[j].first < x){
            i++;
        }
        if(a[i].first + a[j].first == x && i != j){
            cout << a[i].second << " " << a[j].second << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}