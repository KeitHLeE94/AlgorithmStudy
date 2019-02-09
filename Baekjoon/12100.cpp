//
// Created by Keith_Lee on 08/02/2019.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int result = 0;

int (*push(int direction, int (*map)[20]))[20]{ // 이동시킨 후 바뀐 map 리턴.
    // 상
    if(direction == 1){
        for(int i=0; i<N; i++){
            vector<int> toMove; // 위로 이동시킬 숫자들
            queue<int> merge; // 이동 후 같은 숫자일때 합치고 저장

            for(int j=0; j<N; j++){
                if(map[j][i] != 0){ // 위로 이동시킬 숫자가 있으면
                    toMove.push_back(map[j][i]); // 벡터에 넣고
                    map[j][i] = 0; // 숫자 자리를 0으로 만든다.
                }
            }

            for(int j=0; j<toMove.size(); j++){
                if(j+1 < toMove.size() && toMove[j] == toMove[j+1]){ // 벡터 내에서 같은 숫자가 연속될 경우
                    toMove[j] *= 2; // 합친다
                    toMove[j+1] = 0; // 뒷 숫자를 0으로 만든다.
                }
            }

            for(int j=0; j<toMove.size(); j++){ // 벡터를 돌면서
                if(toMove[j] != 0){ // 원소가 0이 아니면
                    merge.push(toMove[j]); // 큐에 넣는다.
                }
            }

            int index = 0;

            while(!merge.empty()){ // 큐를 돌면서
                map[index][i] = merge.front(); // 바뀐 숫자를 맵에 반영한다.
                merge.pop();
                index++;
            }
        }
    }

    // 하
    if(direction == 2){
        for(int i=0; i<N; i++){
            vector<int> toMove; // 아래로 이동시킬 숫자들
            queue<int> merge; // 이동 후 같은 숫자일때 합치고 저장

            for(int j=N-1; j>=0; j--){ // 아래쪽부터 돌거임
                if(map[j][i] != 0){ // 아래로 이동시킬 숫자가 있으면
                    toMove.push_back(map[j][i]); // 벡터에 넣고
                    map[j][i] = 0; // 숫자 자리를 0으로 만든다.
                }
            }

            for(int j=0; j<toMove.size(); j++){
                if(j+1 < toMove.size() && toMove[j] == toMove[j+1]){ // 벡터 내에서 같은 숫자가 연속될 경우
                    toMove[j] *= 2; // 합친다
                    toMove[j+1] = 0; // 뒷 숫자를 0으로 만든다.
                }
            }

            for(int j=0; j<toMove.size(); j++){ // 벡터를 돌면서
                if(toMove[j] != 0){ // 원소가 0이 아니면
                    merge.push(toMove[j]); // 큐에 넣는다.
                }
            }

            int index = 0;

            while(!merge.empty()){ // 큐를 돌면서
                map[N-1-index][i] = merge.front(); // 바뀐 숫자를 맵에 반영한다.
                merge.pop();
                index++;
            }
        }
    }

    // 좌
    if(direction == 3){
        for(int i=0; i<N; i++){
            vector<int> toMove; // 왼쪽으로 이동시킬 숫자들
            queue<int> merge; // 이동 후 같은 숫자일때 합치고 저장

            for(int j=0; j<N; j++){
                if(map[i][j] != 0){ // 왼쪽으로 이동시킬 숫자가 있으면
                    toMove.push_back(map[i][j]); // 벡터에 넣고
                    map[i][j] = 0; // 숫자 자리를 0으로 만든다.
                }
            }

            for(int j=0; j<toMove.size(); j++){
                if(j+1 < toMove.size() && toMove[j] == toMove[j+1]){ // 벡터 내에서 같은 숫자가 연속될 경우
                    toMove[j] *= 2; // 합친다
                    toMove[j+1] = 0; // 뒷 숫자를 0으로 만든다.
                }
            }

            for(int j=0; j<toMove.size(); j++){ // 벡터를 돌면서
                if(toMove[j] != 0){ // 원소가 0이 아니면
                    merge.push(toMove[j]); // 큐에 넣는다.
                }
            }

            int index = 0;

            while(!merge.empty()){ // 큐를 돌면서
                map[i][index] = merge.front(); // 바뀐 숫자를 맵에 반영한다.
                merge.pop();
                index++;
            }
        }
    }

    // 우
    if(direction == 4){
        for(int i=0; i<N; i++){
            vector<int> toMove; // 오른쪽으로 이동시킬 숫자들
            queue<int> merge; // 이동 후 같은 숫자일때 합치고 저장

            for(int j=N-1; j>=0; j--){ // 오른쪽부터 돌거임
                if(map[i][j] != 0){ // 오른쪽으로 이동시킬 숫자가 있으면
                    toMove.push_back(map[i][j]); // 벡터에 넣고
                    map[i][j] = 0; // 숫자 자리를 0으로 만든다.
                }
            }

            for(int j=0; j<toMove.size(); j++){
                if(j+1 < toMove.size() && toMove[j] == toMove[j+1]){ // 벡터 내에서 같은 숫자가 연속될 경우
                    toMove[j] *= 2; // 합친다
                    toMove[j+1] = 0; // 뒷 숫자를 0으로 만든다.
                }
            }

            for(int j=0; j<toMove.size(); j++){ // 벡터를 돌면서
                if(toMove[j] != 0){ // 원소가 0이 아니면
                    merge.push(toMove[j]); // 큐에 넣는다.
                }
            }

            int index = 0;

            while(!merge.empty()){ // 큐를 돌면서
                map[i][N-1-index] = merge.front(); // 바뀐 숫자를 맵에 반영한다.
                merge.pop();
                index++;
            }
        }
    }

    return map;
}

void DFS(int count, int (*map)[20]){
    if(count == 5){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j] > result){
                    result = map[i][j];
                }
            }
        }
        return;
    }

    int (*newMap)[20];

    for(int i=1; i<=4; i++){
        newMap = push(i, map);
        DFS(count+1, newMap);
    }
}

int main(){
    cin >> N;

    int map[20][20] = {0, };

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    DFS(0, map);

    cout << result << '\n';

    return 0;
}