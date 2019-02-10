//
// Created by Keith_Lee on 10/02/2019.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

int N;
int map[14];
int result = 0;

void DFS(int count){
    if(count == N){
        result++;
        return;
    }

    for(int i=0; i<N; i++){
        bool available = true;

        for(int j=0; j<count; j++){
            if(map[j] == i || abs(count - j) == abs(i - map[j])){
                available = false;
                break;
            }
        }

        if(available){
            map[count] = i;
            DFS(count+1);
        }
    }
}

int main(){
    cin >> N;

    DFS(0);

    cout << result << '\n';

    return 0;
}