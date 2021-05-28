#include <bits/stdc++.h>

using namespace std;

int main(){

    int i;
    unsigned long long int resto,cont,num,n;
    while(cin >> n){
        num = 1;
        resto = 1;
        for(i=0;resto!=0;i++){
            resto = num%n;
            num = ((num*10)+1)%n;
        }
            cout << i << endl;
    }
    return 0;
}