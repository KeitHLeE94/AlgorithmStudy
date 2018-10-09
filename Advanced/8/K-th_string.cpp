//
// Created by Keith_Lee on 2018. 10. 9..
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int caseNum;
int K;

vector<string> makeSubstring(string input){
    vector<string> result_temp;

    for(int i=0; i<input.length(); i++){
        for(int j=0; j<input.length()-i; j++){
            string temp;
            for(int k=0; k<=i; k++){
                temp.push_back(input[j+k]);
            }
            result_temp.push_back(temp);
        }
    }

    sort(result_temp.begin(), result_temp.end());
    result_temp.erase(unique(result_temp.begin(), result_temp.end()), result_temp.end()); //벡터 중복 제거시 활용.

    vector<string> result;

    for(int i=0; i<result_temp.size(); i++){
        if(result_temp[i].length() > 0){
            result.push_back(result_temp[i]);
        }
    }

    return result;
}

int main(){
    cin >> caseNum;

    for(int i=0; i<caseNum; i++){
        cin >> K;

        string input;
        cin >> input;

        vector<string> subStrings;
        subStrings = makeSubstring(input);

        string result;
        if(subStrings[K-1].length() > 0){
            result = subStrings[K-1];
        }
        else{
            result = "none";
        }

        cout << '#' << i+1 << ' ' << result << '\n';
    }

    return 0;
}