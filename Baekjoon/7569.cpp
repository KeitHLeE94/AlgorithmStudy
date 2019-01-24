//
// Created by Keith_Lee on 24/01/2019.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[100][100][100] = {0, };
bool visit[100][100][100] = {false, };

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dz[2] = {-1, 1};

// 가로, 세로, 높이
int M, N, H;
int result = 0;

queue<pair<int, pair<int, int>>> Queue;

void BFS(){
    while(!Queue.empty()){
        vector<pair<int, pair<int, int>>> starts;

        while(!Queue.empty()){
            starts.push_back(make_pair(Queue.front().first, make_pair(Queue.front().second.first, Queue.front().second.second)));
            Queue.pop();
        }

        for(int v=0; v<starts.size(); v++){
            int startZ = starts[v].first;
            int startX = starts[v].second.first;
            int startY = starts[v].second.second;

            for(int i=0; i<4; i++){
                int nextX = startX + dx[i];
                int nextY = startY + dy[i];

                if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M){
                    if(!visit[startZ][nextX][nextY] && map[startZ][nextX][nextY] == 0){
                        visit[startZ][nextX][nextY] = true;
                        map[startZ][nextX][nextY] = 1;
                        Queue.push(make_pair(startZ, make_pair(nextX, nextY)));
                    }
                }
            }

            for(int i=0; i<2; i++){
                int nextZ = startZ + dz[i];

                if(nextZ >= 0 && nextZ < H){
                    if(!visit[nextZ][startX][startY] && map[nextZ][startX][startY] == 0){
                        visit[nextZ][startX][startY] = true;
                        map[nextZ][startX][startY] = 1;
                        Queue.push(make_pair(nextZ, make_pair(startX, startY)));
                    }
                }
            }
        }

        result++;

    }

}

int main(){
    cin >> M >> N >> H;

    // (층, (가로, 세로)) 쌍으로 저장한다.
    vector<pair<int, pair<int, int>>> coordinates;

    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin >> map[i][j][k];
                if(map[i][j][k] == 1){
                    visit[i][j][k] = true;
                    Queue.push(make_pair(i, make_pair(j, k)));
                }
            }
        }
    }

    BFS();

    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(map[i][j][k] == 0){
                    result = -1;
                    break;
                }
            }
        }
    }

    if(result != -1){
        cout << result-1 << '\n';
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}