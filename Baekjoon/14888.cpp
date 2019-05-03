//
// Created by Keith_Lee on 03/05/2019.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
int numbers[11] = {0, };

int minValue = 1000000000;
int maxValue = -1000000000;

void DFS(int count, int operators[4], vector<int> order){
    if(count == N-1){
        int answer = numbers[0];

        for(int i=1; i<N; i++){
            int toOper = numbers[i];

            if(order[i-1] == 0){
                answer += toOper;
            }
            else if(order[i-1] == 1){
                answer -= toOper;
            }
            else if(order[i-1] == 2){
                answer *= toOper;
            }
            else if(order[i-1] == 3){
                answer /= toOper;
            }
        }

        minValue = minValue > answer ? answer : minValue;
        maxValue = maxValue < answer ? answer : maxValue;

        return;
    }

    for(int i=0; i<4; i++){
        if(operators[i] > 0){
            order.push_back(i);
            operators[i]--;

            DFS(count+1, operators, order);

            operators[i]++;
            order.pop_back();
        }
    }
}

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> numbers[i];
    }

    int operators[4] = {0, };

    for(int i=0; i<4; i++){
        cin >> operators[i];
    }

    vector<int> order;

    DFS(0, operators, order);

    cout << maxValue << '\n';
    cout << minValue << '\n';

    return 0;
}