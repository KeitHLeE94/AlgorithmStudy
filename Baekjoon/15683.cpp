//
// Created by Keith_Lee on 18/10/2018.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct CCTV{
    int x;
    int y;
    int type;
    bool visit;
};

int N, M;
int map[8][8];
int temp_map[8][8];
int result = 9999999;

vector<CCTV> cctvs;

void go_left(CCTV cctv, int past_map[8][8]){
    for(int i=cctv.y-1; i>=0; i--){
        if(past_map[cctv.x][i] == 6){
            break;
        }
        if(past_map[cctv.x][i] == 0){
            past_map[cctv.x][i] = 7;
        }
    }
}

void go_right(CCTV cctv, int past_map[8][8]){
    for(int i=cctv.y+1; i<M; i++){
        if(past_map[cctv.x][i] == 6){
            break;
        }
        if(past_map[cctv.x][i] == 0){
            past_map[cctv.x][i] = 7;
        }
    }
}

void go_up(CCTV cctv, int past_map[8][8]){
    for(int i=cctv.x-1; i>=0; i--){
        if(past_map[i][cctv.y] == 6){
            break;
        }
        if(past_map[i][cctv.y] == 0){
            past_map[i][cctv.y] = 7;
        }
    }
}

void go_down(CCTV cctv, int past_map[8][8]){
    for(int i=cctv.x+1; i<N; i++){
        if(past_map[i][cctv.y] == 6){
            break;
        }
        if(past_map[i][cctv.y] == 0){
            past_map[i][cctv.y] = 7;
        }
    }
}

void DFS(int cnt, int past_map[8][8]){
    int current_map[8][8];

    if(cnt == cctvs.size()){
        int unseen = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(past_map[i][j] == 0){
                    unseen++;
                }
            }
        }

        result = min(result, unseen);

        return;
    }

    if(cctvs[cnt].type == 1 && !cctvs[cnt].visit){
        for(int i=0; i<4; i++){
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    current_map[i][j] = past_map[i][j];
                }
            }
            if(i == 0){
                go_left(cctvs[cnt], current_map);
            }
            else if(i == 1){
                go_right(cctvs[cnt], current_map);
            }
            else if(i == 2){
                go_up(cctvs[cnt], current_map);
            }
            else if(i == 3){
                go_down(cctvs[cnt], current_map);
            }
            cctvs[cnt].visit = true;
            DFS(cnt+1, current_map);
            cctvs[cnt].visit = false;
        }
    }
    else if(cctvs[cnt].type == 2 && !cctvs[cnt].visit){
        for(int i=0; i<2; i++){
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    current_map[i][j] = past_map[i][j];
                }
            }
            if(i == 0){
                go_down(cctvs[cnt], current_map);
                go_up(cctvs[cnt], current_map);
            }
            else if(i == 1){
                go_left(cctvs[cnt], current_map);
                go_right(cctvs[cnt], current_map);
            }
            cctvs[cnt].visit = true;
            DFS(cnt+1, current_map);
            cctvs[cnt].visit = false;
        }
    }
    else if(cctvs[cnt].type == 3 && !cctvs[cnt].visit){
        for(int i=0; i<4; i++){
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    current_map[i][j] = past_map[i][j];
                }
            }
            if(i == 0){
                go_up(cctvs[cnt], current_map);
                go_right(cctvs[cnt], current_map);
            }
            else if(i == 1){
                go_right(cctvs[cnt], current_map);
                go_down(cctvs[cnt], current_map);
            }
            else if(i == 2){
                go_down(cctvs[cnt], current_map);
                go_left(cctvs[cnt], current_map);
            }
            else if(i == 3){
                go_left(cctvs[cnt], current_map);
                go_up(cctvs[cnt], current_map);
            }
            cctvs[cnt].visit = true;
            DFS(cnt+1, current_map);
            cctvs[cnt].visit = false;
        }
    }
    else if(cctvs[cnt].type == 4 && !cctvs[cnt].visit){
        for(int i=0; i<4; i++){
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    current_map[i][j] = past_map[i][j];
                }
            }
            if(i == 0){
                go_left(cctvs[cnt], current_map);
                go_up(cctvs[cnt], current_map);
                go_right(cctvs[cnt], current_map);
            }
            else if(i == 1){
                go_up(cctvs[cnt], current_map);
                go_right(cctvs[cnt], current_map);
                go_down(cctvs[cnt], current_map);
            }
            else if(i == 2){
                go_right(cctvs[cnt], current_map);
                go_down(cctvs[cnt], current_map);
                go_left(cctvs[cnt], current_map);
            }
            else if(i == 3){
                go_down(cctvs[cnt], current_map);
                go_left(cctvs[cnt], current_map);
                go_up(cctvs[cnt], current_map);
            }
            cctvs[cnt].visit = true;
            DFS(cnt+1, current_map);
            cctvs[cnt].visit = false;
        }
    }
    else if(cctvs[cnt].type == 5 && !cctvs[cnt].visit){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                current_map[i][j] = past_map[i][j];
            }
        }
        go_up(cctvs[cnt], current_map);
        go_right(cctvs[cnt], current_map);
        go_down(cctvs[cnt], current_map);
        go_left(cctvs[cnt], current_map);
        cctvs[cnt].visit = true;
        DFS(cnt+1, current_map);
        cctvs[cnt].visit = false;
    }
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            temp_map[i][j] = map[i][j];
            if(0 < map[i][j] && map[i][j] < 6){
                CCTV temp = {i, j, map[i][j], false};
                cctvs.push_back(temp);
            }
        }
    }

    DFS(0, temp_map);

    cout << result << '\n';

    return 0;
}