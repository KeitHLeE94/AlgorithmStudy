//
// Created by Keith_Lee on 2018. 10. 1..
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int caseNum=0; caseNum < T; caseNum++){
        int N, M; //N: 세로, M: 가로
        cin >> N >> M;

        string exclude;
        for(int i=0; i<M; i++){
            exclude.push_back('0');
        }

        string original_cipher;
        string cipher_line;
        for(int i=0; i<N; i++){
            cin >> cipher_line;

            if(cipher_line != exclude){
                original_cipher = cipher_line;
            }
        }


    }
}