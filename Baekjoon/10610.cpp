//
// Created by Keith_Lee on 02/04/2019.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string num;
    cin >> num;

    int zeroCount = 0;
    long long digitSum = 0;
    vector<int> numbers;

    for(int i=num.length()-1; i>=0; i--){
        if(num[i] - '0' == 0){
            zeroCount++;
        }
        else{
            numbers.push_back(num[i] - '0');
            digitSum += num[i] - '0';
        }
    }

    sort(numbers.begin(), numbers.end());

    string result;
    if(zeroCount > 0 && digitSum % 3 == 0){
        for(int i=numbers.size()-1; i>=0; i--){
            result.push_back(numbers[i] + '0');
        }
        for(int i=0; i<zeroCount; i++){
            result.push_back('0');
        }

        cout << result << '\n';
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}