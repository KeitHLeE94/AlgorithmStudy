//
// Created by Keith_Lee on 2018. 10. 7..
//
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int N;
double E;
int map[1000][2];

long long distance(int a, int b){
    long long x = pow((map[a][0] - map[b][0]), 2);
    long long y = pow((map[a][1] - map[b][1]), 2);

    return x + y;
}

double Prim(){
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    bool visit[1000] = {false, };
    visit[0] = true;
    double result = 0;

    for(int i=0; i<N; i++){
        pq.push(make_pair(distance(0, i), i));
    }

    while(!pq.empty()){
        int current = pq.top().second;
        double weight = pq.top().first;
        pq.pop();

        if(visit[current]){
            continue;
        }
        visit[current] = true;
        result += weight * E;

        for(int i=0; i<N; i++){
            if(!visit[i]){
                pq.push(make_pair(distance(current, i), i));
            }
        }
    }

    return result;
}

int main(){
    int caseNum;
    cin >> caseNum;

    for(int i=0; i<caseNum; i++){
        cin >> N;

        vector<long long> coordX;
        vector<long long> coordY;

        for(int j=0; j<N; j++){
            cin >> map[j][0];
        }
        for(int j=0; j<N; j++){
            cin >> map[j][1];
        }

        cin >> E;

        cout << '#' << i+1 << ' ';
        printf("%.0lf\n", Prim());
    }

    return 0;
}