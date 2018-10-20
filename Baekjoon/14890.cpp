//
// Created by Keith_Lee on 20/10/2018.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, L;
int map[100][100];
int result = 0;

bool checkOut(int to_check[], int size){
//    for(int i=0; i<size; i++){
//        cout << to_check[i] << ' ';
//    }
//    cout << '\n';
    bool visit[size]; //경사로가 겹치는 경우 방지하기 위해 사용
    memset(visit, false, sizeof(visit));

    for(int i=1; i<size; i++){
        if(to_check[i-1] != to_check[i]){ //높이가 다른 경우
            int difference = abs(to_check[i-1] - to_check[i]);
            if(difference != 1){
                return false;
            } //높이 차이가 1보다 크면 안됨.
            if(to_check[i-1] < to_check[i]){
                for(int j=1; j<=L; j++){
                    if(i-j < 0){
//                        cout << "reason1" << '\n';
                        return false;
                    } //경사로가 맵을 벗어나면 안됨.
                    if(to_check[i-1] != to_check[i-j]){
//                        cout << "reason2" << '\n';
                        return false;
                    } //경사로가 놓이는 모든 곳의 높이가 일치해야 함.
                    if(visit[i-j]){
//                        cout << "reason3" << '\n';
                        return false;
                    } //경사로 위에 또다른 경사로가 놓아지면 안됨.
                    visit[i-j] = true;
                }
            }
            else{
                for(int j=0; j<L; j++){
                    if(i+j >= size){
//                        cout << "reason4" << '\n';
                        return false;
                    } //경사로가 맵을 벗어나면 안됨.
                    if(to_check[i] != to_check[i+j]){
//                        cout << "reason5" << '\n';
                        return false;
                    } //경사로가 놓이는 모든 곳의 높이가 일치해야 함.
                    if(visit[i+j]){
//                        cout << "reason6" << '\n';
                        return false;
                    } //경사로 위에 또다른 경사로가 놓아지면 안됨.
                    visit[i+j] = true;
                }
            }
        }
    }

    return true;
}
int main(){
    cin >> N >> L;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<N; i++){
        int to_check[N];
        for(int j=0; j<N; j++){
            to_check[j] = map[i][j];
        }
        if(checkOut(to_check, N)){
            result++;
        }
    }
    for(int i=0; i<N; i++){
        int to_check[N];
        for(int j=0; j<N; j++){
            to_check[j] = map[j][i];
        }
        if(checkOut(to_check, N)){
            result++;
        }
    }

    cout << result << '\n';

    return 0;
}