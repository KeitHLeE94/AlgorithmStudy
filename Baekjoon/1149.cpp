//
// Created by Keith_Lee on 02/01/2019.
//

#include <iostream>

using namespace std;

int N;

int min(int a, int b){
    return (a > b) ? b : a;
}

int main(){
    cin >> N;

    int price[N+1][3];
    int DP[N+1][3];

    for(int i=1; i<=N; i++){
        cin >> price[i][0] >> price[i][1] >> price[i][2];
    }

    price[0][0] = price[0][1] = price[0][2] = 0;
    DP[0][0] = DP[0][1] = DP[0][2] = 0;

    for(int i=1; i<N+1; i++){
        DP[i][0] = min(DP[i-1][1], DP[i-1][2]) + price[i][0];
        DP[i][1] = min(DP[i-1][0], DP[i-1][2]) + price[i][1];
        DP[i][2] = min(DP[i-1][0], DP[i-1][1]) + price[i][2];
    }

    cout << min(min(DP[N][0], DP[N][1]), DP[N][2]) << '\n';

//    for(int i=0; i<N; i++){
//        int min = 1001;
//
//        if(i == 0){
//            for(int j=0; j<3; j++){
//                if(min > price[0][j]){
//                    min = price[0][j];
//                    DP[0][0] = min;
//                    DP[0][1] = j;
//                }
//            }
//        }
//        else{
//            cout << DP[i-1][1] << '\n';
//            for(int j=0; j<3; j++){
//                if(j != DP[i-1][1]){
//                    if(min + price[i][j] > DP[i-1][0] + price[i][j]){
//                        min = price[i][j];
//                        DP[i][0] = min + DP[i-1][0];
//                        DP[i][1] = j;
//                    }
//                }
//            }
//        }
//
//        cout << "================" << min << "=================" << '\n';
//        cout << DP[i][1] << '\n';
//    }
//
//    cout << DP[N-1][0] << '\n';

    return 0;
}