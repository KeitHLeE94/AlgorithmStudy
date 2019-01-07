//
// Created by Keith_Lee on 07/01/2019.
//

#include <iostream>
#include <string.h>

using namespace std;

int T;

int main(){
    cin >> T;

    string input = "";

    for(int test=1; test<=T; test++){
        int count = 0;
        string modified = "";

        cin >> input;

        for(int i=0; i<input.length(); i++){
            modified.push_back('0');
        }

        for(int i=0; i<input.length(); i++){
            if(modified[i] != input[i]){
                if(input[i] == '0'){
                    for(int j=i; j<modified.length(); j++){
                        modified[j] = '0';
                    }
                }
                else if(input[i] == '1'){
                    for(int j=i; j<modified.length(); j++){
                        modified[j] = '1';
                    }
                }
                count++;
            }
        }

        cout << '#' << test << ' ' << count << '\n';
    }

    return 0;
}
