//
// Created by Keith_Lee on 2018. 9. 23..
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool binarySearch(vector<int> search_from, int to_search, int low, int high){
    int middle = (low + high) / 2;

    if(search_from[middle] == to_search){
        return true;
    }
    else if(search_from[middle] > to_search){
        return binarySearch(search_from, to_search, low, middle-1);
    }
    else if(search_from[middle] < to_search){
        return binarySearch(search_from, to_search, middle+1, high);
    }
    else{
        return false;
    }
}

int main(){
    int N;
    cin >> N;

    vector<int> search_from;

    int element;

    for(int i=0; i<N; i++){
        cin >> element;
        search_from.push_back(element);
    }

    int to_search;
    cin >> to_search;

    sort(search_from.begin(), search_from.end());

    bool answer = binarySearch(search_from, to_search, 0, N);

    if(answer){
        cout << "True" << '\n';
    }
    else{
        cout << "False" << '\n';
    }

    return 0;
}