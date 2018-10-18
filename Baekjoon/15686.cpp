//
// Created by Keith_Lee on 17/10/2018.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int answer = 9999999;
int map[51][51];
bool used[14];
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

void distanceSum(){
    int result = 0;

    for(int i=0; i<houses.size(); i++){
        int distance = 9999999;
        for(int j=0; j<chickens.size(); j++){
            if(used[j]){
                int houseX = houses[i].first;
                int houseY = houses[i].second;
                int chickenX = chickens[j].first;
                int chickenY = chickens[j].second;

                int temp = abs(houseX - chickenX) + abs(houseY - chickenY);
                distance = min(temp, distance);
            }
        }
        result += distance;
    }

    answer = min(answer, result);
}

void DFS(int cnt, int currentCnt){
    if(cnt > chickens.size()){
        return;
    }
    if(currentCnt == M){
        distanceSum();
        return;
    }

    used[cnt] = true;
    DFS(cnt+1, currentCnt+1);
    used[cnt] = false;
    DFS(cnt+1, currentCnt);
}

int main(){
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                chickens.push_back(make_pair(i, j));
                map[i][j] = 0;
            }
            else if(map[i][j] == 1){
                houses.push_back(make_pair(i, j));
            }
        }
    }

    DFS(0, 0);

    cout << answer << '\n';

    return 0;
}