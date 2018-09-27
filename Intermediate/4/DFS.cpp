//
// Created by Keith_Lee on 2018. 9. 27..
//
#include <iostream>
#include <stack>

using namespace std;

int map[100][100];
bool visit[100] = {false, };

void DFS(int current){
    visit[current] = true;

    for(int i=0; i<100; i++){
        if(map[current][i] && !visit[i]){
            DFS(i);
        }
    }
}

int main(){
    for(int i=0; i<10; i++) {
        int caseNum;
        int routeNum;
        cin >> caseNum >> routeNum;

        int start;
        int end;

        for (int j = 0; j < routeNum; j++) {
            cin >> start >> end;
            map[start][end] = 1;
        }

        DFS(0);

        int answer;
        if(visit[99]){
            answer = 1;
        }
        else{
            answer = 0;
        }

        cout << '#' << caseNum << ' ' << answer << '\n';

        for(int j=0; j<100; j++){
            for(int k=0; k<100; k++){
                map[j][k] = 0;
            }
        }
        for(int j=0; j<100; j++){
            visit[j] = false;
        }
    }
    return 0;
}