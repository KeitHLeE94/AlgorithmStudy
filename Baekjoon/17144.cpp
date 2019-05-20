//
// Created by Keith_Lee on 18/05/2019.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Dust{
    int x, y;
    int capacity;
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(){
    int R, C, T;

    cin >> R >> C >> T;

    int map[50][50] = {0, };

    int clockX, clockY;
    int cClockX, cClockY;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> map[i][j];

            if(map[i][j] == -1){
                clockX = i;
                clockY = j;
            }
        }
    }

    cClockX = clockX - 1;
    cClockY = clockY;

    for(int time = 0; time < T; time++){
        // 확산할 위치 찾기
        vector<Dust> extend;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(map[i][j] >= 5){
                    extend.push_back({i, j, map[i][j]});
                }
            }
        }

        // 확산
        for(int i=0; i<extend.size(); i++){
            int toExtend = extend[i].capacity / 5;

            for(int j=0; j<4; j++){
                int nextX = extend[i].x + dx[j];
                int nextY = extend[i].y + dy[j];

                if(nextX >= 0 && nextX < R && nextY >= 0 && nextY < C){
                    if(map[nextX][nextY] >= 0){
                        map[nextX][nextY] += toExtend;
                        map[extend[i].x][extend[i].y] -= toExtend;
                    }
                }
            }
        }

        // 위쪽 공기청정기 작동
        queue<int> toRight;
        for(int i=0; i<C-1; i++){
            if(map[cClockX][i+1] == -1){
                continue;
            }

            if(map[cClockX][i] != -1){
                toRight.push(map[cClockX][i]);
            }
            else{
                toRight.push(0);
            }
        }

        queue<int> toUp;
        for(int i=cClockX; i>0; i--){
            toUp.push(map[i][C-1]);
        }

        queue<int> toLeft;
        for(int i=1; i<C; i++){
            toLeft.push(map[0][i]);
        }

        queue<int> toDown;
        for(int i=0; i<cClockX; i++){
            if(map[i+1][0] == -1){
                continue;
            }

            toDown.push(map[i][0]);
        }

        int index_right = 1;
        while(!toRight.empty()){
            map[cClockX][cClockY + index_right] = toRight.front();
            toRight.pop();
            index_right++;
        }

        int index_up = 1;
        while(!toUp.empty()){
            map[cClockX - index_up][C-1] = toUp.front();
            toUp.pop();
            index_up++;
        }

        int index_left = 1;
        while(!toLeft.empty()){
            map[0][index_left-1] = toLeft.front();
            toLeft.pop();
            index_left++;
        }

        int index_down = 1;
        while(!toDown.empty()){
            map[index_down][0] = toDown.front();
            toDown.pop();
            index_down++;
        }

        // 아래쪽 공기청정기 작동
        while(!toRight.empty()){
            toRight.pop();
        }
        while(!toDown.empty()){
            toDown.pop();
        }
        while(!toLeft.empty()){
            toLeft.pop();
        }
        while(!toUp.empty()){
            toUp.pop();
        }

        for(int i=0; i<C-1; i++){
            if(map[clockX][i+1] == -1){
                continue;
            }

            if(map[clockX][i] != -1){
                toRight.push(map[clockX][i]);
            }
            else{
                toRight.push(0);
            }
        }

        for(int i=clockX; i<R-1; i++){
            toDown.push(map[i][C-1]);
        }

        for(int i=1; i<C; i++){
            toLeft.push(map[R-1][i]);
        }

        for(int i=R-1; i>clockX; i--){
            if(map[i-1][0] == -1){
                continue;
            }

            toUp.push(map[i][0]);
        }

        index_right = 1;
        while(!toRight.empty()){
            map[clockX][clockY + index_right] = toRight.front();
            toRight.pop();
            index_right++;
        }

        index_down = 1;
        while(!toDown.empty()){
            map[clockX + index_down][C-1] = toDown.front();
            toDown.pop();
            index_down++;
        }

        index_left = 1;
        while(!toLeft.empty()){
            map[R-1][index_left-1] = toLeft.front();
            toLeft.pop();
            index_left++;
        }

        index_up = 1;
        while(!toUp.empty()){
            map[R - 1 - index_up][clockY] = toUp.front();
            toUp.pop();
            index_up++;
        }
    }

    int result = 0;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j] > 0){
                result += map[i][j];
            }
        }
    }

    cout << result << '\n';

    return 0;
}