//
// Created by Keith_Lee on 24/03/2019.
//

#include <iostream>

using namespace std;

bool DP[101][1001];

int N, S, M;

int main(){
    cin >> N >> S >> M;

    DP[0][S] = true;

    for(int i=1; i<=N; i++){
        int gap;
        cin >> gap;

        for(int j=0; j<=M; j++){
            if(DP[i-1][j]){
                if(j - gap >= 0){
                    DP[i][j-gap] = true;
                }

                if(j + gap <= M){
                    DP[i][j+gap] = true;
                }
            }
        }
    }

    int result = -1;
    for(int i=0; i<=M; i++){
        if(DP[N][i]){
            result = i;
        }
    }

    cout << result << '\n';

    return 0;
}