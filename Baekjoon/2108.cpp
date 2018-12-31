//
// Created by Keith_Lee on 31/12/2018.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

int N;

int halfProcess(double num){
    double high = ceil(num);
    double low = floor(num);

    if(num >= (high + low) / 2){
        return int(high);
    }

    return int(low);
}

int main(){
    cin >> N;

    vector<int> numbers;
    int sum = 0;
    map<int, int> frequencies;

    int inputNum;

    for(int i=0; i<N; i++){
        cin >> inputNum;
        sum += inputNum;
        numbers.push_back(inputNum);
        if(frequencies.find(inputNum) == frequencies.end()){
            frequencies.insert(make_pair(inputNum, 1));
        }
        else{
            frequencies.find(inputNum)->second++;
        }
    }

    int temp = 0;
    int mostFrequent;
    int changeCount = 0;
    for(auto iter = frequencies.begin(); iter != frequencies.end(); iter++){
        if(iter->second > temp){
            temp = iter->second;
            mostFrequent = iter->first;
            changeCount++;
        }
    }
    for(auto iter = frequencies.begin(); iter != frequencies.end(); iter++){
        if(iter->second == temp && iter->first != mostFrequent){
            mostFrequent = iter->first;
            break;
        }
    }

    sort(numbers.begin(), numbers.end());

    int average = halfProcess(double(sum) / double(N));
    int center = numbers[N/2];
    int range = numbers[N-1] - numbers[0];

    cout << average << '\n' << center << '\n' << mostFrequent << '\n' << range << '\n';

    return 0;
}