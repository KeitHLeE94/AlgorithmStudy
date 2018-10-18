//
// Created by Keith_Lee on 16/10/2018.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int players[21][21];
bool used[21];
int result = 9999999;

void DFS(int cnt, int start){
    if(cnt == N/2){
        vector<int> team_start;
        vector<int> team_link;

        for(int i=1; i<=N; i++){
            if(!used[i]){
                team_start.push_back(i);
            }
            else{
                team_link.push_back(i);
            }
        }

        int startSum = 0;
        int linkSum = 0;
        for(int i=0; i<N/2-1; i++){
            for(int j=i+1; j<N/2; j++){
                startSum += (players[team_start[i]][team_start[j]] + players[team_start[j]][team_start[i]]);
                linkSum += (players[team_link[i]][team_link[j]] + players[team_link[j]][team_link[i]]);
            }
        }

        result = min(result, abs(startSum - linkSum));
    }

    for(int i=start+1; i<=N; i++){
        if(!used[i]){
            used[i] = true;
            DFS(cnt+1, i);
            used[i] = false;
        }
    }
}

int main(){
    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> players[i][j];
        }
    }

    DFS(0, 0);

    cout << result << '\n';

    return 0;
}