//
// Created by Keith_Lee on 12/02/2019.
//

#include <iostream>

using namespace std;

int N, M;
int map[500][500] = {0, };
int result = 0;

int max(int a, int b){
    return a < b ? b : a;
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int shape=0; shape<19; shape++) {
                int sum = 0;

                switch (shape) {
                    case 0:
                        if(j+3 < M){
                            sum += map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3];
                        }
                        break;
                    case 1:
                        if(i+3 < N){
                            sum += map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
                        }
                        break;
                    case 2:
                        if(i+1 < N && j+1 < M){
                            sum += map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j+1];
                        }
                        break;
                    case 3:
                        if(i+2 < N && j+1 < M){
                            sum += map[i][j] + map[i+1][j] + map[i+2][j] + map[i+2][j+1];
                        }
                        break;
                    case 4:
                        if(i+2 < N && j-1 >= 0){
                            sum += map[i][j] + map[i+1][j] + map[i+2][j] + map[i+2][j-1];
                        }
                        break;
                    case 5:
                        if(i+1 < N && j+2 < M){
                            sum += map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j];
                        }
                        break;
                    case 6:
                        if(i+1 < N && j+2 < M){
                            sum += map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+2];
                        }
                        break;
                    case 7:
                        if(i+2 < N && j+1 < M){
                            sum += map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1];
                        }
                        break;
                    case 8:
                        if(i+2 < N && j+1 < M){
                            sum += map[i][j] + map[i][j+1] + map[i+1][j] + map[i+2][j];
                        }
                        break;
                    case 9:
                        if(i-1 >= 0 && j+2 < M){
                            sum += map[i][j] + map[i][j+1] + map[i][j+2] + map[i-1][j+2];
                        }
                        break;
                    case 10:
                        if(i+1 < N && j+2 < M){
                            sum += map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2];
                        }
                        break;
                    case 11:
                        if(i+2 < N && j+1 < M){
                            sum += map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+2][j+1];
                        }
                        break;
                    case 12:
                        if(i-1 >= 0 && j+2 < M){
                            sum += map[i][j] + map[i][j+1] + map[i-1][j+1] + map[i-1][j+2];
                        }
                        break;
                    case 13:
                        if(i+2 < N && j-1 >= 0){
                            sum += map[i][j] + map[i+1][j] + map[i+1][j-1] + map[i+2][j-1];
                        }
                        break;
                    case 14:
                        if(i+1 < N && j+2 < M){
                            sum += map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+1][j+2];
                        }
                        break;
                    case 15:
                        if(i+1 < N && j+2 < M){
                            sum += map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1];
                        }
                        break;
                    case 16:
                        if(i+2 < N && i-1 >= 0 && j+1 < M){
                            sum += map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i-1][j+1];
                        }
                        break;
                    case 17:
                        if(i-1 >= 0 && j+2 < M){
                            sum += map[i][j] + map[i][j+1] + map[i-1][j+1] + map[i][j+2];
                        }
                        break;
                    case 18:
                        if(i+2 < N && j+1 < M){
                            sum += map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1];
                        }
                        break;
                }

                result = max(sum, result);
            }
        }
    }

    cout << result << '\n';

    return 0;
}