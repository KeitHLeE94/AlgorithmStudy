//
// Created by Keith_Lee on 05/03/2019.
//

#include <iostream>
#include <queue>
#include <strings.h>
#include <memory.h>

using namespace std;

int N, M;

int map[20][20];
int tempMap[20][20];
bool visit[20][20];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int maxValue = 0;
bool finish = false;

int BFS(int x, int y){
    int count = 0;

    queue<pair<int, int>> Queue;

    memcpy(map, tempMap, sizeof(tempMap));

    Queue.push(make_pair(x, y));

    count++;

    while(!Queue.empty()){
        int currentX = Queue.front().first;
        int currentY = Queue.front().second;
        Queue.pop();

        for(int i=0; i<4; i++){
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M){
                if(!visit[nextX][nextY] && map[nextX][nextY] == 2){
                    visit[nextX][nextY] = true;
                    count++;
                    Queue.push(make_pair(nextX, nextY));
                }
                else if(map[nextX][nextY] == 0){
                    finish = true;
                }
            }
        }
    }

    if(finish){
        return 0;
    }

    return count;
}

void DFS(int count){
    if(count == 2){
        int temp = 0;
        bzero(visit, sizeof(visit));

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(!visit[i][j] && tempMap[i][j] == 2){
                    finish = false;
                    visit[i][j] = true;
                    temp += BFS(i, j);

                    maxValue = maxValue < temp ? temp : maxValue;
                }
            }
        }

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

    cout << maxValue << '\n';

    return 0;
}