//
// Created by Keith_Lee on 13/01/2019.
//

#include <iostream>
#include <queue>

using namespace std;

int N, M;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int map[501][501];

int BFS(int startX, int startY){
    int result = 0;
    queue<pair<int, int>> Queue;

    Queue.push(make_pair(startX, startY));

//    vector<pair<int, int>> visits;

    while(!Queue.empty()){
        int currentX = Queue.front().first;
        int currentY = Queue.front().second;
        Queue.pop();

//        visits.push_back(make_pair(currentX, currentY));

        if(currentX == N && currentY == M){
//            for(int i=0; i<visits.size(); i++){
//                cout << map[visits[i].first][visits[i].second] << ' ';
//            }
//            cout << '\n';
//            visits.clear();
            result++;
        }

        for(int i=0; i<4; i++){
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if(nextX > 0 && nextX <= N && nextY > 0 && nextY <= N){
                if(map[currentX][currentY] > map[nextX][nextY]){
                    Queue.push(make_pair(nextX, nextY));
                }
            }
        }
    }

    return result;
}

int main(){
    cin >> M >> N;

    for(int i=1; i<=M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    cout << BFS(1, 1) << '\n';

    return 0;
}