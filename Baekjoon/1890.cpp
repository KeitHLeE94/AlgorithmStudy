//
// Created by Keith_Lee on 26/02/2019.
//

#include <iostream>

using namespace std;

int N;

int map[101][101] = {-1, };
long long DP[101][101] = {0, };

int main(){
    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }

    DP[1][1] = 1;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i == j && i == 0){
                continue;
            }

            for(int k=0; k<j; k++){
                if(k + map[i][k] == j){
                    DP[i][j] += DP[i][k];
                }
            }

            for(int k=0; k<i; k++){
                if(k + map[k][j] == i){
                    DP[i][j] += DP[k][j];
                }
            }
        }
    }

//    for(int i=1; i<=N; i++){
//        for(int j=1; j<=N; j++){
//            cout << DP[i][j] << ' ';
//        }
//        cout << '\n';
//    }

    cout << DP[N][N] << '\n';
}