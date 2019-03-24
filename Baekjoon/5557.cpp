//
// Created by Keith_Lee on 22/03/2019.
//

#include <iostream>

using namespace std;

long long DP[101][21] = {0, };

int main(){
    int N;

    cin >> N;

    int start;
    cin >> start;

    DP[0][start] = 1;

    for(int i=1; i<N-1; i++){
        int nextNum;
        cin >> nextNum;

        for(int j=0; j<=20; j++){
            if(DP[i-1][j] > 0){
                if(j - nextNum >= 0){
                    DP[i][j-nextNum] += DP[i-1][j];
                }
                if(j + nextNum <= 20){
                    DP[i][j+nextNum] += DP[i-1][j];
                }
            }
        }
    }

    int resultNum;
    cin >> resultNum;

    cout << DP[N-2][resultNum] << '\n';

    return 0;
}