//
// Created by Keith_Lee on 2018. 9. 28..
//
#include <iostream>
#include <queue>

using namespace std;

int map[16][16];
bool visit[16][16] = {false, };

void BFS(int startX, int startY){
    queue<pair<int, int>> Queue;

    visit[startX][startY] = true;
    Queue.push(make_pair(startX, startY));

    while(!Queue.empty()){
        int nextX = Queue.front().first;
        int nextY = Queue.front().second;
        Queue.pop();

        //위로 이동 가능
        if(map[nextX-1][nextY] != 1 && !visit[nextX-1][nextY]){
            Queue.push(make_pair(nextX-1, nextY));
            visit[nextX-1][nextY] = true;
        }
        //아래로 이동 가능
        if(map[nextX+1][nextY] != 1 && !visit[nextX+1][nextY]){
            Queue.push(make_pair(nextX+1, nextY));
            visit[nextX+1][nextY] = true;
        }
        //왼쪽으로 이동 가능
        if(map[nextX][nextY-1] != 1 && !visit[nextX][nextY-1]){
            Queue.push(make_pair(nextX, nextY-1));
            visit[nextX][nextY-1] = true;
        }
        //오른쪽으로 이동 가능
        if(map[nextX][nextY+1] != 1 && !visit[nextX][nextY+1]){
            Queue.push(make_pair(nextX, nextY+1));
            visit[nextX][nextY+1] = true;
        }
    }
}

int main(){
    for(int i=0; i<10; i++){
        int caseNum;
        cin >> caseNum;

        int startX;
        int startY;
        int endX;
        int endY;

        for(int j=0; j<16; j++){
            string row;
            cin >> row;
            for(int k=0; k<16; k++){
                visit[j][k] = false;
                map[j][k] = row[k] - '0';
                if(map[j][k] == 2){
                    startX = j;
                    startY = k;
                }
                else if(map[j][k] == 3){
                    endX = j;
                    endY = k;
                }
            }
        }

        BFS(startX, startY);

        int answer = 0;

        if(visit[endX][endY]){
            answer = 1;
        }

        cout << '#' << caseNum << ' ' << answer << '\n';
    }

    return 0;
}