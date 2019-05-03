//
// Created by Keith_Lee on 02/05/2019.
//

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <strings.h>

using namespace std;

struct Block{
    int x, y, num;
};

int T, N, W, H;
int result = 99999;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void DFS(int count, int map[15][12]){
    if(count == N){ // N개 다 뽑았다
        int sum = 0;

        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(map[i][j] != 0){
                    sum++;
                }
            }
        }

        result = result > sum ? sum : result;

        return;
    }

    int tempMap[15][12] = {0, };
    memcpy(tempMap, map, sizeof(int) * 15 * 12);

    vector<Block> tops; // 맨 윗 블럭 저장할 벡터
    for(int i=0; i<W; i++){
        for(int j=0; j<H; j++){
            if(tempMap[j][i] > 0){
                tops.push_back({j, i, tempMap[j][i]});
                break;
            }
        }
    }

    for(int i=0; i<tops.size(); i++){ // 맨 윗 블럭들중 하나 선택
        if(tempMap[tops[i].x][tops[i].y] > 0){
            queue<Block> toBreak; // 깰 블럭들

            int beforeMap[15][12] = {0, }; // 복원할 map
            memcpy(beforeMap, tempMap, sizeof(int) * 15 * 12);
            toBreak.push(tops[i]);

            while(!toBreak.empty()){ // 연쇄로 깨질 블럭 다 깬다
                Block current = toBreak.front();
                toBreak.pop();

                for(int j=1; j<current.num; j++){
                    for(int k=0; k<4; k++) {
                        int breakX = current.x + dx[k] * j;
                        int breakY = current.y + dy[k] * j;
                        if(breakX >= 0 && breakX < H && breakY >= 0 && breakY < W){
                            int breakNum = tempMap[breakX][breakY];

                            if (breakNum > 0) {
                                toBreak.push({breakX, breakY, breakNum}); // 연쇄로 깨질 블럭 넣음
                            }
                        }
                    }
                }

                tempMap[current.x][current.y] = 0; // 현재꺼 깬다
            }

            // 다깼으면 빈공간 안남기게 떨군다
            for(int j=0; j<W; j++){ // 가로
                queue<int> column;
                for(int k=H-1; k>=0; k--){ // 세로
                    if(tempMap[k][j] > 0){
                        column.push(tempMap[k][j]);
                    }

                    tempMap[k][j] = 0;
                }

                int index = H-1;
                while(!column.empty()){
                    tempMap[index--][j] = column.front();
                    column.pop();
                }
            }

            DFS(count+1, tempMap);

            memcpy(tempMap, beforeMap, sizeof(int) * 15 * 12);
        }
    }
}

int main(){
    cin >> T;

    for(int test=1; test<=T; test++){
        result = 99999;
        cin >> N >> W >> H;

        int map[15][12] = {0, };

        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cin >> map[i][j];
            }
        }

        DFS(0, map);

        if(result == 99999){
            result = 0;
        }

        cout << "#" << test << ' ' << result << '\n';
    }

    return 0;
}