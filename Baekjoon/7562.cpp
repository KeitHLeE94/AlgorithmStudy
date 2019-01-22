//
// Created by Keith_Lee on 22/01/2019.
//

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int I;
int result = 0;

int map[300][300];
bool visit[300][300];

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

void BFS(int startX, int startY, int endX, int endY){
    queue<pair<int, int>> Queue;
    Queue.push(make_pair(startX, startY));
    visit[startX][startY] = true;

    while(!Queue.empty()){
        vector<pair<int, int>> currents;

        while(!Queue.empty()){
            int currentX = Queue.front().first;
            int currentY = Queue.front().second;
            Queue.pop();
            currents.push_back(make_pair(currentX, currentY));
        }

        for(int q=0; q<currents.size(); q++){
            int currentX = currents[q].first;
            int currentY = currents[q].second;

            if(currentX == endX && currentY == endY){
                return;
            }

            for(int i=0; i<8; i++){
                int nextX = currentX + dx[i];
                int nextY = currentY + dy[i];

                if(nextX >= 0 && nextX < I && nextY >= 0 && nextY < I) {
                    if(!visit[nextX][nextY]){
                        visit[nextX][nextY] = true;
                        Queue.push(make_pair(nextX, nextY));
                    }
                }
            }
        }

        result++;

    }
}

int main(){
    int tc;
    cin >> tc;

    for(int test=0; test<tc; test++){
        bzero(visit, sizeof(visit));
        result = 0;
        cin >> I;

        int startX, startY;
        cin >> startX >> startY;

        int endX, endY;
        cin >> endX >> endY;

        BFS(startX, startY, endX, endY);

        cout << result << '\n';
    }

    return 0;
}