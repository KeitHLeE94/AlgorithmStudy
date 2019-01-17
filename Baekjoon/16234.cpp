//
// Created by Keith_Lee on 15/01/2019.
//

#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>

using namespace std;

int N, L, R;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int map[50][50] = {0, };
int toChange[50][50] = {0, };
int visit[50][50] = {0, };

vector<pair<int, int>> changes(){
    vector<pair<int, int>> result;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(toChange[i][j] != 0){
                result.push_back(make_pair(i, j));
            }
        }
    }

    return result;
}

void toChange_init(){
    int areaCount = 1;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            queue<pair<int, int>> Queue;
            Queue.push(make_pair(i, j));

            while(!Queue.empty()){
                int currentX = Queue.front().first;
                int currentY = Queue.front().second;
                Queue.pop();

                for(int k=0; k<4; k++){
                    int nextX = currentX + dx[k];
                    int nextY = currentY + dy[k];

                    if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N){
                        int gap = abs(map[currentX][currentY] - map[nextX][nextY]);
                        if(gap >= L && gap <= R && toChange[nextX][nextY] == 0){
                            toChange[nextX][nextY] = areaCount;
                            Queue.push(make_pair(nextX, nextY));
                        }
                    }
                }
            }

            areaCount++;
        }
    }
}

void BFS(int currentX, int currentY){
    vector<pair<int, int>> visited;

    queue<pair<int, int>> Queue;
    Queue.push(make_pair(currentX, currentY));

    int changeCount = 0;
    int changeSum = 0;
    visit[currentX][currentY] = 1;

    while(!Queue.empty()){
        int startX = Queue.front().first;
        int startY = Queue.front().second;
        Queue.pop();

        changeCount++;
        changeSum += map[startX][startY];
        visited.push_back(make_pair(startX, startY));

        for(int i=0; i<4; i++){
            int nextX = startX + dx[i];
            int nextY = startY + dy[i];

            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N){
                if(visit[nextX][nextY] == 0 && toChange[nextX][nextY] == toChange[startX][startY]){
                    Queue.push(make_pair(nextX, nextY));
                    visit[nextX][nextY] = 1;
                }
            }
        }
    }

    for(int i=0; i<visited.size(); i++){
        map[visited[i].first][visited[i].second] = changeSum / changeCount;
    }
}

int main(){
    cin >> N >> L >> R;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    int count = 0;

    while(true) {
        memset(toChange, 0, sizeof(toChange));
        memset(visit, 0, sizeof(visit));

        toChange_init();

        vector<pair<int, int>> ones = changes();
        if (ones.size() == 0) {
            break;
        }

        for (int i = 0; i < ones.size(); i++) {
            if (visit[ones[i].first][ones[i].second] == 0) {
                BFS(ones[i].first, ones[i].second);
            }
        }

        count++;
    }

    cout << count << '\n';

    return 0;
}