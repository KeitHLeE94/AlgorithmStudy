//
// Created by Keith_Lee on 30/03/2019.
//

#include <iostream>

using namespace std;

int T;
long long DP[101] = {0, };

int main(){
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;

    for(int i=4; i<=100; i++){
        DP[i] = DP[i-2] + DP[i-3];
    }

    cin >> T;

    for(int test=0; test<T; test++){
        int N;

        cin >> N;

        cout << DP[N] << '\n';
    }

    return 0;
}