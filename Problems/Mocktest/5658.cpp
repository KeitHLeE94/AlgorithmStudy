//
// Created by Keith_Lee on 25/04/2019.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <iterator>

using namespace std;

int hexes[] = {10, 11, 12, 13, 14, 15};

int main(){
    int T;
    cin >> T;

    for(int test=1; test<=T; test++){
        int N, K;
        cin >> N >> K;

        string input;
        cin >> input;

        set<string> Set;
        queue<char> Queue;
        vector<char> chars;

        for(int i=0; i<input.length(); i++){
            Queue.push(input[i]);
        }

        for(int r=0; r<N/4; r++){
            chars.clear();

            while(!Queue.empty()){
                chars.push_back(Queue.front());
                Queue.pop();
            }

            string divide = "";
            for(int i=0; i<chars.size(); i++){
                if(divide.length() != N/4){
                    divide += chars[i];
                }
                else{
                    Set.insert(divide);
                    divide = "";
                    divide += chars[i];
                }
            }
            Set.insert(divide);

            for(int i=1; i<chars.size(); i++){
                Queue.push(chars[i]);
            }
            Queue.push(chars[0]);
        }

        vector<long long> results;

        set<string>::iterator iter = Set.begin();
        for(iter = Set.begin(); iter != Set.end(); iter++){
            string temp = *iter;
            long long result = 0;
            long long hex = 1;

            for(int i=temp.length()-1; i>=0; i--){
                if(temp[i] >= 'A' && temp[i] <= 'F'){
                    result += hexes[temp[i] - 'A'] * hex;
                }
                else{
                    result += (temp[i] - '0') * hex;
                }

                hex *= 16;
            }

            results.push_back(result);
        }

        cout << '#' << test << ' ' << results[results.size() - K] << '\n';
    }

    return 0;
}