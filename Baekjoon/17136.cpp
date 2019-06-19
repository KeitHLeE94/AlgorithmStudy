//
// Created by Keith_Lee on 18/06/2019.
//

#include <iostream>

using namespace std;

int minValue = 999;

int map[10][10] = {0, };

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

void DFS(int r, int c, int limit[5]){
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
        int result = 0;
        for(int i=0; i<5; i++){
            result += (5 - limit[i]);

            if(limit[i] < 0){
                result = -1;
                break;
            }
        }

        if(result >= 0){
            minValue = minValue < result ? minValue : result;
        }

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
        DFS(r, c, limit);
        revoke(r, c, size);
        limit[size-1]++;
    }
}

int main(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> map[i][j];
        }
    }

    int limit[5] = {5, 5, 5, 5, 5};

    DFS(0, 0, limit);

    if(minValue == 999){
        cout << -1 << '\n';
    }
    else{
        cout << minValue << '\n';
    }

    return 0;
}