//
// Created by Keith_Lee on 14/02/2019.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Tree{
    int x, y, age;
};

int N, M, K;

int map[11][11] = {0, };
int winterAdd[11][11] = {0, };
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

queue<Tree> Queue;

int compare(const Tree &t1, const Tree &t2){
    if(t1.age < t2.age){
        return true;
    }
    return false;
}

int BFS(){
    for(int i=0; i<K; i++){
        vector<Tree> lives;
        vector<Tree> deads;

        while(!Queue.empty()){
            lives.push_back(Queue.front());
            Queue.pop();
        }

        sort(lives.begin(), lives.end(), compare);

        for(int j=0; j<lives.size(); j++) {
            if (map[lives[j].x][lives[j].y] >= lives[j].age) { // 봄
                map[lives[j].x][lives[j].y] -= lives[j].age;
                Queue.push({lives[j].x, lives[j].y, lives[j].age + 1});
                lives[j].age++;
            }
            else {
                deads.push_back({lives[j].x, lives[j].y, lives[j].age});
                lives[j].age = -1;
            }

            if(lives[j].age > 0 && lives[j].age % 5 == 0){ // 가을
                for(int k=0; k<8; k++){
                    int nextX = lives[j].x + dx[k];
                    int nextY = lives[j].y + dy[k];

                    if(nextX > 0 && nextX <= N && nextY > 0 && nextY <= N){
                        Queue.push({nextX, nextY, 1});
                    }
                }
            }
        }

        for(int k=0; k<deads.size(); k++){ // 여름
            map[deads[k].x][deads[k].y] += deads[k].age / 2;
        }

        for(int k=1; k<=N; k++){ // 겨울
            for(int l=1; l<=N; l++){
                map[k][l] += winterAdd[k][l];
            }
        }
    }

    return Queue.size();
}

int main(){
    for(int i=0; i<=10; i++){
        for(int j=0; j<=10; j++){
            map[i][j] = 5;
        }
    }

    cin >> N >> M >> K;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> winterAdd[i][j];
        }
    }

    int x, y, z;

    for(int i=0; i<M; i++){
        cin >> x >> y >> z;

        Queue.push({x, y, z});
    }

    cout << BFS() << '\n';

    return 0;
}