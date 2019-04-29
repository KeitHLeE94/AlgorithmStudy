//
// Created by Keith_Lee on 29/04/2019.
//

#include <iostream>
#include <memory.h>

using namespace std;

int N, M, H;
int result = -1;

int origin[31][11] = {0, };

void DFS(int limit, int count, int visit[31][11]){
    if(limit == count){
        for(int i=1; i<=N; i++){ // 세로줄
            int end = i;

            for(int j=1; j<=H; j++){ // 가로줄
                if(end-1 >= 1 && visit[j][end-1] == 1){
                    end--;
                }
                else if(end+1 <= N && visit[j][end] == 1){
                    end++;
                }
            }

            if(end != i){
                return;
            }
        }

        result = limit;
        return;
    }

    int tempVisit[31][11] = {0, };

    memcpy(tempVisit, visit, sizeof(int) * 31 * 11);

    for(int i=1; i<=H; i++){
        for(int j=1; j<N; j++){
            tempVisit[i][j] = visit[i][j];
        }
    }

    for(int i=1; i<=H; i++){
        for(int j=1; j<N; j++){
            if(tempVisit[i][j] == 0){
                tempVisit[i][j] = 1;
                tempVisit[i][j-1] = 2;
                tempVisit[i][j+1] = 2;

                DFS(limit, count+1, tempVisit);

                tempVisit[i][j] = 0;
                tempVisit[i][j-1] = 0;
                tempVisit[i][j+1] = 0;
                memcpy(tempVisit, visit, sizeof(int) * 31 * 11);
            }
        }
    }
}

int main(){
    cin >> N >> M >> H;

    // 0: 가로줄 놓을수 있음, 1: 이미 가로줄 놓여있음, 2: 가로줄 놓을수 없음
    int visit[31][11] = {0, }; // 세로 = 0번 무시, 가로 = 0번 무시, N번 무시

    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;

        visit[a][b] = 1; // 이미 놓인 가로줄
        visit[a][b-1] = 2; // 이미 있는 가로줄 왼쪽은 못쓴다
        visit[a][b+1] = 2; // 이미 있는 가로줄 오른쪽도 못쓴다
        origin[a][b] = 1;
        origin[a][b-1] = 2;
        origin[a][b+1] = 2;
    }

    for(int i=0; i<=3; i++){
        if(result != -1){
            break;
        }
        DFS(i, 0, visit);
    }

    cout << result << '\n';

    return 0;
}