//
// Created by Keith_Lee on 29/05/2019.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <strings.h>

using namespace std;

struct shark{
    int x, y, speed, dir, size;
};

int R, C, M;

struct cmp{
    bool operator()(shark a, shark b){
        return a.size < b.size;
    }
};

bool map[101][101] = {false, };

pair<pair<int, int>, int> move(shark toMove){
    int speed = toMove.speed;
    int x = toMove.x;
    int y = toMove.y;
    int dir = toMove.dir;

    if(dir == 1){ // 상
        int dx = -1;

        while(speed > 0){
            if(x == 1){
                dx = 1;
                dir = 2;
            }
            else if(x == R){
                dx = -1;
                dir = 1;
            }

            x += dx;
            speed--;
        }
    }
    else if(dir == 2){ // 하
        int dx = 1;

        while(speed > 0){
            if(x == 1){
                dx = 1;
                dir = 2;
            }
            else if(x == R){
                dx = -1;
                dir = 1;
            }

            x += dx;
            speed--;
        }
    }
    else if(dir == 3){ // 우
        int dy = 1;

        while(speed > 0){
            if(y == 1){
                dy = 1;
                dir = 3;
            }
            else if(y == C){
                dy = -1;
                dir = 4;
            }

            y += dy;
            speed--;
        }
    }
    else if(dir == 4){ // 좌
        int dy = -1;

        while(speed > 0){
            if(y == 1){
                dy = 1;
                dir = 3;
            }
            else if(y == C){
                dy = -1;
                dir = 4;
            }

            y += dy;
            speed--;
        }
    }

    return {{x, y}, dir};
}

int main(){
    cin >> R >> C >> M;

    priority_queue<shark, vector<shark>, cmp> alive;

    for(int i=0; i<M; i++){
        int r, c, s, d, z;

        cin >> r >> c >> s >> d >> z;

        alive.push({r, c, s, d, z});
    }

    int result = 0;

    if(M != 0) {
        for (int fisher = 1; fisher <= C; fisher++) {
            int minX = 9999;
            int minIndex = 9999;

            vector<shark> temp;
            while(!alive.empty()){
                temp.push_back(alive.top());
                alive.pop();
            }

            for (int i = 0; i < temp.size(); i++) {
                if (temp[i].y == fisher) {
                    if (temp[i].x < minX) {
                        minX = temp[i].x;
                        minIndex = i;
                    }
                }
            }

            if(minIndex < temp.size()){
                if(temp[minIndex].x > 0 && temp[minIndex].y > 0){
                    result += temp[minIndex].size;
                    temp[minIndex].size = -1;
                }
            }

            bzero(map, sizeof(map));

            for (int i = 0; i < temp.size(); i++) {
                if(temp[i].size >= 0){
                    pair<pair<int, int>, int> moved = move(temp[i]);

                    int nextX = moved.first.first;
                    int nextY = moved.first.second;
                    int nextDir = moved.second;

                    if (!map[nextX][nextY]) {
                        temp[i].x = nextX;
                        temp[i].y = nextY;
                        temp[i].dir = nextDir;
                        map[nextX][nextY] = true;

                        alive.push(temp[i]);
                    }
                }
            }
        }
    }

    cout << result << '\n';

    return 0;
}