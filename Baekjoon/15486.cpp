//
// Created by Keith_Lee on 14/10/2018.
//
#define MAX 1500001
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int DP[MAX];
int T[MAX];
int P[MAX];
int N, result;

int main(){
    cin >> N;

    memset(DP, 0, sizeof(DP));

    for(int i=1; i<=N; i++){
        cin >> T[i] >> P[i];
    }

    for(int i=1; i<=N+1; i++){
        result = max(DP[i], result);

        if(i + T[i] > N+1){
            continue;
        }
        DP[i + T[i]] = max(result + P[i], DP[i + T[i]]);
    }

    cout << result << '\n';

    return 0;
}
