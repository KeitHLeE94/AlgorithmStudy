//
// Created by Keith_Lee on 21/01/2019.
//

#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[1001][1001] = {0, };
bool visit[1001] = {false, };

int result = 0;

void BFS(int start){
    queue<int> Queue;
    Queue.push(start);

    while(!Queue.empty()){
        int next = Queue.front();
        Queue.pop();

        for(int i=1; i<=N; i++){
            if(!visit[i] && map[next][i] == 1){
                visit[i] = true;
                Queue.push(i);
            }
        }
    }

    result++;
}

int main(){
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int start, end;
        cin >> start >> end;
        map[start][end] = 1;
        map[end][start] = 1;
    }

    for(int i=1; i<=N; i++){
        if(!visit[i]){
            visit[i] = true;
            BFS(i);
        }
    }

    cout << result << '\n';

    return 0;
}