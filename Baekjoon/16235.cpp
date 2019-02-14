//
// Created by Keith_Lee on 14/02/2019.
//

#include <iostream>
#include <vector>

using namespace std;

//struct deadTree{ // 죽은 나무 x좌표, y좌표, 나이
//    int x, y, age;
//};

int N, M, K;

int map[11][11] = {0, };
int winterAdd[11][11] = {0, };
vector<int> tree[11][11];

void years(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(tree[i][j].size() > 0){
                vector<int> deads; // 죽은 나무들

                sort(tree[i][j].begin(), tree[i][j].end());

                cout << tree[i][j][0] << '\n';

                for(int k=0; k<tree[i][j].size(); k++){ // 봄
                    if(tree[i][j][k] > 0 && map[i][j] >= tree[i][j][k]){ // 나무가 양분을 먹었다
                        map[i][j] -= tree[i][j][k];
                        tree[i][j][k]++;
                    }
                    else{ // 나무가 양분을 못먹고 죽었다
                        deads.push_back(tree[i][j][k]);
                        tree[i][j][k] = -1;
                    }
                }

                for(int k=0; k<deads.size(); k++){ // 여름
                    map[i][j] += (deads[k] / 2);
                }

                for(int k=0; k<tree[i][j].size(); k++){ // 가을
                    if(tree[i][j][k] % 5 == 0){ // 나무의 나이가 5의 배수이면 번식
                        tree[i-1][j-1].push_back(1);
                        tree[i-1][j].push_back(1);
                        tree[i-1][j+1].push_back(1);
                        tree[i][j-1].push_back(1);
                        tree[i][j+1].push_back(1);
                        tree[i+1][j-1].push_back(1);
                        tree[i+1][j].push_back(1);
                        tree[i+1][j+1].push_back(1);
                    }
                }

                map[i][j] += winterAdd[i][j]; // 겨울
            }
        }
    }
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

        tree[x][y].push_back(z);
    }

    for(int i=0; i<K; i++){
        years();
    }

    int result = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<tree[i][j].size(); k++){
                if(tree[i][j][k] > 0){
                    result++;
                }
            }
        }
    }

    cout << result << '\n';

    return 0;
}