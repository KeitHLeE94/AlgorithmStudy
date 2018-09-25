//
// Created by Keith_Lee on 2018. 9. 24..
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    for(int i=0; i<10; i++){
        int caseNum;
        cin >> caseNum;
        vector<int> answer;

        int array[100][100];

        for(int j=0; j<100; j++){
            for(int k=0; k<100; k++){
                cin >> array[j][k];
            }
        }

        int max_horizontal = 0;
        for(int j=0; j<100; j++){
            int sum_horizontal = 0;
            for(int k=0; k<100; k++){
                sum_horizontal += array[j][k];
            }
            if(max_horizontal < sum_horizontal){
                max_horizontal = sum_horizontal;
            }
        }

        int max_vertical = 0;
        for(int j=0; j<100; j++){
            int sum_vertical = 0;
            for(int k=0; k<100; k++){
                sum_vertical += array[k][j];
            }
            if(max_vertical < sum_vertical){
                max_vertical = sum_vertical;
            }
        }

        int sum_cross1 = 0;
        for(int j=0; j<100; j++){
            sum_cross1 += array[j][j];
        }

        int sum_cross2 = 0;
        for(int j=99; j>=0; j--){
            sum_cross2 += array[j][99-j];
        }

        answer.push_back(max_horizontal);
        answer.push_back(max_vertical);
        answer.push_back(sum_cross1);
        answer.push_back(sum_cross2);

        sort(answer.begin(), answer.end());

        cout << '#' << caseNum << ' ' << answer.back() << '\n';
    }

    return 0;
}