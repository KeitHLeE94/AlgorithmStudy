//
// Created by Keith_Lee on 25/02/2019.
//

#include <iostream>
#include <strings.h>

using namespace std;

int N;

long long zoo(int n){
    long long DP[n+1];
    bzero(DP, sizeof(DP));

    DP[0] = 0;
    DP[1] = 3;
    DP[2] = 7;

    for(int i=3; i<=n; i++){
        DP[i] = (2 * DP[i-1] + DP[i-2]) % 9901;
    }

    return DP[n];
}

int main(){
    cin >> N;

    cout << zoo(N) << '\n';
}