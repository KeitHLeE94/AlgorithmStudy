//
// Created by Keith_Lee on 17/10/2018.
//
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int T, M, N, K;
int map[50][50];
bool visit[50][50];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int answer;

void BFS(int startX, int startY){
    queue<pair<int, int>> Queue;
    visit[startX][startY] = true;
    Queue.push(make_pair(startX, startY));

    while(!Queue.empty()){
        int currentX = Queue.front().first;
        int currentY = Queue.front().second;
        Queue.pop();

        for(int i=0; i<4; i++){
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N){
                if(!visit[nextX][nextY] && map[nextX][nextY] == 1){
                    visit[nextX][nextY] = true;
                    Queue.push(make_pair(nextX, nextY));
                }
            }
        }
    }

    answer++;
}

int main(){
    cin >> T;
    vector<int> answers;

    for(int testCase=0; testCase<T; testCase++){
        answer = 0;
        memset(map, 0, sizeof(map));
        memset(visit, false, sizeof(visit));
        cin >> M >> N >> K;

        int X, Y;
        for(int i=0; i<K; i++){
            cin >> X >> Y;
            map[X][Y] = 1;
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j] == 1 && !visit[i][j]){
                    BFS(i, j);
                }
            }
        }

        answers.push_back(answer);
    }

    for(int i=0; i<T; i++){
        cout << answers[i] << '\n';
    }

    return 0;
}