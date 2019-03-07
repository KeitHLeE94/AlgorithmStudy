//
// Created by Keith_Lee on 2019-03-04.
//

#include <iostream>

using namespace std;

int map[10][10];
bool rowCheck[10][10];
bool colCheck[10][10];
bool partCheck[10][10];

int findPart(int i, int j){ // 몇번째 작은 사각형인지 찾아준다.
    return (i/3) * 3 + (j/3);
}

void DFS(int count){
    if(count == 81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }

        exit(0);
    }

    int x = count / 9;
    int y = count % 9;

    if(map[x][y] !=  0){
        DFS(count+1);
    }
    else{
        for(int i=1; i<=9; i++){
            if(!rowCheck[x][i] && !colCheck[y][i] && !partCheck[findPart(x, y)][i]){
                rowCheck[x][i] = true;
                colCheck[y][i] = true;
                partCheck[findPart(x, y)][i] = true;
                map[x][y] = i;

                DFS(count+1);

                map[x][y] = 0;
                rowCheck[x][i] = false;
                colCheck[y][i] = false;
                partCheck[findPart(x, y)][i] = false;
            }
        }
    }
}

int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> map[i][j];

            if(map[i][j] != 0){
                rowCheck[i][map[i][j]] = true;
                colCheck[j][map[i][j]] = true;
                partCheck[findPart(i, j)][map[i][j]] = true;
            }
        }
    }

    DFS(0);

    return 0;
}