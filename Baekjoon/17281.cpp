//
// Created by Keith_Lee on 13/06/2019.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int max_score = -1;
int innings[51][9];

void proceed(vector<int> order){
    int score = 0;
    int inning = 1;
    int out = 3;

    int base[4] = {0, }; // 1루 2루 3루 홈

    int hitter = 0;

    while(true){

        if(out == 0){
            score += base[3];
            inning++;
            base[0] = 0;
            base[1] = 0;
            base[2] = 0;
            base[3] = 0;
            out = 3;

            if(inning > N){
                break;
            }
        }
        else{
            if(innings[inning][order[hitter % 9]] == 0){
                out--;
            }
            else if(innings[inning][order[hitter % 9]] == 1){
                for(int i=2; i>=0; i--){
                    if(base[i] == 1){
                        base[i+1]++;
                        base[i]--;
                    }
                }

                base[0]++;
            }
            else if(innings[inning][order[hitter % 9]] == 2){
                for(int i=2; i>=0; i--){
                    if(base[i] == 1){
                        if(i+2 > 3){
                            base[3]++;
                        }
                        else{
                            base[i+2]++;
                        }

                        base[i]--;
                    }
                }

                base[1]++;
            }
            else if(innings[inning][order[hitter % 9]] == 3){
                for(int i=2; i>=0; i--){
                    if(base[i] == 1){
                        base[3]++;
                        base[i]--;
                    }
                }

                base[2]++;
            }
            else if(innings[inning][order[hitter % 9]] == 4){
                for(int i=2; i>=0; i--){
                    if(base[i] == 1){
                        base[3]++;
                        base[i] = 0;
                    }
                }

                base[3]++;
            }

            hitter++;
        }
    }

    max_score = max_score > score ? max_score : score;
}

int main(){
    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=0; j<9; j++){
            cin >> innings[i][j];
        }
    }

    vector<int> players;

    for(int i=1; i<9; i++){
        players.push_back(i);
    }

    vector<int> temp_order;
    for(int i=0; i<players.size(); i++){
        if(temp_order.size() == 3){
            temp_order.push_back(0);
        }

        temp_order.push_back(players[i]);
    }

    proceed(temp_order);

    while(next_permutation(players.begin(), players.end())){
        vector<int> order;

        for(int i=0; i<players.size(); i++){
            if(order.size() == 3){
                order.push_back(0);
            }
            order.push_back(players[i]);
        }

        proceed(order);
    }

    cout << max_score << '\n';

    return 0;
}