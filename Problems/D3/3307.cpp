//
// Created by Keith_Lee on 08/01/2019.
//

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int T;

int main(){
    cin >> T;

    for(int test=1; test<=T; test++){
        int maximum = 0;
        int N;

        cin >> N;

        int numbers[N];
        int DP[N];

        for(int i=0; i<N; i++){
            cin >> numbers[i];
        }

        bzero(DP, sizeof(DP));

        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                if(numbers[j] < numbers[i]) continue;
                if(DP[j] >= DP[i] + 1) continue;
                DP[j] = DP[i] + 1; // 증가수열이면서 수열 count가 증가한다면 1 더해줌.
                maximum = max(maximum, DP[j]); // 최대값 갱신.
            }
        }

        cout << '#' << test << ' ' << maximum+1 << '\n';
    }
}