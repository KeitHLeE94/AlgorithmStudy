//
// Created by Keith_Lee on 2018. 9. 30..
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    string numbers[10] = {"0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011"};

    int caseNum;
    cin >> caseNum;

    for(int i=0; i<caseNum; i++){
        int N, M;
        cin >> N >> M;

        string exclude;
        for(int j=0; j<M; j++){
            exclude.push_back('0');
        }

        vector<string> cipher;
        string input;
        for(int j=0; j<N; j++){
            cin >> input;
            if(input != exclude){
                cipher.push_back(input);
            }
        }

        int endIndex = cipher[0].length()-1;
        int searchFail = 1;
        for(int j=0; j<cipher[0].length(); j++){
            string search;
            for(int k=endIndex-6; k<=endIndex; k++){
                search.push_back(cipher[0][k]);
            }
            for(int k=0; k<10; k++){
                if(numbers[k] == search){
                    searchFail = 0;
                    break;
                }
            }
            if(searchFail){
                endIndex--;
            }
        }

        int answer = 0;
        string realCipher;
        for(int j=endIndex-55; j<=endIndex; j++){
            realCipher.push_back(cipher[0][j]);
        }

        int result[8];
        for(int j=0; j<8; j++){
            string convert;
            int temp = 0;

            for(int k=0; k<7; k++){
                convert.push_back(realCipher[j*7+k]);
            }
            for(int k=0; k<10; k++){
                if(numbers[k] == convert){
                    temp = k;
                    break;
                }
            }
            result[j] = temp;
        }

        int check = (result[0] + result[2] + result[4] + result[6])*3 + (result[1] + result[3] + result[5] + result[7]);

        if(check % 10 == 0){
            for(int j=0; j<8; j++){
                answer += result[j];
            }
        }

        cout << '#' << i+1 << ' ' << answer << '\n';
    }

    return 0;
}