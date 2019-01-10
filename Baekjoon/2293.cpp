//
// Created by Keith_Lee on 10/01/2019.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;

int main(){
    cin >> N >> K;

    int DP[10001] = {0, };
    int coins[101];

    for(int i=1; i<=N; i++){
        cin >> coins[i];
    }

    DP[0] = 1;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            if(j >= coins[i]){
                DP[j] += DP[j - coins[i]];
            }
        }
    }

    cout << DP[K] << '\n';

    return 0;
}