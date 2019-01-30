//
// Created by Keith_Lee on 30/01/2019.
//

#include <iostream>
#include <vector>

using namespace std;

int result = 0;
int N, K;

string words[50];
bool visit[26];

int max(int a, int b){
    return a > b ? a : b;
}

void searchTeach(int index, int count){
    if(count == K-5){
        int tempResult = 0;

        for(int i=0; i<N; i++){
            bool invalid = false;

            for(int j=0; j<words[i].length(); j++){
                if(!visit[words[i][j] - 'a']){
                    invalid = true;
                    break;
                }

            }

            if(!invalid){
                tempResult++;
            }
        }

        result = max(result, tempResult);
        return;
    }

    for(int i=index; i<26; i++){
        if(!visit[i]){
            visit[i] = true;
            searchTeach(i, count+1);
            visit[i] = false;
        }
    }

}

int main(){
    cin >> N >> K;

    for(int i=0; i<N; i++){
        cin >> words[i];

        words[i] = words[i].substr(4, words[i].length()-8);
    }

    if(K < 5){
        result = 0;
    }
    else if(K == 26){
        result = N;
    }
    else{
        visit['a' - 'a'] = true;
        visit['n' - 'a'] = true;
        visit['t' - 'a'] = true;
        visit['c' - 'a'] = true;
        visit['i' - 'a'] = true;

        searchTeach(0, 0);
    }

    cout << result << '\n';

    return 0;
}