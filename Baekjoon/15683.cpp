//
// Created by Keith_Lee on 16/10/2018.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int map[8][8];
int temp_map[8][8];
int result = 9999999;
vector<pair<int, int>> tvs;

void edit_map(int camX, int camY){
    int zeroCount;
    bool changed;
    int direct_map[8][8];

    if(map[camX][camY] == 1){
        for(int i=0; i<4; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<M; k++){
                    temp_map[j][k] = map[j][k];
                }
            }
            changed = false;
            zeroCount = 0;

            int nextX = camX + dx[i];
            int nextY = camY + dy[i];
            while(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M){
                if(temp_map[nextX][nextY] == 6){
                    break;
                }
                if(temp_map[nextX][nextY] == 0){
                    temp_map[nextX][nextY] = 7;
                }
                nextX += dx[i];
                nextY += dy[i];
            }

            for(int j=0; j<N; j++){
                for(int k=0; k<M; k++){
                    if(temp_map[j][k] == 0){
                        zeroCount++;
                    }
                }
            }

            if(result > zeroCount){
                changed = true;
                result = zeroCount;
            }
            if(changed){
                for(int j=0; j<N; j++){
                    for(int k=0; k<M; k++){
                        direct_map[j][k] = temp_map[j][k];
                    }
                }
            }
        }
    }
    else if(map[camX][camY] == 2){
        for(int i=0; i<2; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<M; k++){
                    temp_map[j][k] = map[j][k];
                }
            }
            changed = false;
            zeroCount = 0;

            if(i == 0){
                for(int j=camY-1; j>=0; j--){
                    if(temp_map[camX][j] == 6){
                        break;
                    }
                    if(temp_map[camX][j] == 0){
                        temp_map[camX][j] = 7;
                    }
                }
                //카메라기준 왼쪽으로
                for(int j=camY+1; j<M; j++){
                    if(temp_map[camX][j] == 6){
                        break;
                    }
                    if(temp_map[camX][j] == 0){
                        temp_map[camX][j] = 7;
                    }
                }
                //카메라기준 오른쪽으로
            }
            else if(i == 1){
                for(int j=camX-1; j>=0; j--){
                    if(temp_map[j][camY] == 6){
                        break;
                    }
                    if(temp_map[j][camY] == 0){
                        temp_map[j][camY] = 7;
                    }
                }
                //카메라기준 위쪽으로
                for(int j=camX+1; j<N; j++){
                    if(temp_map[j][camY] == 6){
                        break;
                    }
                    if(temp_map[j][camY] == 0){
                        temp_map[j][camY] = 7;
                    }
                }
                //카메라기준 아래쪽으로
            }

            for(int j=0; j<N; j++){
                for(int k=0; k<M; k++){
                    if(temp_map[j][k] == 0){
                        zeroCount++;
                    }
                }
            }

            if(result > zeroCount){
                changed = true;
                result = zeroCount;
            }
            if(changed){
                for(int j=0; j<N; j++){
                    for(int k=0; k<M; k++){
                        direct_map[j][k] = temp_map[j][k];
                    }
                }
            }
        }
    }
    else if(map[camX][camY] == 3){
        for(int i=0; i<4; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<M; k++){
                    temp_map[j][k] = map[j][k];
                }
            }
            changed = false;
            zeroCount = 0;
            if(i == 0){
                for(int j=camX-1; j>=0; j--){
                    if(temp_map[j][camY] == 6){
                        break;
                    }
                    if(temp_map[j][camY] == 0){
                        temp_map[j][camY] = 7;
                    }
                }
                //카메라기준 위쪽으로
                for(int j=camY+1; j<M; j++){
                    if(temp_map[camX][j] == 6){
                        break;
                    }
                    if(temp_map[j][camY] == 0){
                        temp_map[camX][j] = 7;
                    }
                }
                //카메라기준 오른쪽으로
            }
            else if(i == 1){
                for(int j=camY+1; j<M; j++){
                    if(temp_map[camX][j] == 6){
                        break;
                    }
                    if(temp_map[camX][j] == 0){
                        temp_map[camX][j] = 7;
                    }
                }
                //카메라기준 오른쪽으로
                for(int j=camX+1; j<N; j++){
                    if(temp_map[j][camY] == 6){
                        break;
                    }
                    if(temp_map[j][camY] == 0){
                        temp_map[j][camY] = 7;
                    }
                }
                //카메라기준 아래쪽으로
            }
            else if(i == 2){
                for(int j=camX+1; j<N; j++){
                    if(temp_map[j][camY] == 6){
                        break;
                    }
                    if(temp_map[j][camY] == 0){
                        temp_map[j][camY] = 7;
                    }
                }
                //카메라기준 아래쪽으로
                for(int j=camY-1; j>=0; j--){
                    if(temp_map[camX][j] == 6){
                        break;
                    }
                    if(temp_map[camX][j] == 0){
                        temp_map[camX][j] = 7;
                    }
                }
                //카메라기준 왼쪽으로
            }
            else if(i == 3){
                for(int j=camY-1; j>=0; j--){
                    if(temp_map[camX][j] == 6){
                        break;
                    }
                    if(temp_map[camX][j] == 0) {
                        temp_map[camX][j] = 7;
                    }
                }
                //카메라기준 왼쪽으로
                for(int j=camX-1; j>=0; j--){
                    if(temp_map[j][camY] == 6){
                        break;
                    }
                    if(temp_map[j][camY] == 0){
                        temp_map[j][camY] = 7;
                    }
                }
                //카메라기준 위쪽으로
            }

            for(int j=0; j<N; j++){
                for(int k=0; k<M; k++){
                    if(temp_map[j][k] == 0){
                        zeroCount++;
                    }
                }
            }

            if(result > zeroCount){
                changed = true;
                result = zeroCount;
            }
            if(changed){
                for(int j=0; j<N; j++){
                    for(int k=0; k<M; k++){
                        direct_map[j][k] = temp_map[j][k];
                    }
                }
            }
        }
    }
    else if(map[camX][camY] == 4){
        for(int i=0; i<4; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<M; k++){
                    temp_map[j][k] = map[j][k];
                }
            }
            changed = false;
            zeroCount = 0;

            if(i == 0){
                for(int j=camY-1; j>=0; j--){
                    if(temp_map[camX][j] == 6){
                        break;
                    }
                    if(temp_map[camX][j] == 0){
                        temp_map[camX][j] = 7;
                    }
                }
                //카메라기준 왼쪽으로
                for(int j=camX-1; j>=0; j--){
                    if(temp_map[j][camY] == 6){
                        break;
                    }
                    if(temp_map[j][camY] == 0){
                        temp_map[j][camY] = 7;
                    }
                }
                //카메라기준 위쪽으로
                for(int j=camY+1; j<M; j++){
                    if(temp_map[camX][j] == 6){
                        break;
                    }
                    if(temp_map[camX][j] == 0){
                        temp_map[camX][j] = 7;
                    }
                }
                //카메라기준 오른쪽으로
            }
            else if(i == 1){
                for(int j=camX-1; j>=0; j--){
                    if(temp_map[j][camY] == 6){
                        break;
                    }
                    if(temp_map[j][camY] == 0){
                        temp_map[j][camY] = 7;
                    }
                }
                //카메라기준 위쪽으로
                for(int j=camY+1; j<M; j++){
                    if(temp_map[camX][j] == 6){
                        break;
                    }
                    if(temp_map[camX][j] == 0){
                        temp_map[camX][j] = 7;
                    }
                }
                //카메라기준 오른쪽으로
                for(int j=camX+1; j<N; j++){
                    if(temp_map[j][camY] == 6){
                        break;
                    }
                    if(temp_map[j][camY] == 0){
                        temp_map[j][camY] = 7;
                    }
                }
                //카메라기준 아래쪽으로
            }
            else if(i == 2){
                for(int j=camY+1; j<M; j++){
                    if(temp_map[camX][j] == 6){
                        break;
                    }
                    if(temp_map[camX][j] == 0){
                        temp_map[camX][j] = 7;
                    }
                }
                //카메라기준 오른쪽으로
                for(int j=camX+1; j<N; j++){
                    if(temp_map[j][camY] == 6){
                        break;
                    }
                    if(temp_map[j][camY] == 0){
                        temp_map[j][camY] = 7;
                    }
                }
                //카메라기준 아래쪽으로
                for(int j=camY-1; j>=0; j--){
                    if(temp_map[camX][j] == 6){
                        break;
                    }
                    if(temp_map[camX][j] == 0){
                        temp_map[camX][j] = 7;
                    }
                }
                //카메라기준 왼쪽으로
            }
            else if(i == 3){
                for(int j=camX+1; j<N; j++){
                    if(temp_map[j][camY] == 6){
                        break;
                    }
                    if(temp_map[j][camY] == 0){
                        temp_map[j][camY] = 7;
                    }
                }
                //카메라기준 아래쪽으로
                for(int j=camY-1; j>=0; j--){
                    if(temp_map[camX][j] == 6){
                        break;
                    }
                    if(temp_map[camX][j] == 0){
                        temp_map[camX][j] = 7;
                    }
                }
                //카메라기준 왼쪽으로
                for(int j=camX-1; j>=0; j--){
                    if(temp_map[j][camY] == 6){
                        break;
                    }
                    if(temp_map[j][camY] == 0){
                        temp_map[j][camY] = 7;
                    }
                }
                //카메라기준 위쪽으로
            }

            for(int j=0; j<N; j++){
                for(int k=0; k<M; k++){
                    if(temp_map[j][k] == 0){
                        zeroCount++;
                    }
                }
            }

            if(result > zeroCount){
                changed = true;
                result = zeroCount;
            }
            if(changed){
                for(int j=0; j<N; j++){
                    for(int k=0; k<M; k++){
                        direct_map[j][k] = temp_map[j][k];
                    }
                }
            }
        }
    }
    else if(map[camX][camY] == 5){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                temp_map[j][k] = map[j][k];
            }
        }
        for(int j=camY-1; j>=0; j--){
            if(temp_map[camX][j] == 6){
                break;
            }
            if(temp_map[camX][j] == 0){
                temp_map[camX][j] = 7;
            }
        }
        //카메라기준 왼쪽으로
        for(int j=camX-1; j>=0; j--){
            if(temp_map[j][camY] == 6){
                break;
            }
            if(temp_map[j][camY] == 0){
                temp_map[j][camY] = 7;
            }
        }
        //카메라기준 위쪽으로
        for(int j=camY+1; j<M; j++){
            if(temp_map[camX][j] == 6){
                break;
            }
            if(temp_map[camX][j] == 0){
                temp_map[camX][j] = 7;
            }
        }
        //카메라기준 오른쪽으로
        for(int j=camX+1; j<N; j++){
            if(temp_map[j][camY] == 6){
                break;
            }
            if(temp_map[j][camY] == 0){
                temp_map[j][camY] = 7;
            }
        }
        //카메라기준 아래쪽으로

        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                direct_map[j][k] = temp_map[j][k];
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(direct_map[i][j] == 7){
                map[i][j] = 7;
            }
        }
    }
}

int main(){
    memset(map, -1, sizeof(map));
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j] != 0 && map[i][j] != 6){
                tvs.push_back(make_pair(i, j));
            }
        }
    }

    for(int i=0; i<tvs.size(); i++){
        edit_map(tvs[i].first, tvs[i].second);
    }

    int zeroCount = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 0){
                zeroCount++;
            }
        }
    }
    result = zeroCount;

    cout << result << '\n';

    return 0;
}