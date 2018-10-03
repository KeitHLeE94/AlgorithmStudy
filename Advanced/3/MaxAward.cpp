//
// Created by Keith_Lee on 2018. 10. 2..
//
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int changeNum;
int result, caseNum;
string cards;
char temp[256];

void get_award(int count, int current){
    cout << cards << '\n';
    cout << count << ", " << current << '\n';
    if(count == changeNum){
        result = max(result, stoi(cards));
        return;
    }
    for(int i=current; i<cards.size(); i++){
        for(int j=i; j<cards.size(); j++){
            if(i == j){
                continue;
            }
            if(cards[i] <= cards[j]){
                swap(cards[i], cards[j]);
                get_award(count+1, i);
                swap(cards[i], cards[j]);
            }
        }
    }
}

int main(){
    cin >> caseNum;

    for(int i=0; i<caseNum; i++){
        scanf("%s", temp);
        scanf("%d", &changeNum);

        result = 0;
        cards = temp;

        get_award(0, 0);

        cout << '#' << i+1 << ' ' << result << '\n';
    }

    return 0;
}