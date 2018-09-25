//
// Created by Keith_Lee on 2018. 9. 25..
//
#include <iostream>

using namespace std;

int main(){
    int map[100][100];
    bool visit[100][100];

    for(int i=0; i<10; i++){
        int caseNum;
        cin >> caseNum;

        for(int j=0; j<100; j++){
            for(int k=0; k<100; k++){
                cin >> map[j][k];
            }
        }

        for(int j=0; j<100; j++){
            int x, y;

            if(map[0][j]){
                for(int j=0; j<100; j++){
                    for(int k=0; k<100; k++){
                        visit[j][k] = false;
                    }
                }
                x = 0;
                y = j;

                visit[x][y] = true;

                while(x != 99){
                    if(map[x][y+1] && !visit[x][y+1] && y<99){
                        y++;
                    }
                    else if(map[x][y-1] && !visit[x][y-1] && y>=1){
                        y--;
                    }
                    else if(map[x+1][y] && !visit[x+1][y] && x<99){
                        x++;
                    }
                    visit[x][y] = true;
                }

                if(map[x][y] == 2){
                    cout << '#' << caseNum << ' ' << j << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}