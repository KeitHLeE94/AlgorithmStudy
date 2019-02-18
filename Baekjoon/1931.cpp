//
// Created by Keith_Lee on 18/02/2019.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct meeting{
    int start, end;
    bool visit;
};

int N;

bool compare(meeting a, meeting b){
    if(a.end < b.end){
        return true;
    }
    else if(a.end == b.end){
        if(a.start < b.start){
            return true;
        }
    }
    return false;
}

int main(){
    cin >> N;

    vector<meeting> meetings;

    int start, end;

    for(int i=0; i<N; i++){
        cin >> start >> end;

        meetings.push_back({start, end, false});
    }

    sort(meetings.begin(), meetings.end(), compare);

    vector<meeting> available;
    available.push_back(meetings[0]);
    meetings[0].visit = true;

    for(int i=0; i<meetings.size(); i++){
        int currentEnd = available[available.size()-1].end;

        if(meetings[i].start >= currentEnd && !meetings[i].visit){
            available.push_back(meetings[i]);
        }
    }

    cout << available.size() << '\n';

    return 0;
}