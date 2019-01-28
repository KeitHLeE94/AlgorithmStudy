//
// Created by Keith_Lee on 28/01/2019.
//

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N;
char map[101][101];
bool visit[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int normalResult = 0;
int redGreenResult = 0;

void BFS_normal(int startX, int startY){
    queue<pair<int, int>> Queue;

    Queue.push(make_pair(startX, startY));
    visit[startX][startY] = true;

    while(!Queue.empty()){
        int currentX = Queue.front().first;
        int currentY = Queue.front().second;
        Queue.pop();

        for(int i=0; i<4; i++){
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if(nextX >= 1 && nextX <= N && nextY >= 0 && nextY <= N){
                if(map[startX][startY] == 'R'){
                    if(map[nextX][nextY] == 'R' && !visit[nextX][nextY]){
                        visit[nextX][nextY] = true;
                        Queue.push(make_pair(nextX, nextY));
                    }
                }
                else if(map[startX][startY] == 'G'){
                    if(map[nextX][nextY] == 'G' && !visit[nextX][nextY]){
                        visit[nextX][nextY] = true;
                        Queue.push(make_pair(nextX, nextY));
                    }
                }
                else if(map[startX][startY] == 'B'){
                    if(map[nextX][nextY] == 'B' && !visit[nextX][nextY]){
                        visit[nextX][nextY] = true;
                        Queue.push(make_pair(nextX, nextY));
                    }
                }
            }
        }
    }

    normalResult++;
}

void BFS_redGreen(int startX, int startY){
    queue<pair<int, int>> Queue;

    Queue.push(make_pair(startX, startY));
    visit[startX][startY] = true;

    while(!Queue.empty()){
        int currentX = Queue.front().first;
        int currentY = Queue.front().second;
        Queue.pop();

        for(int i=0; i<4; i++){
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if(nextX >= 1 && nextX <= N && nextY >= 0 && nextY <= N){
                if(map[startX][startY] == 'R' || map[startX][startY] == 'G'){
                    if((map[nextX][nextY] == 'R' || map[nextX][nextY] == 'G') && !visit[nextX][nextY]){
                        visit[nextX][nextY] = true;
                        Queue.push(make_pair(nextX, nextY));
                    }
                }
                else if(map[startX][startY] == 'B'){
                    if(map[nextX][nextY] == 'B' && !visit[nextX][nextY]){
                        visit[nextX][nextY] = true;
                        Queue.push(make_pair(nextX, nextY));
                    }
                }
            }
        }
    }

    redGreenResult++;
}

int main(){
    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(!visit[i][j]){
                BFS_normal(i, j);
            }
        }
    }

    bzero(visit, sizeof(visit));

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(!visit[i][j]){
                BFS_redGreen(i, j);
            }
        }
    }

    cout << normalResult << ' ' << redGreenResult << '\n';

    return 0;
}