//
// Created by Keith_Lee on 16/10/2018.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int roster[20][20];
bool visit[20];
int result = 9999999;

void DFS(int start, int cnt){
    if(cnt == N/2){
        vector<int> team_start;
        vector<int> team_link;

        for(int i=0; i<N; i++){
            if(visit[i]){
                team_start.push_back(i);
            }
            else{
                team_link.push_back(i);
            }
        }

        int score_start = 0;
        int score_link = 0;

        for(int i=0; i<team_start.size(); i++){
            for(int j=i+1; j<team_start.size(); j++){
                int startX = team_start[i];
                int startY = team_start[j];
                int linkX = team_link[i];
                int linkY = team_link[j];

                score_start += (roster[startX][startY] + roster[startY][startX]);
                score_link += (roster[linkX][linkY] + roster[linkY][linkX]);
            }
        }

        result = min(result, abs(score_start - score_link));

        return;
    }

    for(int i=start+1; i<N; i++){
        if(!visit[i]){
            visit[i] = true;
            DFS(i, cnt+1);
            visit[i] = false;
        }
    }
}

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> roster[i][j];
        }
    }

    DFS(0, 0);

    cout << result << '\n';

    return 0;
}