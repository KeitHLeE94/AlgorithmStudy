//
// Created by Keith_Lee on 22/01/2019.
//

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int M, N, K;
int result = 0;

int map[100][100];
bool visit[100][100];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<int> areas;

void BFS(int startX, int startY){
    queue<pair<int, int>> Queue;
    Queue.push(make_pair(startX, startY));

    int area = 1;

    while(!Queue.empty()){
        int currentX = Queue.front().first;
        int currentY = Queue.front().second;
        Queue.pop();

        for(int i=0; i<4; i++){
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if(nextX >= 0 && nextX < M && nextY >= 0 && nextY < N){
                if(!visit[nextX][nextY] && map[nextX][nextY] == 0){
                    visit[nextX][nextY] = true;
                    Queue.push(make_pair(nextX, nextY));
                    area++;
                }
            }
        }
    }

    result++;
    areas.push_back(area);
}

int main(){
    cin >> M >> N >> K;

    bzero(map, sizeof(map));

    for(int i=0; i<K; i++){
        int startX, startY, endX, endY;

        cin >> startX >> startY >> endX >> endY;

        for(int j=startY; j<endY; j++){
            for(int k=startX; k<endX; k++){
                map[j][k] = 1;
            }
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(!visit[i][j] && map[i][j] == 0){
                visit[i][j] = true;
                BFS(i, j);
            }
        }
    }

    sort(areas.begin(), areas.end());
    cout << result << '\n';
    for(int i=0; i<areas.size(); i++){
        cout << areas[i] << ' ';
    }
    cout << '\n';

    return 0;
}