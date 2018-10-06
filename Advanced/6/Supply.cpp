//
// Created by Keith_Lee on 2018. 10. 5..
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[100][100] = {-1, };
bool visit[100][100] = {false, };
int dist[100][100] = {0, };

void BFS(queue<pair<int, int>>* Queue, int currentX, int currentY){
    dist[currentX][currentY] = 0;
    visit[currentX][currentY] = true;
    Queue->push(make_pair(currentX, currentY));

    while(!Queue->empty()){
        int tempX = Queue->front().first;
        int tempY = Queue->front().second;
        Queue->pop();

        vector<pair<int, int>> candidates;

        if(0 <= map[tempX-1][tempY] && map[tempX-1][tempY] < 10){
            candidates.push_back(make_pair(tempX-1, tempY));
        }
        if(0 <= map[tempX+1][tempY] && map[tempX+1][tempY] < 10){
            candidates.push_back(make_pair(tempX+1, tempY));
        }
        if(0 <= map[tempX][tempY-1] && map[tempX][tempY-1] < 10){
            candidates.push_back(make_pair(tempX, tempY-1));
        }
        if(0 <= map[tempX][tempY+1] && map[tempX][tempY+1] < 10){
            candidates.push_back(make_pair(tempX, tempY+1));
        }

        for(int i=0; i<candidates.size(); i++){
            int nextX = candidates[i].first;
            int nextY = candidates[i].second;

            if(!visit[nextX][nextY]){
                Queue->push(make_pair(nextX, nextY));
                dist[nextX][nextY] = dist[tempX][tempY] + map[tempX][tempY];
                visit[nextX][nextY] = true;
            }
        }
    }
}

int main(){
    int caseNum;
    cin >> caseNum;

    for(int i=0; i<caseNum; i++){
        for(int j=0; j<100; j++){
            for(int k=0; k<100; k++){
                map[j][k] = -1;
                visit[j][k] = false;
                dist[j][k] = 0;
            }
        }
        int N;
        cin >> N;

        string row;
        for(int j=0; j<N; j++){
            cin >> row;

            for(int k=0; k<N; k++){
                map[j][k] = row[k] - '0';
            }
        }

        queue<pair<int, int>> Queue;

        BFS(&Queue, 0, 0);

        cout << '#' << i+1 << ' ' << dist[N-1][N-1] << '\n';
    }

    return 0;
}