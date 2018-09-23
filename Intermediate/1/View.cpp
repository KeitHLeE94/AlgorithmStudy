//
// Created by Keith_Lee on 2018. 9. 23..
//
#include <iostream>

using namespace std;

int main(){
    for(int i=0; i<10; i++){
        int length;
        cin >> length;

        int ground[length];

        for(int j=0; j<length; j++){
            cin >> ground[j];
        }

        int answer = 0;

        for(int j=2; j<length-2; j++){
            for(int k=1; k<=ground[j]; k++){
                if(k > ground[j-1] && k > ground[j-2] && k > ground[j+1] && k > ground[j+2]){
                    answer++;
                }
            }
        }

        cout << '#' << i+1 << ' ' << answer << '\n';
    }

    return 0;
}