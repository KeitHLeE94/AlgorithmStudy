//
// Created by Keith_Lee on 2018. 9. 23..
//
#include <iostream>

using namespace std;

int main(){
    int T, N, temp;

    cin >> T;

    for(int i=0; i<T; i++){
        int frequency[101] = {0, };
        int answer;
        int max = 0;

        cin >> N;

        for(int j=0; j<1000; j++){
            cin >> temp;
            frequency[temp] += 1;
        }

        for(int j=0; j<=100; j++){
            if(max <= frequency[j]){
                max = frequency[j];
                answer = j;
            }
        }

        cout << '#' << N << ' ' << answer << '\n';
    }

    return 0;
}