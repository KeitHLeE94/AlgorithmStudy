//
// Created by Keith_Lee on 08/01/2019.
//

#include <iostream>
#include <strings.h>

using namespace std;

int main(){
    int N;

    cin >> N;

    unsigned long long DP[101][11];
    bzero(DP, sizeof(DP));

    for(int i=1; i<10; i++){
        DP[1][i] = 1;
    }

    for(int i=2; i<=N; i++) {
        DP[i][0] = DP[i-1][1];
        for(int j=1; j<10; j++){
            DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1]) % 1000000000;
        }
    }

    unsigned long long sum = 0;
    for(int i=0; i<10; i++){
        sum += DP[N][i];
    }
    cout << (sum % 1000000000) << '\n';

    return 0;
}