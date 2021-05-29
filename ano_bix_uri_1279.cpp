#include <bits/stdc++.h>

using namespace std;

int calcula_resto(string numero, int m){
    int resto = 0, pot10;
    for(int i = 0; i < numero.size(); i++){
        pot10 = ((10%m * resto%m)%m);
        resto = (pot10 + (numero[i]-'0')%m)%m;
    }
    return resto;
}

// ano bissexto = div por 4 e nao div por 100 ou divisivel por 400
//huluculu = div por 15
//bulukulu = div por 55 e bissexto

int main(){
    string ano;
    int flag, flag_bi, print = 0;
    while(cin >> ano){

        if(print++ > 0){
            cout << endl;
        }

        flag = flag_bi = 0;

        if(!calcula_resto(ano, 400)){
            cout << "This is leap year." << endl;
            flag = 1;
            flag_bi = 1;
        } else if(!calcula_resto(ano, 4) && calcula_resto(ano, 100)){
            cout << "This is leap year." << endl;
            flag = 1;
            flag_bi = 1;
        }
        if(!calcula_resto(ano, 15)){
            cout << "This is huluculu festival year." << endl;
            flag = 1;
        }
        if(flag_bi){
            if(!calcula_resto(ano, 55)){
                cout << "This is bulukulu festival year." << endl;
                flag = 1;
            }
        }
        if(!flag){
            cout << "This is an ordinary year." << endl;
        }
    }
    return 0;
}