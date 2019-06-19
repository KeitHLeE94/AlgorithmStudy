//
// Created by Keith_Lee on 19/06/2019.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;

int main(){
    cin >> N;
    cin >> M;

    int vips[41] = {0, };

    for(int i=0; i<M; i++){
        int vip;
        cin >> vip;

        vips[vip] = vip;
    }

    int DP[41] = {0, };

    DP[1] = 1;
    DP[2] = 2;

    for(int i=3; i<=40; i++){
        DP[i] = DP[i-1] + DP[i-2];
    }

    int continuous = 0;
    vector<int> toMul;

    for(int i=1; i<=N; i++){
        if(vips[i] == 0){
            continuous++;
        }
        else{
            if(continuous != 0){
                toMul.push_back(continuous);
                continuous = 0;
            }
        }
    }
    if(continuous != 0){
        toMul.push_back(continuous);
    }

    int result = 1;
    if(!toMul.empty()){
        for(int i=0; i<toMul.size(); i++){
            result *= DP[toMul[i]];
        }
    }

    cout << result << '\n';

    return 0;
}