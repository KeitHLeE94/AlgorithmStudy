//
// Created by Keith_Lee on 2018. 10. 2..
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

bool numbers[1000000] = {false, };

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int combination(int length){
    return length * (length-1) / 2;
}

vector<int> divide_num(int num){
    vector<int> result;
    int divide = 100000;

    while(num > 0){
        int temp = num / divide;
        if(temp != 0){
            num -= (divide * temp);
            result.push_back(temp);
        }
        else{
            divide /= 10;
        }
    }

    return result;
}

int make_num(vector<int> number_place){
    int result = 0;
    int multiply = 1;
    for(int i=0; i<number_place.size(); i++){
        result += multiply * number_place[number_place.size()-1-i];
        multiply *= 10;
    }

    return result;
}

queue<int> get_award(queue<int> candidates, int changeNum, int size, int changeIter){
    for(int i=0; i<size; i++){
        int number = candidates.front();
        candidates.pop();
        vector<int> number_place = divide_num(number);

        for(int j=0; j<number_place.size()-1; j++){
            for(int k=j+1; k<number_place.size(); k++){
                swap(number_place[j], number_place[k]);
                if(!numbers[make_num(number_place)]){
                    candidates.push(make_num(number_place));
                    numbers[make_num(number_place)] = true;
                }
                swap(number_place[j], number_place[k]);
            }
        }
    }
//    for(int i=0; i<changeNum; i++){
//        int number = candidates.front();
//        candidates.pop();
//
//        vector<int> number_place = divide_num(number);
//
//        int changeIter = combination(number_place.size());
//
//        for(int j=0; j<changeIter; j++){
//            for(int k=0; k<number_place.size()-1; k++){
//                for(int l=1; l<number_place.size(); l++){
//                    swap(number_place[k], number_place[l]);
//                    candidates.push(make_num(number_place));
//                    swap(number_place[l], number_place[k]);
//                }
//            }
//        }
//    }

    if(changeNum > 1){
        return get_award(candidates, changeNum-1, candidates.size(), changeIter);
    }
    else{
        return candidates;
    }
}

int main(){
    int caseNum;
    cin >> caseNum;

    for(int i=0; i<caseNum; i++){
        for(int j=0; j<100000; j++){
            numbers[j] = false;
        }
        queue<int> candidates;

        int number;
        cin >> number;
        candidates.push(number);

        int changeNum;
        cin >> changeNum;

        int temp = number;
        int length = 1;
        while(temp >= 10){
            temp /= 10;
            length++;
        }

        length = combination(length);

        cout << '#' << i+1 << ' ';
        candidates = get_award(candidates, changeNum, candidates.size(), length);

        vector<int> result;

        while(!candidates.empty()){
            result.push_back(candidates.front());
            candidates.pop();
        }

        sort(result.begin(), result.end());

        cout << result.back() << '\n';
    }
}