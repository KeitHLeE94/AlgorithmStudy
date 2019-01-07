//
// Created by Keith_Lee on 07/01/2019.
//

#include <iostream>
#include <string.h>

using namespace std;

int min(int a, int b){
    return a > b ? b : a;
}

int main(){
    int N;
    int DP[1000000];

    cin >> N;

    bzero(DP, sizeof(DP));

    for(int i=2; i<=N; i++){
        DP[i] = DP[i-1] + 1; // 기본적으로 1 빼준다.

        if(i % 2 == 0){
            DP[i] = min(DP[i], DP[i/2] + 1); // 2로 나눠떨어지면 2로 나눴을때와 1뺐을때를 비교한다.
        }
        if(i % 3 == 0){
            DP[i] = min(DP[i], DP[i/3] + 1); // 3으로 나눠떨어지면 3으로 나눴을때와 1뺐을때를 비교한다.
        }
    }

    cout << DP[N] << '\n';

    return 0;
}