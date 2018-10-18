//
// Created by Keith_Lee on 16/10/2018.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int map[8][8];
int temp_map[8][8];
int result = 9999999;
vector<pair<int, int>> tvs;

void go_left(int x, int y){
    for(int i=y; i>=0; i--){
        if(temp_map[x][i] == 6){
            break;
        }
        if(temp_map[x][i] == 0){
            temp_map[x][i] = 7;
        }
    }
}

void go_right(int x, int y){
    for(int i=y; i<M; i++){
        if(temp_map[x][i] == 6){
            break;
        }
        if(temp_map[x][i] == 0){
            temp_map[x][i] = 7;
        }
    }
}

void go_up(int x, int y){
    for(int i=x; i>=0; i--){
        if(temp_map[i][y] == 6){
            break;
        }
        if(temp_map[i][y] == 0){
            temp_map[i][y] = 7;
        }
    }
}

void go_down(int x, int y){
    for(int i=x; i<N; i++){
        if(temp_map[i][y] == 6){
            break;
        }
        if(temp_map[i][y] == 0){
            temp_map[i][y] = 7;
        }
    }
}

int zero_count(){
    int result = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(temp_map[i][j] == 0){
                result++;
            }
        }
    }

    return result;
}

void map_initialize(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            temp_map[i][j] = map[i][j];
        }
    }
}

void edit_map(int camX, int camY){
    bool changed;
    int direct_map[8][8];

    if(map[camX][camY] == 1){
        for(int i=0; i<4; i++){
            map_initialize();

            changed = false;

            if(i == 0){
                go_left(camX, camY);
            }
            else if(i == 1){
                go_right(camX, camY);
            }
            else if(i == 2){
                go_up(camX, camY);
            }
            else if(i == 3){
                go_down(camX, camY);
            }

            int zeroCount = zero_count();

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
            map_initialize();

            changed = false;

            if(i == 0){
                go_left(camX, camY);
                go_right(camX, camY);
            }
            else if(i == 1){
                go_up(camX, camY);
                go_down(camX, camY);
            }

            int zeroCount = zero_count();

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
            map_initialize();

            changed = false;

            if(i == 0){
                go_up(camX, camY);
                go_right(camX, camY);
            }
            else if(i == 1){
                go_right(camX, camY);
                go_down(camX, camY);
            }
            else if(i == 2){
                go_down(camX, camY);
                go_left(camX, camY);
            }
            else if(i == 3){
                go_left(camX, camY);
                go_up(camX, camY);
            }

            int zeroCount = zero_count();

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
            map_initialize();

            changed = false;

            if(i == 0){
                go_left(camX, camY);
                go_up(camX, camY);
                go_right(camX, camY);
            }
            else if(i == 1){
                go_up(camX, camY);
                go_right(camX, camY);
                go_down(camX, camY);
            }
            else if(i == 2){
                go_right(camX, camY);
                go_down(camX, camY);
                go_left(camX, camY);
            }
            else if(i == 3){
                go_down(camX, camY);
                go_left(camX, camY);
                go_up(camX, camY);
            }

            int zeroCount = zero_count();

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
        map_initialize();
        go_left(camX, camY);
        go_right(camX, camY);
        go_down(camX, camY);
        go_up(camX, camY);

        int zeroCount = zero_count();

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

    cout << result << '\n';

    return 0;
}