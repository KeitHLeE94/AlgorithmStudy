//
// Created by Keith_Lee on 15/01/2019.
//

/**
 * 풀이방법
 * 1. 입력된 지도에서 4방향에 대해 current와 next의 차이의 절대값을 구한다.
 * 2. 그 차이가 L과 R 사이에 있으면 toChange의 next 값을 1로 바꾼다.
 * 3. map의 값을 toChange가 1인 것들의 평균값으로 바꾼다.
 * 4. 더이상 바꿀 수 없을때까지 1~3을 반복한다.
 */

#include <iostream>
#include <memory.h>

using namespace std;

int N, L, R;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int countOne(int toCheck[][N]){
    int result = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(toCheck[i][j] == 1){
                result++;
            }
        }
    }

    return result;
}

int main(){
    cin >> N >> L >> R;

    int map[N][N];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    int toChange[N][N];

    memset(toChange, 0, sizeof(toChange));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int currentX = i;
            int currentY = j;

            for(int k=0; k<4; k++){
                int nextX = currentX + dx[k];
                int nextY = currentY + dy[k];

                if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N){
                    int gap = abs(map[currentX][currentY] - map[nextX][nextY]);
                    if(gap >= L && gap <= R && toChange[nextX][nextY] != 1){
                        toChange[nextX][nextY] = 1;
                    }
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << toChange[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}