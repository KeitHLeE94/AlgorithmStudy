//
// Created by Keith_Lee on 30/03/2019.
//

#include <iostream>

using namespace std;

int main(){
    int N;

    long long DP[1001][2] = {0, };

    DP[1][0] = 1;
    DP[1][1] = 0;
    DP[2][0] = 1;
    DP[2][1] = 1;

    cin >> N;

    for(int i=3; i<=N; i++){
        DP[i][0] = (DP[i-1][0] + DP[i-1][1]) % 10007;
        DP[i][1] = DP[i-1][0] % 10007;
    }

    cout << (DP[N][0] + DP[N][1]) % 10007 << '\n';

    return 0;
}