//
// Created by Keith_Lee on 22/02/2019.
//

#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

struct place{
    int x, y, direction, moved;
};

int map[101][101];
bool visit[101][101] = {false, };
int dx[13] = {0, 0, 0, 1, -1, 0, 0, 2, -2, 0, 0, 3, -3};
int dy[13] = {0, 1, -1, 0, 0, 2, -2, 0, 0, 3, -3, 0, 0};

int M, N;
int robotX, robotY, robotDirection;
int destX, destY, destDirection;

int minMove = 99999;

int directionCheck(int currentDirection, int nextDirection){ // 현재 방향에서 몇번 더 방향을 바꿔야 하는지 확인
    if(currentDirection == 1){
        if(nextDirection == 1){
            return 0;
        }
        else if(nextDirection == 2){
            return 2;
        }
        else if(nextDirection == 3 || nextDirection == 4){
            return 1;
        }
    }
    else if(currentDirection == 2){
        if(nextDirection == 1){
            return 2;
        }
        else if(nextDirection == 2){
            return 0;
        }
        else if(nextDirection == 3 || nextDirection == 4){
            return 1;
        }
    }
    else if(currentDirection == 3){
        if(nextDirection == 1 || nextDirection == 2){
            return 1;
        }
        else if(nextDirection == 3){
            return 0;
        }
        else if(nextDirection == 4){
            return 2;
        }
    }
    else if(currentDirection == 4){
        if(nextDirection == 1 || nextDirection == 2){
            return 1;
        }
        else if(nextDirection == 3){
            return 2;
        }
        else if(nextDirection == 4){
            return 0;
        }
    }

    return -1;
}

bool movableCheck(int currentX, int currentY, int index){ // 다음 이동장소로 이동 가능한지 확인
    int nextX = currentX + dx[index];
    int nextY = currentY + dy[index];

    if(nextX >= 1 && nextX <= M && nextY >= 1 && nextY <= N){
        if(map[nextX][nextY] == 1){
            return false;
        }
        else{
            if(dx[index] >= 0){
                for(int j=0; j<=dx[index]; j++){
                    if(map[currentX + j][currentY] == 1){
                        return false;
                    }
                }
            }
            else{
                for(int j=0; j>=dx[index]; j--){
                    if(map[currentX + j][currentY] == 1){
                        return false;
                    }
                }
            }

            if(dy[index] >= 0){
                for(int j=0; j<=dy[index]; j++){
                    if(map[currentX][currentY + j] == 1){
                        return false;
                    }
                }
            }
            else{
                for(int j=0; j>=dy[index]; j--){
                    if(map[currentX][currentY + j] == 1){
                        return false;
                    }
                }
            }
        }
    }
    else{
        return false;
    }

    return true;
}

void BFS(){
    queue<place> Queue;
    Queue.push({robotX, robotY, robotDirection, 0});

    while(!Queue.empty()){
        vector<place> candidates;

        while(!Queue.empty()){
            candidates.push_back(Queue.front());
            Queue.pop();
        }

        for(int v=0; v<candidates.size(); v++){
            int currentX = candidates[v].x;
            int currentY = candidates[v].y;
            int currentDirection = candidates[v].direction;
            int currentMoved = candidates[v].moved;

//            cout << "((" << currentX << ", " << currentY << ") " << currentDirection << "): " << currentMoved << '\n';

            if(currentX == destX && currentY == destY){ // 목적지에 도착한 경우
                int temp = currentMoved;

                temp += directionCheck(currentDirection, destDirection); // 방향 확인

                minMove = minMove > temp ? temp : minMove; // 최소값 갱신
            }

            for(int i=12; i>=1; i--){ // 많이 움직이는 경우부터(3칸, 2칸, 1칸 순) 확인
                bool movable = movableCheck(currentX, currentY, i);
                int nextDirection = i % 4; // 바뀌는 방향 확인
                if(nextDirection == 0){
                    nextDirection = 4;
                }

                int nextX = currentX + dx[i];
                int nextY = currentY + dy[i];

                if(movable && !visit[nextX][nextY]){ // 이동 가능하고 방문 안했으면 큐에 넣음
                    int nextMoved = currentMoved;
                    int tempDirection = currentDirection;

                    nextMoved += directionCheck(tempDirection, nextDirection); // 방향 바꾸기
                    tempDirection = nextDirection;
                    visit[nextX][nextY] = true; // 방문했다고 표시

                    Queue.push({nextX, nextY, tempDirection, nextMoved+1});
                }
            }
        }
    }
}

int main(){
    memset(map, -1, sizeof(map));

    cin >> M >> N;

    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }

    cin >> robotX >> robotY >> robotDirection;
    cin >> destX >> destY >> destDirection;

    visit[robotX][robotY] = true;

    BFS();

    cout << minMove << '\n';

    return 0;
}