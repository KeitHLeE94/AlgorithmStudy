//
// Created by Keith_Lee on 28/03/2019.
//

#include <iostream>

using namespace std;

int T;
long long DP[5001] = {0, };

int main(){
    cin >> T;

    DP[2] = 1;

    for(int i=4; i<=5000; i++){
        if(i % 2 == 0){
            DP[i] = DP[i-2];

            for(int j=0; j<=i-2; j+=2){
                DP[i] += (DP[j] % 1000000007);
            }

            DP[i] = DP[i] % 1000000007;
        }
        else{
            continue;
        }
    }

    for(int test=0; test<T; test++){
        int L;
        cin >> L;

        cout << DP[L] << '\n';
    }

    return 0;
}