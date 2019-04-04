//
// Created by Keith_Lee on 03/04/2019.
//

#include <iostream>
#include <queue>

using namespace std;

struct Point{
    int x, y;
    int breakCount;
};

int map[1000][1000] = {0, };
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dist[1000][1000][2] = {0, };

int N, M;

int BFS(){
    queue<Point> Queue;
    Queue.push({0, 0, 1});
    dist[0][0][1] = 1;

    while(!Queue.empty()){
        int currentX = Queue.front().x;
        int currentY = Queue.front().y;
        int breakCount = Queue.front().breakCount;
        Queue.pop();

        if(currentX == N-1 && currentY == M-1){
            return dist[N-1][M-1][breakCount];
        }

        for(int i=0; i<4; i++){
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M){
                if(map[nextX][nextY] == 0 && dist[nextX][nextY][breakCount] == 0){
                    dist[nextX][nextY][breakCount] = dist[currentX][currentY][breakCount] + 1;
                    Queue.push({nextX, nextY, breakCount});
                }
                else if(map[nextX][nextY] == 1 && breakCount > 0){
                    dist[nextX][nextY][breakCount-1] = dist[currentX][currentY][breakCount] + 1;
                    Queue.push({nextX, nextY, breakCount-1});
                }
            }
        }
    }

    return -1;
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        string row;
        cin >> row;

        for(int j=0; j<M; j++){
            map[i][j] = row[j] - '0';
        }
    }

    cout << BFS() << '\n';

    return 0;
}