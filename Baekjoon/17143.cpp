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

bool cmp(shark a, shark b){
    if(a.size < b.size){
        return false;
    }

    return true;
}

bool map[101][101] = {false, };

pair<pair<int, int>, int> move(shark toMove){
    int speed = toMove.speed;
    int x = toMove.x;
    int y = toMove.y;
    int dir = toMove.dir;

    if(toMove.dir == 1){
        int dx = -1;

        while(speed > 0){
            if(x == 1 || x == R){
                dx *= -1;

                if(dir == 1){
                    dir = 2;
                }
                else if(dir == 2){
                    dir = 1;
                }
            }

            x += dx;
            speed--;
        }
    }
    else if(toMove.dir == 2){
        int dx = 1;

        while(speed > 0){
            if(x == 1 || x == R){
                dx *= -1;

                if(dir == 1){
                    dir = 2;
                }
                else if(dir == 2){
                    dir = 1;
                }
            }

            x += dx;
            speed--;
        }
    }
    else if(toMove.dir == 3){
        int dy = 1;

        while(speed > 0){
            if(y == 1 || y == C){
                dy *= -1;

                if(dir == 3){
                    dir = 4;
                }
                else if(dir == 4){
                    dir = 3;
                }
            }

            y += dy;
            speed--;
        }
    }
    else if(toMove.dir == 4){
        int dy = -1;

        while(speed > 0){
            if(y == 1 || y == C){
                dy *= -1;

                if(dir == 3){
                    dir = 4;
                }
                else if(dir == 4){
                    dir = 3;
                }
            }

            y += dy;
            speed--;
        }
    }

    return {{x, y}, dir};
}

int main(){
    cin >> R >> C >> M;

    vector<shark> alive;

    for(int i=0; i<M; i++){
        int r, c, s, d, z;

        cin >> r >> c >> s >> d >> z;

        alive.push_back({r, c, s, d, z});
    }

    int result = 0;

    for(int fisher=1; fisher<=C; fisher++){
        int minX = 9999;
        int minIndex = 0;

        for(int i=0; i<M; i++){
            if(alive[i].y == fisher){
                if(alive[i].x < minX){
                    minX = alive[i].x;
                    minIndex = i;
                }
            }
        }

        result += alive[minIndex].size;
        alive[minIndex].size = -1;

        sort(alive.begin(), alive.end(), cmp);

        vector<shark> temp;
        for(int i=0; i<M; i++){
            if(alive[i].size >= 0){
                temp.push_back(alive[i]);
            }
        }

        alive.clear();
        bzero(map, sizeof(map));

        for(int i=0; i<temp.size(); i++){
            cout << temp[i].x << ", " << temp[i].y << ": " << temp[i].speed << " | ";
            pair<pair<int, int>, int> moved = move(temp[i]);

            int nextX = moved.first.first;
            int nextY = moved.first.second;
            int nextDir = moved.second;

            cout << nextX << ", " << nextY << " - " << nextDir << '\n';

            if(!map[nextX][nextY]){
                temp[i].x = nextX;
                temp[i].y = nextY;
                temp[i].dir = nextDir;
                map[nextX][nextY] = true;
            }
        }
    }

    cout << result << '\n';

    return 0;
}