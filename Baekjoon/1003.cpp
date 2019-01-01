//
// Created by Keith_Lee on 01/01/2019.
//
#include <iostream>

using namespace std;

int T;
int DP[41][2];

void fibonacci(int n){
    if(n == 0){
        DP[n][0]++;
    }
    else if(n == 1){
        DP[n][1]++;
    }
    else{
        DP[n][0] = DP[n-1][0] + DP[n-2][0];
        DP[n][1] = DP[n-1][1] + DP[n-2][1];
    }
}

int main(){
    for(int i=0; i<41; i++){
        fibonacci(i);
    }

    cin >> T;

    int N;

    for(int i=0; i<T; i++){
        cin >> N;
        cout << DP[N][0] << ' ' << DP[N][1] << '\n';
    }

    return 0;
}