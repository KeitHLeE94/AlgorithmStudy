//
// Created by Keith_Lee on 08/02/2019.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int result = 0;
int map[20][20] = {0, };

string progress = "MMMMM";

int (*push(char direction, int (*tempMap)[20]))[20]{ // 이동시킨 후 바뀐 map 리턴.
    // 상
    if(direction == 'U'){
        for(int i=0; i<N; i++){
            vector<int> toMove; // 위로 이동시킬 숫자들
            queue<int> merge; // 이동 후 같은 숫자일때 합치고 저장

            for(int j=0; j<N; j++){
                if(tempMap[j][i] != 0){ // 위로 이동시킬 숫자가 있으면
                    toMove.push_back(tempMap[j][i]); // 벡터에 넣고
                    tempMap[j][i] = 0; // 숫자 자리를 0으로 만든다.
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
                tempMap[index][i] = merge.front(); // 바뀐 숫자를 맵에 반영한다.
                merge.pop();
                index++;
            }
        }
    }

    // 하
    if(direction == 'D'){
        for(int i=0; i<N; i++){
            vector<int> toMove; // 아래로 이동시킬 숫자들
            queue<int> merge; // 이동 후 같은 숫자일때 합치고 저장

            for(int j=N-1; j>=0; j--){ // 아래쪽부터 돌거임
                if(tempMap[j][i] != 0){ // 아래로 이동시킬 숫자가 있으면
                    toMove.push_back(tempMap[j][i]); // 벡터에 넣고
                    tempMap[j][i] = 0; // 숫자 자리를 0으로 만든다.
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
                tempMap[N-1-index][i] = merge.front(); // 바뀐 숫자를 맵에 반영한다.
                merge.pop();
                index++;
            }
        }
    }

    // 좌
    if(direction == 'L'){
        for(int i=0; i<N; i++){
            vector<int> toMove; // 왼쪽으로 이동시킬 숫자들
            queue<int> merge; // 이동 후 같은 숫자일때 합치고 저장

            for(int j=0; j<N; j++){
                if(tempMap[i][j] != 0){ // 왼쪽으로 이동시킬 숫자가 있으면
                    toMove.push_back(tempMap[i][j]); // 벡터에 넣고
                    tempMap[i][j] = 0; // 숫자 자리를 0으로 만든다.
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
                tempMap[i][index] = merge.front(); // 바뀐 숫자를 맵에 반영한다.
                merge.pop();
                index++;
            }
        }
    }

    // 우
    if(direction == 'R'){
        for(int i=0; i<N; i++){
            vector<int> toMove; // 오른쪽으로 이동시킬 숫자들
            queue<int> merge; // 이동 후 같은 숫자일때 합치고 저장

            for(int j=N-1; j>=0; j--){ // 오른쪽부터 돌거임
                if(tempMap[i][j] != 0){ // 오른쪽으로 이동시킬 숫자가 있으면
                    toMove.push_back(tempMap[i][j]); // 벡터에 넣고
                    tempMap[i][j] = 0; // 숫자 자리를 0으로 만든다.
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
                tempMap[i][N-1-index] = merge.front(); // 바뀐 숫자를 맵에 반영한다.
                merge.pop();
                index++;
            }
        }
    }

    return tempMap;
}

void DFS(int count){
    if(count == 5){
        int newMap[20][20] = {0, };
        int (*temp)[20] = newMap;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                newMap[i][j] = map[i][j];
            }
        }

        for(int i=0; i<progress.length(); i++){
            temp = push(progress[i], temp);
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                newMap[i][j] = temp[i][j];
                if(newMap[i][j] > result){
                    result = newMap[i][j];
                }
            }
        }

        return;
    }

    for(int i=1; i<=4; i++){
        if(i == 1){
            progress[count] = 'U';
        }
        else if(i == 2){
            progress[count] = 'D';
        }
        else if(i == 3){
            progress[count] = 'L';
        }
        else if(i == 4){
            progress[count] = 'R';
        }
        DFS(count+1);
    }
}

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    DFS(0);

    cout << result << '\n';

    return 0;
}