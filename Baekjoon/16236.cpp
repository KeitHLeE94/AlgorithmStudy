//
// Created by Keith_Lee on 17/02/2019.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Fish{
    int x, y, dist;
};

int N;
int map[20][20];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int sharkSize = 2;
int moved = 0;
int ate = 0;

bool compare(Fish &a, Fish &b){
    if(a.dist < b.dist){
        return true;
    }
    else if(a.dist == b.dist){
        return a.x < b.x;
    }
    else if(a.dist == b.dist && a.x == b.x){
        return a.y < b.y;
    }
    else{
        return false;
    }
}

int BFS(int startX, int startY, int endX, int endY){
    queue<Fish> Queue;
    int minDist = 9999;
    bool visit[20][20] = {false, };

    Queue.push({startX, startY, 0});
    visit[startX][startY] = true;

    while(!Queue.empty()){
        int currentX = Queue.front().x;
        int currentY = Queue.front().y;
        int currentDist = Queue.front().dist;
        Queue.pop();

        if(currentX == endX && currentY == endY){
            if(minDist > currentDist){
                minDist = currentDist;
            }

            break;
        }

        for(int i=0; i<4; i++){
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N){
                if(!visit[nextX][nextY] && map[nextX][nextY] <= sharkSize){
                    Queue.push({nextX, nextY, currentDist+1});
                    visit[nextX][nextY] = true;
                }
            }
        }
    }

    return minDist;
}

vector<Fish> findEdible(int startX, int startY){
    vector<Fish> result;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] > 0 && map[i][j] < sharkSize){
                int dist = BFS(startX, startY, i, j);
                if(dist != 9999){
                    result.push_back({i, j, dist});
                }
            }
        }
    }

    if(!result.empty()){
        sort(result.begin(), result.end(), compare);
    }

    return result;
}

int main(){
    cin >> N;

    int startX = 0, startY = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];

            if(map[i][j] == 9){
                startX = i;
                startY = j;
            }
        }
    }

    while(true){
        vector<Fish> edible = findEdible(startX, startY);
        if(edible.empty()){
            break;
        }

        map[startX][startY] = 0;
        Fish toEat = edible[0];
        startX = toEat.x;
        startY = toEat.y;

        moved += toEat.dist;
        ate++;
        map[startX][startY] = 9;

        if(ate == sharkSize){
            sharkSize++;
            ate = 0;
        }
    }

    cout << moved << '\n';

    return 0;
}