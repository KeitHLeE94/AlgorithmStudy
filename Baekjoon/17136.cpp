//
// Created by Keith_Lee on 18/06/2019.
//

#include <iostream>

using namespace std;

int minValue = 999;

int map[10][10] = {0, };

void update(int r, int c, int size){
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
            if(map[i][j] == 0 || map[i][j] == 2){
                return false;
            }
        }
    }

    return true;
}

void DFS(int r, int c, int used[5]){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    for(int i=0; i<5; i++){
        cout << used[i] << ' ';
    }
    cout << '\n';
    cout << "========================================" << '\n';

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
            if(used[i] > 5){
                result = -1;
                break;
            }
            else{
                result += used[i];
            }
        }

        if(result >= 0){
            minValue = minValue < result ? minValue : result;
        }

        return;
    }

    for(int size=1; size<=5; size++){
        if(fit(r, c, size)){
            used[size-1]++;
            update(r, c, size);
            DFS(r, c, used);
            used[size-1]--;
            revoke(r, c, size);
        }
    }
}

int main(){
    int map[10][10] = {0, };

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> map[i][j];
        }
    }

    int used[5] = {0, };

    DFS(0, 0, used);

    if(minValue != 999){
        cout << minValue << '\n';
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}