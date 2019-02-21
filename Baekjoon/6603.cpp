//
// Created by Keith_Lee on 21/02/2019.
//

#include <iostream>
#include <vector>
#include <strings.h>
#include <algorithm>

using namespace std;

int K;
vector<int> numbers;
bool visit[12] = {false, };

void DFS(int index){
    if(index == K){
        int count = 0;
        for(int i=0; i<K; i++){
            if(visit[i]){
                count++;
            }
        }

        if(count == 6){
            for(int i=0; i<K; i++){
                if(visit[i]){
                    cout << numbers[i] << ' ';
                }
            }
            cout << '\n';
        }

        return;
    }

    visit[index] = true;
    DFS(index+1);
    visit[index] = false;
    DFS(index+1);
}

int main(){
    while(true){
        cin >> K;

        if(K == 0){
            break;
        }

        numbers.clear();
        bzero(visit, sizeof(visit));

        for(int i=0; i<K; i++){
            int temp;
            cin >> temp;
            numbers.push_back(temp);
        }

        sort(numbers.begin(), numbers.end());

        DFS(0);
        cout << '\n';
    }

    return 0;
}