//
// Created by Keith_Lee on 2018. 9. 23..
//
#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int set[N];

    for(int i=0; i<N; i++){
        cin >> set[i];
    }

    for(int i=0; i<(1 << N); i++){
        for(int j=0; j<N; j++){
            if(i & (1 << j)){
                cout << set[j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}