//
// Created by Keith_Lee on 2018. 10. 9..
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int caseNum;
int K;

vector<string> makeTail(string input){
    vector<string> result_temp;

    for(int i=input.length(); i>=0; i--){
        string temp;

        for(int j=input.length()-i; j<input.length(); j++){
            temp.push_back(input[j]);
        }

        result_temp.push_back(temp);
    }

    sort(result_temp.begin(), result_temp.end());

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

        vector<string> tails = makeTail(input);

        string result;
        if(tails[K].length() > 0){
            result = tails[K-1];
        }
        else{
            result = "none";
        }

        cout << '#' << i+1 << ' ' << result << '\n';
    }

    return 0;
}