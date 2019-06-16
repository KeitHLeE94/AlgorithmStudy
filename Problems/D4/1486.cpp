//
// Created by Keith_Lee on 16/06/2019.
//

#include <iostream>
#include <vector>

using namespace std;

int N, B;
int result;

void DFS(int count, bool visit[20], int heights[20]){
    if(count == N){
        int sum = 0;

        for(int i=0; i<N; i++){
            if(visit[i]){
                sum += heights[i];
            }
        }

        if(sum >= B){
            result = result < sum ? result : sum;
        }

        return;
    }

    visit[count] = true;
    DFS(count+1, visit, heights);
    visit[count] = false;
    DFS(count+1, visit, heights);
}

int main(){
    int T;

    cin >> T;

    for(int test=1; test<=T; test++){
        cin >> N >> B;
        result = 9999999;

        int heights[20];

        for(int i=0; i<N; i++){
            cin >> heights[i];
        }

        bool visit[20] = {false, };
        DFS(0, visit, heights);

        cout << "#" << test << ' ' << abs(result - B) << '\n';
    }
}