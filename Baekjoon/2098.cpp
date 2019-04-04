//
// Created by Keith_Lee on 04/04/2019.
//

#include <iostream>
#include <string.h>

using namespace std;

int map[16][16] = {0, };
int DP[16][1 << 16] = {0, };

int N;

int cost(int index, int visit){
    if(visit == (1 << N) - 1){
        if(map[index][0] == 0){
            return 987654321;
        }

        return map[index][0];
    }

    int& result = DP[index][visit];

    if(result != -1){
        return result;
    }

    result = 999999999;

    for(int i=0; i<N; i++){
        if(visit & (1 << i) || map[index][i] == 0){
            continue;
        }

        result = min(result, cost(i, (visit | (1 << i))) + map[index][i]);
    }

    return result;
}

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    memset(DP, -1, sizeof(DP));

    cout << cost(0, 1) << '\n';

    return 0;
}