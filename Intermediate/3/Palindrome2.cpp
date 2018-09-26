//
// Created by Keith_Lee on 2018. 9. 26..
//
#include <iostream>
#include <string>

using namespace std;

int main(){
    for(int i=0; i<10; i++){
        int caseNum;
        cin >> caseNum;

        char map[100][100];

        for(int j=0; j<100; j++){
            for(int k=0; k<100; k++){
                cin >> map[j][k];
            }
        }

        int length_horizontal = 1;

        for(int j=0; j<100; j++){
            for(int k=0; k<100; k++){
                string check;
                string reverse;

                for(int l=0; l<length_horizontal; l++){
                    if(k+l < 100 && k+length_horizontal-1 < 100){
                        check.push_back(map[j][k+l]);
                        reverse.push_back(map[j][k+length_horizontal-1-l]);
                    }
                }

                if(check == reverse && check.length() > 0 && reverse.length() > 0){
                    length_horizontal++;
                    j = k = 0;
                }
            }
        }

        int length_vertical = 1;

        for(int j=0; j<100; j++){
            for(int k=0; k<100; k++){
                string check;
                string reverse;

                for(int l=0; l<length_vertical; l++){
                    if(j+l < 100 && j+length_vertical-1 < 100){
                        check.push_back(map[j+l][k]);
                        reverse.push_back(map[j+length_vertical-1-l][k]);
                    }
                }

                if(check == reverse && check.length() > 0 && reverse.length() > 0){
                    length_vertical++;
                    j = k = 0;
                }
            }
        }

        int answer;

        if(length_horizontal > length_vertical){
            answer = length_horizontal - 1;
        }
        else{
            answer = length_vertical - 1;
        }

        cout << '#' << caseNum << ' ' << answer << '\n';
    }

    return 0;
}