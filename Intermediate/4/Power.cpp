//
// Created by Keith_Lee on 2018. 9. 27..
//
#include <iostream>
#include <stack>

using namespace std;

int main(){
    for(int i=0; i<10; i++){
        int caseNum;
        cin >> caseNum;

        int N, M;
        cin >> N >> M;

        stack<int> Stack;

        for(int j=0; j<M; j++){
            Stack.push(N);
        }

        int answer = 1;

        while(!Stack.empty()){
            answer *= Stack.top();
            Stack.pop();
        }

        cout << '#' << caseNum << ' ' << answer << '\n';
    }

    return 0;
}