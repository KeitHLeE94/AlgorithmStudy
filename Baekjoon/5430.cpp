//
// Created by Keith_Lee on 20/06/2019.
//

#include <iostream>
#include <deque>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int test=0; test<T; test++){
        string p;
        cin >> p;

        int n;
        cin >> n;

        string input;
        cin >> input;

        bool reverse = false;
        bool isError = false;

        deque<string> processedArray;

        string temp = "";
        for(int i=1; i<input.length()-1; i++){
            if(input[i] != ','){
                temp += input[i];
            }
            else{
                if(n > 0){
                    processedArray.push_back(temp);
                    temp = "";
                }
            }
        }

        if(temp.length() > 0){
            processedArray.push_back(temp);
        }

        for(int i=0; i<p.length(); i++){
            if(p[i] == 'R'){
                reverse = !reverse;
            }
            else if(p[i] == 'D'){
                if(!processedArray.empty()){
                    if(reverse){
                        processedArray.pop_back();
                    }
                    else{
                        processedArray.pop_front();
                    }
                }
                else{
                    isError = true;
                }
            }
        }

        if(isError){
            cout << "error" << '\n';
        }
        else{
            string result = "[";

            while(!processedArray.empty()){
                if(reverse){
                    result += processedArray.back();
                    processedArray.pop_back();
                }
                else{
                    result += processedArray.front();
                    processedArray.pop_front();
                }

                result += ",";
            }

            if(result.length() > 1){
                result.pop_back();
            }

            result += "]";

            cout << result << '\n';
        }
    }

    return 0;
}