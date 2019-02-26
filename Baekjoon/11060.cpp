//
// Created by Keith_Lee on 26/02/2019.
//

#include <iostream>
#include <vector>
#include <strings.h>

using namespace std;

int N;

int map[1001];
int DP[1001];

int min(vector<int> v){
    int result = 99999;

    for(int i=0; i<v.size(); i++){
        if(result > v[i]){
            result = v[i];
        }
    }

    return result;
}

int main(){
    bzero(DP, sizeof(DP));
    bzero(map, sizeof(map));
    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> map[i];
    }

    for(int i=2; i<=N; i++){
        vector<int> temp;

        for(int j=1; j<i; j++){
            if(j + map[j] >= i){
                temp.push_back(DP[j] + 1);
            }
        }

        DP[i] = min(temp);
    }

    if(DP[N] == 99999){
        DP[N] = -1;
    }

    cout << DP[N] << '\n';

    return 0;
}