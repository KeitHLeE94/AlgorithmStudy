//
// Created by Keith_Lee on 03/01/2019.
//

#include <iostream>
#include <cstring>

using namespace std;

int n;
int maximum = 0;

int max(int a, int b){
    return (a > b) ? a : b;
}

int main(){
    cin >> n;

    int DP[n+1][n+1];
    int tree[n+1][n+1];

    bzero(DP, sizeof(DP));
    bzero(tree, sizeof(tree));

    int inputNum;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> inputNum;
            tree[i][j] = inputNum;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            DP[i][j] = max(DP[i-1][j-1], DP[i-1][j]) + tree[i][j];

            if(maximum < DP[i][j]){
                maximum = DP[i][j];
            }
        }
    }

    cout << maximum << '\n';

    return 0;
}