//
// Created by Keith_Lee on 19/10/2018.
//
#include <iostream>
#include <vector>

using namespace std;

int N, M, x, y, K;
int map[20][20];
int temp_dice[7] = {-1, };
vector<int> orders;

void move_left(int dice[]){
    temp_dice[1] = dice[3];
    temp_dice[2] = dice[2];
    temp_dice[3] = dice[6];
    temp_dice[4] = dice[1];
    temp_dice[5] = dice[5];
    temp_dice[6] = dice[4];
}

void move_right(int dice[]){
    temp_dice[1] = dice[4];
    temp_dice[2] = dice[2];
    temp_dice[3] = dice[1];
    temp_dice[4] = dice[6];
    temp_dice[5] = dice[5];
    temp_dice[6] = dice[3];
}

void move_up(int dice[]){
    temp_dice[1] = dice[5];
    temp_dice[2] = dice[1];
    temp_dice[3] = dice[3];
    temp_dice[4] = dice[4];
    temp_dice[5] = dice[6];
    temp_dice[6] = dice[2];
}

void move_down(int dice[]){
    temp_dice[1] = dice[2];
    temp_dice[2] = dice[6];
    temp_dice[3] = dice[3];
    temp_dice[4] = dice[4];
    temp_dice[5] = dice[1];
    temp_dice[6] = dice[5];
}

int main(){
    cin >> N >> M >> x >> y >> K;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }

    int dice[7] = {-1, 0, 0, 0, 0, 0, 0};

    int order;
    for(int i=0; i<K; i++){
        cin >> order;
        orders.push_back(order);
    }

    vector<int> result;

    for(int i=0; i<orders.size(); i++){
        if(orders[i] == 1 && y+1 < M){
            move_right(dice);
            for(int j=1; j<=6; j++){
                dice[j] = temp_dice[j];
            }
            y++;
            if(map[x][y]){
                dice[6] = map[x][y];
                map[x][y] = 0;
            }
            else{
                map[x][y] = dice[6];
            }
            result.push_back(dice[1]);
        }
        else if(orders[i] == 2 && y-1 >= 0){
            move_left(dice);
            for(int j=1; j<=6; j++){
                dice[j] = temp_dice[j];
            }
            y--;
            if(map[x][y]){
                dice[6] = map[x][y];
                map[x][y] = 0;
            }
            else{
                map[x][y] = dice[6];
            }
            result.push_back(dice[1]);
        }
        else if(orders[i] == 3 && x-1 >= 0){
            move_up(dice);
            for(int j=1; j<=6; j++){
                dice[j] = temp_dice[j];
            }
            x--;
            if(map[x][y]){
                dice[6] = map[x][y];
                map[x][y] = 0;
            }
            else{
                map[x][y] = dice[6];
            }
            result.push_back(dice[1]);
        }
        else if(orders[i] == 4 && x+1 < N){
            move_down(dice);
            for(int j=1; j<=6; j++){
                dice[j] = temp_dice[j];
            }
            x++;
            if(map[x][y]){
                dice[6] = map[x][y];
                map[x][y] = 0;
            }
            else{
                map[x][y] = dice[6];
            }
            result.push_back(dice[1]);
        }
    }


    for(int i=0; i<result.size(); i++){
        cout << result[i] << '\n';
    }

    return 0;
}