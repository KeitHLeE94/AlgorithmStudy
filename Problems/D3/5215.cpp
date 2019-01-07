//
// Created by Keith_Lee on 07/01/2019.
//

#include <iostream>
#include <vector>

using namespace std;

int T;
int N, L;
int maximum = 0;

vector<pair<int, int>> base;

void DFS(int start, int calory, int score){
    if(start == N){
        maximum = maximum > score ? maximum : score;
        return;
    }
    if(calory + base[start].second <= L){
        DFS(start+1, calory+base[start].second, score+base[start].first); // start번째 재료 추가
    }
    DFS(start+1, calory, score); // start번째 재료 거름
}

int main(){
    cin >> T;

    for(int test=1; test<=T; test++){
        cin >> N >> L;

        for(int i=0; i<N; i++){
            int calory;
            int score;

            cin >> score >> calory;

            base.push_back(make_pair(score, calory));
        }

        DFS(0, 0, 0);

        cout << '#' << test << ' ' << maximum << '\n';
        while(!base.empty()){
            base.pop_back();
        }
        maximum = 0;
    }
}