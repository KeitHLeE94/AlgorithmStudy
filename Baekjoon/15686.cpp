//
// Created by Keith_Lee on 17/10/2018.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int map[50][50];
bool remain[13];
int result = 9999999;

vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

void DFS(int start, int cnt){
//    cout << start << ' ' << cnt << '\n';
//    for(int i=0; i<13; i++){
//        if(remain[i]){
//            cout << "Include: " << i << ' ';
//        }
//    }
//    cout << '\n';
    if(start > chickens.size()){
        return;
    }
    if(cnt == M){
        int temp = 0;
        for(int i=0; i<houses.size(); i++){
            int distance = 9999999;
            for(int j=0; j<chickens.size(); j++){
                if(remain[j]){
                    distance = min(distance, abs(houses[i].first - chickens[j].first) + abs(houses[i].second - chickens[j].second));
                }
            }
            temp += distance;
        }
        result = min(result, temp);

        return;
    }

//    for(int i=start; i<chickens.size(); i++){
//        if(remain[i]){
//            continue;
//        }
//        remain[i] = true;
//        DFS(start+1, cnt+1);
//        remain[i] = false;
//    }
    remain[start] = true;
    DFS(start+1, cnt+1);
    //chickens[start+1]을 포함하겠다
    remain[start] = false;
    DFS(start+1, cnt);
    //chickens[start+1]을 포함하지 않고 다른 경우를 탐색하겠다
}

int main(){
    memset(map, -1, sizeof(map));
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                houses.push_back(make_pair(i, j));
            }
            else if(map[i][j] == 2){
                chickens.push_back(make_pair(i, j));
            }
        }
    }

    DFS(0, 0);

    cout << result << '\n';

    return 0;
}