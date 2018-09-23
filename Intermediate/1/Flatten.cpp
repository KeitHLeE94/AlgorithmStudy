//
// Created by Keith_Lee on 2018. 9. 23..
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    for(int i=0; i<10; i++){
        vector<int> boxes;

        int dump_num;
        int height;

        cin >> dump_num;

        for(int j=0; j<100; j++){
            cin >> height;
            boxes.push_back(height);
        }

        for(int j=0; j<dump_num; j++){
            sort(boxes.begin(), boxes.end());
            boxes.front() += 1;
            boxes.back() -= 1;
        }

        sort(boxes.begin(), boxes.end());

        int answer = boxes.back() - boxes.front();

        cout << '#' << i+1 << ' ' << answer << '\n';
    }

    return 0;
}