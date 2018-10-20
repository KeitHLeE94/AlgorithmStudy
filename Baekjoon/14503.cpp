//
// Created by Keith_Lee on 20/10/2018.
//
#include <iostream>

using namespace std;

int N, M, r, c, d;
int map[50][50];

int main(){
    cin >> N >> M;
    cin >> r >> c >> d;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }

    while(true){
        if(map[r][c] == 0){
            map[r][c] = 2;
        }

        if(map[r-1][c] != 0 && map[r+1][c] != 0 && map[r][c-1] != 0 && map[r][c+1] != 0){
            if(d == 0){
                if(map[r+1][c] == 1){
                    break;
                }
                else{
                    r++;
                }
            }
            else if(d == 1){
                if(map[r][c-1] == 1){
                    break;
                }
                else{
                    c--;
                }
            }
            else if(d == 2){
                if(map[r-1][c] == 1){
                    break;
                }
                else{
                    r--;
                }
            }
            else if(d == 3){
                if(map[r][c+1] == 1){
                    break;
                }
                else{
                    c++;
                }
            }
        }

        else {
            if (d == 0) { //북쪽
                if (map[r][c - 1] == 0) {
                    c--;
                }
                d = 3;
            } else if (d == 1) { //동쪽
                if (map[r - 1][c] == 0) {
                    r--;
                }
                d = 0;
            } else if (d == 2) { //남쪽
                if (map[r][c + 1] == 0) {
                    c++;
                }
                d = 1;
            } else if (d == 3) { //서쪽
                if (map[r + 1][c] == 0) {
                    r++;
                }
                d = 2;
            }
        }
    }

    int result = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 2){
                result++;
            }
        }
    }

    cout << result << '\n';

    return 0;
}