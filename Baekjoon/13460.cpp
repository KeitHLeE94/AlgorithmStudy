//
// Created by Keith_Lee on 27/04/2019.
//

#include <iostream>

using namespace std;

class Point{
public:
    int x, y;

    Point(){
        x = -1;
        y = -1;
    }

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int reverse(int dir){
    int rd = 0;

    if(dir == 0){
        rd = 1;
    }
    else if(dir == 1){
        rd = 0;
    }
    else if(dir == 2){
        rd = 3;
    }
    else if(dir == 3){
        rd = 2;
    }

    return rd;
}

int result = 111111111;
int N, M;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void DFS(int direction, int count, char map[10][10], bool red, bool blue, Point R, Point B){
    count++;
    char tempMap[10][10];

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            tempMap[i][j] = map[i][j];
        }
    }

    int first = 0; // 0이면 R먼저, 1이면 B먼저

    if(direction == 0){
        if(R.y < B.y){
            first = 1;
        }
    }
    else if(direction == 1){
        if(R.y > B.y){
            first = 1;
        }
    }
    else if(direction == 2){
        if(R.x < B.x){
            first = 1;
        }
    }
    else if(direction == 3){
        if(R.x > B.x){
            first = 1;
        }
    }

    if(!first){
        while(true){
            int nextRX = R.x + dx[direction];
            int nextRY = R.y + dy[direction];

            if(tempMap[nextRX][nextRY] == '#'){
                break;
            }
            if(tempMap[nextRX][nextRY] == 'O'){
                tempMap[R.x][R.y] = '.';
                R = Point(-1, -1);
                red = true;
                break;
            }

            tempMap[R.x][R.y] = '.';
            tempMap[nextRX][nextRY] = 'R';
            R = Point(nextRX, nextRY);
        }
        while(true){
            int nextBX = B.x + dx[direction];
            int nextBY = B.y + dy[direction];

            if(tempMap[nextBX][nextBY] == '#' || tempMap[nextBX][nextBY] == 'R'){
                break;
            }
            if(tempMap[nextBX][nextBY] == 'O'){
                tempMap[B.x][B.y] = '.';
                B = Point(-1, -1);
                blue = true;
                break;
            }

            tempMap[B.x][B.y] = '.';
            tempMap[nextBX][nextBY] = 'B';
            B = Point(nextBX, nextBY);
        }
    }
    else{
        while(true){
            int nextBX = B.x + dx[direction];
            int nextBY = B.y + dy[direction];

            if(tempMap[nextBX][nextBY] == '#'){
                break;
            }
            if(tempMap[nextBX][nextBY] == 'O'){
                tempMap[B.x][B.y] = '.';
                B = Point(-1, -1);
                blue = true;
                break;
            }

            tempMap[B.x][B.y] = '.';
            tempMap[nextBX][nextBY] = 'B';
            B = Point(nextBX, nextBY);
        }
        while(true){
            int nextRX = R.x + dx[direction];
            int nextRY = R.y + dy[direction];

            if(tempMap[nextRX][nextRY] == '#' || tempMap[nextRX][nextRY] == 'B'){
                break;
            }
            if(tempMap[nextRX][nextRY] == 'O'){
                tempMap[R.x][R.y] = '.';
                R = Point(-1, -1);
                red = true;
                break;
            }

            tempMap[R.x][R.y] = '.';
            tempMap[nextRX][nextRY] = 'R';
            R = Point(nextRX, nextRY);
        }
    }

    if(count > 10){
        return;
    }
    if(blue){
        return;
    }
    else{
        if(red){
            result = result > count ? count : result;
            return;
        }
    }

    for(int i=0; i<4; i++){
        if(i == reverse(direction) || i == direction){
            continue;
        }
        DFS(i, count, tempMap, red, blue, R, B);
    }
}

int main(){
    char map[10][10];
    Point R, B;

    cin >> N >> M;

    for(int i=0; i<N; i++){
        string row;
        cin >> row;

        for(int j=0; j<M; j++){
            map[i][j] = row[j];

            if(map[i][j] == 'R'){
                R = Point(i, j);
            }
            else if(map[i][j] == 'B'){
                B = Point(i, j);
            }
        }
    }

    for(int i=0; i<4; i++){
        DFS(i, 0, map, false, false, R, B);
    }

    if(result == 111111111){
        result = -1;
    }

    cout << result << '\n';

    return 0;
}