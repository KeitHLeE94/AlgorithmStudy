//
// Created by Keith_Lee on 2018. 9. 25..
//
#include <iostream>
#include <string>

using namespace std;

int main(){
    for(int i=0; i<10; i++){
        int caseNum;
        cin >> caseNum;

        string to_search;
        cin >> to_search;

        string search_from;
        cin >> search_from;

        int total_count = 0;

        for(int j=0; j<search_from.length(); j++){
            int count = 0;
            for(int k=0; k<to_search.length(); k++){
                if(search_from[j+k] == to_search[k]){
                    count++;
                }
                if(count == to_search.length()){
                    total_count++;
                    break;
                }
            }
        }

        cout << '#' << caseNum << ' ' << total_count <<'\n';
    }

    return 0;
}