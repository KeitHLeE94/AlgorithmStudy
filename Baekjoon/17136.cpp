//
// Created by Keith_Lee on 18/06/2019.
//

#include <iostream>

using namespace std;

int minValue = 30;
bool start = false;

int map[10][10] = {0, };
int limit[5] = {5, 5, 5, 5, 5};

void change(int r, int c, int size){
    for(int i=r; i<r+size; i++){
        for(int j=c; j<c+size; j++){
            map[i][j] = 2;
        }
    }
}

void revoke(int r, int c, int size){
    for(int i=r; i<r+size; i++){
        for(int j=c; j<c+size; j++){
            map[i][j] = 1;
        }
    }
}

bool fit(int r, int c, int size){
    for(int i=r; i<r+size; i++){
        for(int j=c; j<c+size; j++){
            if(map[i][j] == 0 || map[i][j] == 2 || i >= 10 || j >= 10){
                return false;
            }
        }
    }

    return true;
}

void DFS(int r, int c, int count){
    bool finish = true;

    for(int i=r; i<10; i++){
        for(int j=0; j<10; j++){
            if(map[i][j] == 1){
                r = i;
                c = j;
                finish = false;
                break;
            }
        }

        if(!finish){
            break;
        }
    }

    if(finish){
        minValue = minValue < count ? minValue : count;

        return;
    }

    for(int size=1; size<=5; size++){
        if(limit[size-1] == 0){
            continue;
        }

        if(!fit(r, c, size)){
            return;
        }

        limit[size-1]--;
        change(r, c, size);
        DFS(r, c, count+1);
        revoke(r, c, size);
        limit[size-1]++;
    }
}

int main(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> map[i][j];

            if(map[i][j] == 1){
                start = true;
            }
        }
    }

    DFS(0, 0, 0);

    if(start && minValue == 30){
        cout << -1 << '\n';
    }
    else{
        cout << minValue << '\n';
    }

    return 0;
}