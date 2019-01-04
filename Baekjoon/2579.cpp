//
// Created by Keith_Lee on 04/01/2019.
//

#include <iostream>

using namespace std;

int N;

int max(int a, int b){
    return (a > b) ? a : b;
}

int main(){
    cin >> N;

    int DP[N+1];
    int score[N+1];

    for(int i=1; i<=N; i++){
        cin >> score[i];
    }

    DP[1] = score[1];
    DP[2] = max(score[1] + score[2], score[2]);
    DP[3] = max(score[1] + score[3], score[2] + score[3]);

    for(int i=4; i<=N; i++){
        DP[i] = max(DP[i-2] + score[i], DP[i-3] + score[i] + score[i-1]);
    }

    cout << DP[N] << '\n';

    return 0;
}