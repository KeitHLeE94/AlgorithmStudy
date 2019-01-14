//
// Created by Keith_Lee on 13/01/2019.
//

#include <iostream>
#include <memory.h>

using namespace std;

int N, M;

int map[501][501];
int DP[501][501];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int DFS(int startX, int startY){
    if(DP[startX][startY] != -1){
        return DP[startX][startY];
    }
    if(startX < 0 || startX >= N || startY < 0 || startY >= M){
        return 0;
    }
    if(startX == 0 && startY == 0){
        return 1;
    }

    DP[startX][startY] = 0;

    for(int i=0; i<4; i++){
        int nextX = startX + dx[i];
        int nextY = startY + dy[i];

        if(map[nextX][nextY] > map[startX][startY]){
            DP[startX][startY] += DFS(nextX, nextY);
        }
    }

    return DP[startX][startY];
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    memset(DP, -1, sizeof(DP));

    cout << DFS(N-1, M-1) << '\n';

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << DP[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}