//
// Created by Keith_Lee on 2018. 9. 23..
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> cards(6);

int main(){
    for(int i=0; i<6; i++){
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    do{
        int babygin = 0;

        if(cards[0] == cards[1] == cards[2] || cards[3] == cards[4] == cards[5]){
            babygin++;
        }
        if(cards[1] == cards[0] + 1 && cards[2] == cards[1] + 1){
            babygin++;
        }
        if(cards[4] == cards[3]+1 && cards[5] == cards[4]+1){
            babygin++;
        }

        if(babygin == 2){
            cout << "BabyGin" << '\n';
            break;
        }
    } while(next_permutation(cards.begin(), cards.end()));

    return 0;
}