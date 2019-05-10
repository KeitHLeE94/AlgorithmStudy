//
// Created by Keith_Lee on 10/05/2019.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Cell{
    int x, y;
    int age;
    int activate;
};

struct cmp{
    bool operator()(const Cell &a, const Cell &b){
        return a.age < b.age;
    }
};

// 상 좌 우 하
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int main(){
    int T;

    cin >> T;

    for(int test=1; test<=T; test++){
        int N, M, K;

        cin >> N >> M >> K;

        int map[500][500] = {0, };

        priority_queue<Cell, vector<Cell>, cmp> alive;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                int x = (500-N) / 2 + 1 + i;
                int y = (500-M) / 2 + 1 + j;
                cin >> map[x][y];

                if(map[x][y] != 0){
                    alive.push({x, y, map[x][y], map[x][y] * 2});
                }
            }
        }

        for(int i=0; i<K; i++){
            vector<Cell> level;

            while(!alive.empty()){
                level.push_back(alive.top());
                alive.pop();
            }

            for(int v=0; v<level.size(); v++){
                Cell current = level[v];

                if(current.activate == current.age){
                    for(int j=0; j<4; j++){
                        int nextX = current.x + dx[j];
                        int nextY = current.y + dy[j];

                        if(nextX >= 0 && nextX < 500 && nextY >= 0 && nextY < 500){
                            if(map[nextX][nextY] == 0){
                                map[nextX][nextY] = current.age;
                                alive.push({nextX, nextY, current.age, current.age * 2});
                            }
                        }
                    }
                }

                current.activate--;

                if(current.activate == 0){
                    map[current.x][current.y] = -1;
                }
                else{
                    alive.push(current);
                }
            }
        }

        int result = 0;
        for(int i=0; i<500; i++){
            for(int j=0; j<500; j++){
                if(map[i][j] > 0){
                    result++;
                }
            }
        }

        cout << "#" << test << ' ' << result << '\n';
    }

    return 0;
}