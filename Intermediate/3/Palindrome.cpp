//
// Created by Keith_Lee on 2018. 9. 26..
//
#include <iostream>
#include <string>

using namespace std;

int main(){
    for(int i=0; i<10; i++){
        int length;
        cin >> length;

        char map[8][8];

        for(int j=0; j<8; j++){
            for(int k=0; k<8; k++){
                cin >> map[j][k];
            }
        }

        int count = 0;

        for(int j=0; j<8; j++){
            for(int k=0; k<=8-length; k++){
                string check;
                string reverse;

                for(int l=0; l<length; l++){
                    if(map[j][k+l] && map[j][k+length-1]){
                        check.push_back(map[j][k+l]);
                        reverse.push_back(map[j][k+length-1-l]);
                    }
                }

                if(check.compare(reverse) == 0){
                    count++;
                }
            }
        }

        for(int j=0; j<=8-length; j++){
            for(int k=0; k<8; k++){
                string check;
                string reverse;

                for(int l=0; l<length; l++){
                    if(map[j+l][k] && map[j+length-1][k]){
                        check.push_back(map[j+l][k]);
                        reverse.push_back(map[j+length-1-l][k]);
                    }
                }

                if(check.compare(reverse) == 0){
                    count++;
                }
            }
        }

        cout << '#' << i+1 << ' ' << count << '\n';
    }

    return 0;
}