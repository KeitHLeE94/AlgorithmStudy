//
// Created by Keith_Lee on 01/04/2019.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char board1[8][8] = {
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
};

char board2[8][8] = {
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}
};

char map[50][50];

int main(){
    int N, M;

    cin >> N >> M;

    for(int i=0; i<N; i++){
        string row;
        cin >> row;

        for(int j=0; j<M; j++){
            map[i][j] = row[j];
        }
    }

    char checkMap[8][8];
    vector<int> candidates;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(i + 7 < N && j + 7 < M){
                for(int k=0; k<8; k++){
                    for(int l=0; l<8; l++){
                        checkMap[k][l] = map[k+i][l+j];
                    }
                }

                int result1 = 0, result2 = 0;
                for(int k=0; k<8; k++){
                    for(int l=0; l<8; l++){
                        if(checkMap[k][l] != board1[k][l]){
                            result1++;
                        }
                        if(checkMap[k][l] != board2[k][l]){
                            result2++;
                        }
                    }
                }

                candidates.push_back(result1);
                candidates.push_back(result2);
            }
        }
    }

    sort(candidates.begin(), candidates.end());

    cout << candidates[0] << '\n';

    return 0;
}