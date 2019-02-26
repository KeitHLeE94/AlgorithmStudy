//
// Created by Keith_Lee on 26/02/2019.
//

#include <iostream>
#include <vector>
#include <strings.h>

using namespace std;

int N;
long long DP[101];

long long max(vector<long long> v){
    long long result = 0;

    for(int i=0; i<v.size(); i++){
        if(v[i] > result){
            result = v[i];
        }
    }

    return result;
}

int main(){
    cin >> N;

    bzero(DP, sizeof(DP));

    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;
    DP[4] = 4;

    for(int i=5; i<=N; i++){
        vector<long long> temp;
        for(int j=3; j<i; j++){
            temp.push_back(DP[i-j]*(j-1));
        }

        DP[i] = max(temp);
    }

    cout << DP[N] << '\n';

    return 0;
}