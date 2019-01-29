//
// Created by Keith_Lee on 29/01/2019.
//

#include <iostream>
#include <vector>

using namespace std;

int result = 0;
int N, K;
int candidates[26] = {0, };

int words[50][26] = {0, };

int max(int a, int b){
    return a > b ? a : b;
}

void searchTeach(int index, string toTeach, int limit){
    string temp = toTeach;
    if(index < 26){
        temp += (candidates[index] + 'a');
    }
    int tempResult = 0;

    if(toTeach.length() == limit || temp == toTeach){
        for(int i=0; i<words.size(); i++){
            bool invalid = false;
            int alphabets[26] = {0, };
            for(int j=0; j<toTeach.length(); j++){
                alphabets[toTeach[j] - 'a'] = 1;
            }
            for(int j=0; j<26; j++){
                if(alphabets[j] - words[i][j] < 0){
                    invalid = true;
                    break;
                }
            }
//            for(int j=0; j<words[i].length(); j++){
//                if(toTeach.find(words[i][j]) >= toTeach.length()){
//                    invalid = true;
//                    break;
//                }
//            }

            if(!invalid){
                tempResult++;
            }
        }

        result = max(result, tempResult);
        return;
    }

    searchTeach(index+1, temp, limit);
    searchTeach(index+1, toTeach, limit);
}

void toTeach(){
    for(int i=0; i<words.size(); i++){
        int temp[26] = {0, };

        for(int j=0; j<26; j++){
            if(j != 'a' - 'a' && j != 'c' - 'a' && j != 'i' - 'a' && j != 'n' - 'a' && j != 't' - 'a'){
                if(temp[j] != 1){
                    temp[j] = 1;
                }
                if(candidates[j] != 1){
                    candidates[j] = 1;
                }
            }
        }
        for(int j=0; j<26; j++){
            words[i][j] = temp[j];
        }
//        for(int j=0; j<words[i].length(); j++){
//            if(words[i][j] != 'a' && words[i][j] != 'c' && words[i][j] != 'i' && words[i][j] != 'n' && words[i][j] != 't'){ // anta, tica 뗀 문자열이 a, c, i, n, t를 포함하지 않는다면
//                if(temp.find(words[i][j]) >= temp.length()) { // temp 내에 a, c, i, n, t가 아닌 문자가 이미 있지 않다면
//                    temp += words[i][j]; // 문자 추가
//                }
//                if(candidates.find(words[i][j]) >= candidates.length()){ // 최종 정답 후보에 이 문자가 없다면
//                    candidates += words[i][j]; // 문자 추가
//                }
//            }
//        }

//        if(temp.length() == 0){
//            result++;
//        }

//        words[i] = temp; // anta, tica 뗀 문자열에서 a, c, i, n, t 빼고 중복 제거하여 바꿔넣는다.
    }
}

int main(){
    string word;

    cin >> N >> K;

    for(int i=0; i<N; i++){
        cin >> word;

        if(K >= 5){
            string temp = word.substr(4, word.length()-8);
//            int toInsert[26] = {0, };
            for(int j=0; j<temp.length(); j++){
                words[i][temp[j] - 'a']++;
//                toInsert[temp[j] - 'a']++;
            }
        }
    }

    if(K >= 5){
        toTeach();

        searchTeach(0, "", K-5);
    }
    else{
        result = 0;
    }

    cout << result << '\n';

    return 0;
}