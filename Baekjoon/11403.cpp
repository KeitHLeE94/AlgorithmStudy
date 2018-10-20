//
// Created by Keith_Lee on 18/10/2018.
//
#include <iostream>
#include <queue>

using namespace std;
int map[100][100];
int N;

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    int answer[N][N];
    for(int i=0; i<N; i++){
        answer[i][i] = 1;
    }
}