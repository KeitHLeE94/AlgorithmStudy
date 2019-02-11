//
// Created by Keith_Lee on 11/02/2019.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int littles[9] = {0, };
bool visit[9] = {false, };
vector<int> intermediate;

void DFS(int index, int count){
    if(index == 9){
        if(count == 7){
            int sum = 0;

            for(int i=0; i<9; i++){
                if(visit[i]){
                    sum += littles[i];
                }
            }

            if(sum == 100){
                for(int i=0; i<9; i++){
                    if(visit[i]){
                        intermediate.push_back(littles[i]);
                    }
                }
            }
        }

        return;
    }

    visit[index] = true;
    DFS(index+1, count+1);
    visit[index] = false;
    DFS(index+1, count);
}

int main(){
    for(int i=0; i<9; i++){
        cin >> littles[i];
    }

    DFS(0, 0);

    vector<int> result;

    for(int i=0; i<7; i++){
        result.push_back(intermediate[i]);
    }

    sort(result.begin(), result.end());

    for(int i=0; i<result.size(); i++){
        cout << result[i] << '\n';
    }

    return 0;
}