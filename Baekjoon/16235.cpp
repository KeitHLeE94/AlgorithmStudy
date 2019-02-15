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

//struct deadTree{ // 죽은 나무 x좌표, y좌표, 나이
//    int x, y, age;
//};

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

        for(int j=1; j<=N; j++){
            for(int k=1; k<=N; k++){
                cout << map[j][k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';

        for(int j=0; j<lives.size(); j++){
            cout << lives[j].age << ' ';
        }
        cout << '\n';
        cout << '\n';

        for(int j=0; j<lives.size(); j++) {
            if (map[lives[j].x][lives[j].y] >= lives[j].age) { // 봄
                map[lives[j].x][lives[j].y] -= lives[j].age;
                Queue.push({lives[j].x, lives[j].y, lives[j].age + 1});
                lives[j].age++;
            }
            else {
                deads.push_back({lives[j].x, lives[j].y, lives[j].age});
            }

            if(lives[j].age % 5 == 0){ // 가을
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

        for(int j=1; j<=N; j++){
            for(int k=1; k<=N; k++){
                cout << map[j][k] << ' ';
            }
            cout << '\n';
        }

        cout << "======================================" << '\n';
    }

    return Queue.size();
}

//void years(){
//    for(int i=1; i<=N; i++){
//        for(int j=1; j<=N; j++){
//            if(tree[i][j].size() > 0){
//                vector<int> deads; // 죽은 나무들
//
//                sort(tree[i][j].begin(), tree[i][j].end());
//
//                cout << tree[i][j][0] << '\n';
//
//                for(int k=0; k<tree[i][j].size(); k++){ // 봄
//                    if(tree[i][j][k] > 0 && map[i][j] >= tree[i][j][k]){ // 나무가 양분을 먹었다
//                        map[i][j] -= tree[i][j][k];
//                        tree[i][j][k]++;
//                    }
//                    else{ // 나무가 양분을 못먹고 죽었다
//                        deads.push_back(tree[i][j][k]);
//                        tree[i][j][k] = -1;
//                    }
//                }
//
//                for(int k=0; k<deads.size(); k++){ // 여름
//                    map[i][j] += (deads[k] / 2);
//                }
//
//                for(int k=0; k<tree[i][j].size(); k++){ // 가을
//                    if(tree[i][j][k] % 5 == 0){ // 나무의 나이가 5의 배수이면 번식
//                        tree[i-1][j-1].push_back(1);
//                        tree[i-1][j].push_back(1);
//                        tree[i-1][j+1].push_back(1);
//                        tree[i][j-1].push_back(1);
//                        tree[i][j+1].push_back(1);
//                        tree[i+1][j-1].push_back(1);
//                        tree[i+1][j].push_back(1);
//                        tree[i+1][j+1].push_back(1);
//                    }
//                }
//
//                map[i][j] += winterAdd[i][j]; // 겨울
//            }
//        }
//    }
//}

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

    while(!Queue.empty()){
        cout << Queue.front().x << ", " << Queue.front().y << ": " << Queue.front().age << '\n';
        Queue.pop();
    }

    return 0;
}