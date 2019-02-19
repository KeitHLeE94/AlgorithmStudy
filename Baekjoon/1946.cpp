//
// Created by Keith_Lee on 19/02/2019.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct candidates{
    int doc, interview;
};

bool compare(candidates &a, candidates &b){
    if(a.doc > b.doc){
        return false;
    }
    return true;
}

int main(){
    int T;

    cin >> T;

    for(int test=0; test<T; test++){
        int N;

        cin >> N;

        vector<candidates> applicants;

        for(int i=0; i<N; i++){
            int doc, interview;

            cin >> doc >> interview;

            applicants.push_back({doc, interview});
        }

        sort(applicants.begin(), applicants.end(), compare);

        int count = 1;

        int standard = applicants[0].interview;

        for(int i=1; i<applicants.size(); i++){
            if(standard > applicants[i].interview){
                standard = applicants[i].interview;
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}