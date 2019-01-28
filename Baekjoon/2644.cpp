//
// Created by Keith_Lee on 28/01/2019.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[101][101] = {0, };
bool visit[101][101] = {false, };

int n;

int BFS(int start, int end){
    int result = 0;

    queue<int> Queue;
    Queue.push(start);

    while(!Queue.empty()){
        vector<int> available;

        while(!Queue.empty()) {
            available.push_back(Queue.front());
            Queue.pop();
        }

        for(int i=0; i<available.size(); i++) {
            int current = available[i];

            for (int j = 1; j <= n; j++) {
                if (map[current][j] == 1 && !visit[current][j]) {
                    visit[current][j] = true;
                    visit[j][current] = true;
                    Queue.push(j);
                }
            }
        }

        result++;

        for(int i=1; i<=n; i++){
            if(visit[end][i] && visit[i][end]){
                return result;
            }
        }

    }
}

int main(){
    cin >> n;

    int start, end;
    cin >> start >> end;

    int m;
    cin >> m;

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;

        map[x][y] = 1;
        map[y][x] = 1;
    }

    int result = BFS(start, end);

    bool find = false;
    for(int i=1; i<=n; i++){
        if(visit[end][i] && visit[i][end]){
            find = true;
        }
    }

    if(!find){
        result = -1;
    }

    cout << result << '\n';

    return 0;
}