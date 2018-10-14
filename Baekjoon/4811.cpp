//
// Created by Keith_Lee on 14/10/2018.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(){
    while(true){
        vector<char> str;

        cin >> N;
        if(N == 0){
            break;
        }

        int result = 0;

        for(int i=0; i<N; i++){
            str.push_back('H');
        }
        for(int i=0; i<N; i++){
            str.push_back('W');
        }

        do{
            int sum = 0;
            int flag = 0;

            for(int i=0; i<str.size(); i++){
                if(str[i] == 'W'){
                    sum++;
                }
                else if(str[i] == 'H'){
                    sum--;
                }

                if(sum < 0){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                result++;
            }
        } while(next_permutation(str.begin(), str.end()));

        cout << result << '\n';
    }

    return 0;
}