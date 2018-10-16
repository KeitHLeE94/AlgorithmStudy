//
// Created by Keith_Lee on 16/10/2018.
//
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int map[8][8];
int temp_map[8][8];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int answer = 0;

vector<pair<int, int>> viruses;

void BFS(){
    int wall_map[8][8];
    memset(wall_map, -1, sizeof(wall_map));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            wall_map[i][j] = temp_map[i][j];
        }
    }

    queue<pair<int, int>> Queue;
    for(int i=0; i<viruses.size(); i++){
        Queue.push(viruses[i]);
    }

    while(!Queue.empty()){
        int startX = Queue.front().first;
        int startY = Queue.front().second;
        Queue.pop();

        for(int i=0; i<4; i++){
            int nextX = startX + dx[i];
            int nextY = startY + dy[i];

            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M){
                if(wall_map[nextX][nextY] == 0){
                    wall_map[nextX][nextY] = 2;
                    Queue.push(make_pair(nextX, nextY));
                }
            }
        }
    }

    int safe = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(wall_map[i][j] == 0){
                safe++;
            }
        }
    }

    answer = max(answer, safe);
}

void makeWall(int cnt){
    if(cnt == 3){
        BFS();
        return;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(temp_map[i][j] == 0){
                temp_map[i][j] = 1;
                makeWall(cnt+1);
                temp_map[i][j] = 0;
            }
        }
    }
}

int main(){
    memset(map, -1, sizeof(map));
    memset(temp_map, -1, sizeof(temp_map));
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            temp_map[i][j] = map[i][j];
            if(map[i][j] == 2){
                viruses.push_back(make_pair(i, j));
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 0){
                temp_map[i][j] = 1;
                makeWall(1);
                temp_map[i][j] = 0;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}