//
// Created by Keith_Lee on 25/03/2019.
//

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

struct Point{
    int z, x, y;
};

int map[5][5][5] = {0, };
int setMap[5][5][5] = {0, };

int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};

int result = 99999999;

void rotate(int partIndex, int degree){ // 몇층을 몇도로 돌릴것인가
    if(degree == 0){
        return;
    }

    int temp[5][5] = {0, };
    memcpy(temp, setMap[partIndex], sizeof(int) * 25);

    if(degree == 1){ // 오른쪽으로 90도
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                setMap[partIndex][i][j] = temp[4-j][i];
            }
        }
    }
    else if(degree == 2){ // 오른쪽으로 180도
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                setMap[partIndex][i][j] = temp[4-i][4-j];
            }
        }
    }
    else if(degree == 3){ // 오른쪽으로 270도
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                setMap[partIndex][i][j] = temp[j][4-i];
            }
        }
    }
}

int BFS(){
    queue<Point> Queue;
    bool visit[5][5][5] = {false, };

    Queue.push({0, 0, 0});
    visit[0][0][0] = true;
    int distance = 0;

    while(!Queue.empty()){
        vector<Point> points;

        while(!Queue.empty()){
            points.push_back(Queue.front());
            Queue.pop();
        }

        for(int v=0; v<points.size(); v++){
            int currentZ = points[v].z;
            int currentX = points[v].x;
            int currentY = points[v].y;

            if(currentZ == 4 && currentX == 4 && currentY == 4){
                return distance;
            }

            for(int i=0; i<6; i++){
                int nextZ = currentZ + dz[i];
                int nextX = currentX + dx[i];
                int nextY = currentY + dy[i];

                if(nextX >= 0 && nextX < 5 && nextY >= 0 && nextY < 5 && nextZ >= 0 && nextZ < 5){
                    if(!visit[nextZ][nextX][nextY] && setMap[nextZ][nextX][nextY] == 1){
                        visit[nextZ][nextX][nextY] = true;
                        Queue.push({nextZ, nextX, nextY});
                    }
                }
            }
        }

        distance++;
    }

    return -1;
}

int main(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                cin >> map[i][j][k];
            }
        }
    }

    vector<int> perm = {0, 1, 2, 3, 4};

    do{
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                for(int k=0; k<4; k++){
                    for(int l=0; l<4; l++){
                        for(int m=0; m<4; m++){
                            for(int n=0; n<5; n++){
                                memcpy(setMap[n], map[perm[n]], sizeof(int) * 25);
                            } // 바꾼 맵 초기화: 순열로 순서 배정

                            rotate(0, i);
                            rotate(1, j);
                            rotate(2, k);
                            rotate(3, l);
                            rotate(4, m);
                            // 각층 회전

                            if(setMap[0][0][0] == 1 && setMap[4][4][4] == 1){
                                int temp = BFS();

                                if(temp > 0 && result > temp){
                                    result = temp;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    while(next_permutation(perm.begin(), perm.end()));

    if(result == 99999999){
        result = -1;
    }
    cout << result << '\n';

    return 0;
}