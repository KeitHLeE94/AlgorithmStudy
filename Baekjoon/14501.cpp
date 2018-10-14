//
// Created by Keith_Lee on 14/10/2018.
//
#define MAX 16
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int result;
int T[MAX];
int P[MAX];
int DP[MAX];

int main(){
    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> T[i] >> P[i];
    }

    for(int i=1; i<=N+1; i++){
        result = max(result, DP[i]);

        if(T[i] + i > N+1){
            continue;
        }

        DP[i + T[i]] = max(result + P[i], DP[i + T[i]]);
    }

    cout << result << '\n';

    return 0;
}