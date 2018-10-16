//
// Created by Keith_Lee on 14/10/2018.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int result;
long long DP[30][30];

long long ffind(int wNum, int hNum){
    if((wNum == 1 && hNum == 0) || wNum == 0){
        return 1;
    }

    long long &ret = DP[wNum][hNum];
    if(ret != 0){
        return ret;
    }

    ret = 0;
    ret += ffind(wNum-1, hNum+1);
    if(hNum > 0){
        ret += ffind(wNum, hNum-1);
    }

    return ret;
}

int main(){
    memset(DP, 0, sizeof(DP));

    while(true){
        cin >> N;
        if(N == 0){
            break;
        }
        cout << ffind(N-1, 1) << '\n';
    }

    return 0;
}