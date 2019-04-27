//
// Created by Keith_Lee on 27/04/2019.
//

#include <iostream>

using namespace std;

char map[10][10];
int redX, redY, blueX, blueY;
int N, M;
int result = 11;

void DFS(string order){
    cout << order << '\n';

    if(order.length() > 10){
        return;
    }

    for(int i=0; i<order.length(); i++){
        if(order[i] == 'L'){
            int moveCount = 1;

            while(redY - moveCount >= 0 && map[redX][redY - moveCount] == '.'){
                moveCount++;
            }

            map[redX][redY] = '.';
            redY -= moveCount;

            if(map[redX][redY] == 'O'){
                redX = -1;
                redY = -1;
            }
            else{
                map[redX][redY] = 'R';
            }

            moveCount = 1;

            while(blueY - moveCount >= 0 && map[blueX][blueY - moveCount] == '.'){
                moveCount++;
            }

            map[blueX][blueY] = '.';
            blueY -= moveCount;

            if(map[blueX][blueY] == 'O'){
                blueX = -1;
                blueY = -1;
            }
            else{
                map[blueX][blueY] = 'B';
            }
        }
        else if(order[i] == 'R'){
            int moveCount = 1;

            while(redY + moveCount < M && map[redX][redY + moveCount] == '.'){
                moveCount++;
            }

            map[redX][redY] = '.';
            redY += moveCount;

            if(map[redX][redY] == 'O'){
                redX = -1;
                redY = -1;
            }
            else{
                map[redX][redY] = 'R';
            }

            moveCount = 1;

            while(blueY + moveCount < M && map[blueX][blueY + moveCount] == '.'){
                moveCount++;
            }

            map[blueX][blueY] = '.';
            blueY += moveCount;

            if(map[blueX][blueY] == 'O'){
                blueX = -1;
                blueY = -1;
            }
            else{
                map[blueX][blueY] = 'B';
            }
        }
        else if(order[i] == 'U'){
            int moveCount = 1;

            while(redX - moveCount >= 0 && map[redX - moveCount][redY] == '.'){
                moveCount++;
            }

            map[redX][redY] = '.';
            redX -= moveCount;

            if(map[redX][redY] == 'O'){
                redX = -1;
                redY = -1;
            }
            else{
                map[redX][redY] = 'R';
            }

            moveCount = 1;

            while(blueX - moveCount >= 0 && map[blueX - moveCount][blueY] == '.'){
                moveCount++;
            }

            map[blueX][blueY] = '.';
            blueX -= moveCount;

            if(map[blueX][blueY] == 'O'){
                blueX = -1;
                blueY = -1;
            }
            else{
                map[blueX][blueY] = 'B';
            }
        }
        else if(order[i] == 'D'){
            int moveCount = 1;

            while(redX + moveCount < N && map[redX + moveCount][redY] == '.'){
                moveCount++;
            }

            map[redX][redY] = '.';
            redX += moveCount;

            if(map[redX][redY] == 'O'){
                redX = -1;
                redY = -1;
            }
            else{
                map[redX][redY] = 'R';
            }

            moveCount = 1;

            while(blueX + moveCount >= 0 && map[blueX + moveCount][blueY] == '.'){
                moveCount++;
            }

            map[blueX][blueY] = '.';
            blueX += moveCount;

            if(map[blueX][blueY] == 'O'){
                blueX = -1;
                blueY = -1;
            }
            else{
                map[blueX][blueY] = 'B';
            }
        }

        if(redX == -1 && redY == -1){
            if(blueX != -1 && blueY != -1){
                result = result > i+1 ? i+1 : result;
                return;
            }
        }
    }

    string temp = order + 'L';
    DFS(temp);
    temp = order + 'R';
    DFS(temp);
    temp = order + 'U';
    DFS(temp);
    temp = order + 'D';
    DFS(temp);
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        string row;
        cin >> row;

        for(int j=0; j<M; j++){
            map[i][j] = row[j];

            if(map[i][j] == 'R'){
                redX = i;
                redY = j;
            }
            else if(map[i][j] == 'B'){
                blueX = i;
                blueY = j;
            }
        }
    }

    DFS("LLLLLLLLLL");

    cout << redX << ", " << redY << '\n';
    cout << blueX << ", " << blueY << '\n';

    cout << result << '\n';

    return 0;
}