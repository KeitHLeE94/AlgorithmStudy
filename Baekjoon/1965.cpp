//
// Created by Keith_Lee on 14/06/2019.
//

#include <iostream>

using namespace std;

int N;

int main(){
    int numbers[1000];

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> numbers[i];
    }

    int DP[1000] = {0, };

    DP[0] = 1;

    for(int i=1; i<N; i++){
        int max = 0;

        for(int j=0; j<i; j++){
            if(numbers[i] > numbers[j]){
                max = DP[j] > max ? DP[j] : max;
            }
        }

        DP[i] = max + 1;
    }

    int result = 0;

    for(int i=0; i<N; i++){
        result = DP[i] > result ? DP[i] : result;
    }

    cout << result << '\n';

    return 0;
}