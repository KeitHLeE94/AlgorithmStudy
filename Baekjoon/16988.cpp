//
// Created by Keith_Lee on 05/03/2019.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;

int map[20][20];
int tempMap[20][20];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void BFS(){
    int countMap[20][20];

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            countMap[i][j] = tempMap[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(countMap[i][j] == 2){
                for(int k=0; k<4; k++){
                    int nextX = i + dx[k];
                    int nextY = j + dy[k];

                    if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M){
                        if(countMap[nextX][nextY] == 0){
                            countMap[i][j] = 3;
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << countMap[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void DFS(int count){
    if(count == 2){
        BFS();
        return;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(tempMap[i][j] == 0){
                tempMap[i][j] = 1;
                DFS(count+1);
                tempMap[i][j] = 0;
            }
        }
    }
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];

            tempMap[i][j] = map[i][j];
        }
    }

    DFS(0);

    return 0;
}