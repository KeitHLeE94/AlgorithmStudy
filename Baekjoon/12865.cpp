//
// Created by Keith_Lee on 24/03/2019.
//

#include <iostream>

using namespace std;

struct item{
    int W, V;
};

int N, K;

int DP[100001] = {0, };

int main(){
    cin >> N >> K;

    item items[101];

    for(int i=0; i<N; i++){
        int weight, value;
        cin >> weight >> value;

        items[i] = {weight, value};
    }

    for(int i=0; i<N; i++){
        for(int j=K; j>=0; j--){
            if(items[i].W <= j){
                DP[j] = max(DP[j], DP[j-items[i].W] + items[i].V);
            }
        }
    }

    cout << DP[K] << '\n';

    return 0;
}