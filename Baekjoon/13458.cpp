//
// Created by Keith_Lee on 15/10/2018.
//
#include <iostream>
#include <cstring>

using namespace std;

long long N;
long long room[1000000];
long long room_sub[1000000];
long long B, C;

int main(){
    memset(room, 0, sizeof(room));
    memset(room_sub, 0, sizeof(room_sub));
    cin >> N;

    for(long long i=0; i<N; i++){
        cin >> room[i];
    }

    cin >> B >> C;

    long long answer = N;

    for(long long i=0; i<N; i++){
        room_sub[i] = room[i] - B;

        if(room_sub[i] > 0){
            if(room_sub[i] % C == 0){
                answer += room_sub[i] / C;
            }
            else{
                answer += (room_sub[i] / C) + 1;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}