//
// Created by Keith_Lee on 27/04/2019.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    vector<int> gears[4]; // 톱니바퀴 4개 현재 상태

    for(int i=0; i<4; i++){
        string input;
        cin >> input;

        for(int j=0; j<input.length(); j++){
            gears[i].push_back(input[j] - '0');
        }
    }

    int K;
    cin >> K;

    int gearNum, direction;
    for(int i=0; i<K; i++){
        int dir[4] = {0, }; // 각 톱니바퀴 회전 방향

        cin >> gearNum >> direction;
        gearNum--;

        dir[gearNum] = direction;

        for(int j=gearNum; j>=0; j--){
            if(j-1 >= 0){
                if(gears[j-1][2] != gears[j][6]){
                    if(dir[j] != 0){
                        dir[j-1] = dir[j] * -1;
                    }
                }
            }
        }

        for(int j=gearNum; j<4; j++){
            if(j+1 < 4){
                if(gears[j][2] != gears[j+1][6]){
                    if(dir[j] != 0){
                        dir[j+1] = dir[j] * -1;
                    }
                }
            }
        }

        for(int j=0; j<4; j++){
            if(dir[j] == -1){ // 반시계방향 회전
                queue<int> temp;
                int last = gears[j][0];

                for(int k=1; k<8; k++){
                    temp.push(gears[j][k]);
                }

                gears[j].clear();
                while(!temp.empty()){
                    gears[j].push_back(temp.front());
                    temp.pop();
                }
                gears[j].push_back(last);
            }
            else if(dir[j] == 1){
                queue<int> temp;
                int first = gears[j][7];

                for(int k=0; k<7; k++){
                    temp.push(gears[j][k]);
                }

                gears[j].clear();
                gears[j].push_back(first);
                while(!temp.empty()){
                    gears[j].push_back(temp.front());
                    temp.pop();
                }
            }
        }
    }

    int result = 0;
    int score = 1;
    for(int i=0; i<4; i++){
        if(gears[i][0] == 1){
            result += score;
        }

        score *= 2;
    }

    cout << result << '\n';

    return 0;
}