//
// Created by Keith_Lee on 30/03/2019.
//

#include <iostream>
#include <strings.h>

using namespace std;

int T;
int stickers[2][100001] = {0, };
int DP[100001][3] = {0, };

int main(){
    cin >> T;

    for(int test=0; test<T; test++){
        int N;

        cin >> N;

        bzero(stickers, sizeof(stickers));
        bzero(DP, sizeof(DP));

        for(int i=0; i<2; i++){
            for(int j=1; j<=N; j++){
                cin >> stickers[i][j];
            }
        }

        for(int i=1; i<=N; i++){
            DP[i][0] = max(max(DP[i-1][0], DP[i-1][1]), DP[i-1][2]);
            DP[i][1] = max(DP[i-1][0], DP[i-1][2]) + stickers[0][i];
            DP[i][2] = max(DP[i-1][0], DP[i-1][1]) + stickers[1][i];
        }

        cout << max(max(DP[N][0], DP[N][1]), DP[N][2]) << '\n';
    }

    return 0;
}