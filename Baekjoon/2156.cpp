//
// Created by Keith_Lee on 11/01/2019.
//

#include <iostream>
#include <vector>

using namespace std;

int N;

int maximum(vector<int> numbers){
    int result = 0;

    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] > result){
            result = numbers[i];
        }
    }

    numbers.clear();
    return result;
}

int main(){
    cin >> N;

    int DP[10001];
    int score[10001];

    for(int i=1; i<=N; i++){
        cin >> score[i];
    }

    vector<int> to_compare;

    DP[1] = score[1];
    DP[2] = max(score[1] + score[2], score[2]);

    for(int i=3; i<=N; i++){
        to_compare.push_back(DP[i-1]);
        to_compare.push_back(DP[i-2] + score[i]);
        to_compare.push_back(DP[i-3] + score[i] + score[i-1]);
        DP[i] = maximum(to_compare);
    }

    cout << DP[N] << '\n';

    return 0;
}