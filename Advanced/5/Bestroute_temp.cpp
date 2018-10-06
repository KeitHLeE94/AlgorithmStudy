//
// Created by Keith_Lee on 2018. 10. 4..
//
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    int caseNum;
    cin >> caseNum;

    for(int i=0; i<caseNum; i++){
        int N;
        cin >> N;

        int companyX, companyY;
        cin >> companyX >> companyY;

        int homeX, homeY;
        cin >> homeX >> homeY;

        vector<pair<int, int>> customers;

        int customerX, customerY;
        for(int j=0; j<N; j++){
            cin >> customerX >> customerY;
            customers.push_back(make_pair(customerX, customerY));
        }

        sort(customers.begin(), customers.end());

        int result = 99999;

        do{
            int distance = 0;

            distance += (abs(companyX - customers[0].first) + abs(companyY - customers[0].second));
            for(int j=0; j<N-1; j++){
                distance += (abs(customers[j].first - customers[j+1].first) + abs(customers[j].second - customers[j+1].second));
            }
            distance += (abs(homeX - customers[N-1].first) + abs(homeY - customers[N-1].second));

            result = min(result, distance);
        }
        while(next_permutation(customers.begin(), customers.end()));

        cout << '#' << i+1 << ' ' << result << '\n';
    }

    return 0;
}