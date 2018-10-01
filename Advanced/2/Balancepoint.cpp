//
// Created by Keith_Lee on 2018. 10. 1..
//
#include <iostream>

using namespace std;

double calculateBalance(double x1, double x2, double m1, double m2){
    double start = x1;
    if(x1 > x2){
        start = x2;
    }

    for(double i=start; i<x2; i+=0.0000000001){
        cout << "계산중" << '\n';
        if((x1-i)*(x1-i) == (x2-i)*(x2-i)){
            start = i;
            break;
        }
    }

    return start;
}

int main(){
    int caseNum;
    cin >> caseNum;

    for(int i=0; i<caseNum; i++){
        int N;
        cin >> N;

        double pointX[N];
        double pointMeasure[N];
        int inputX;
        int inputMeasure;
        for(int j=0; j<N; j++){
            cin >> inputX;
            pointX[j] = double(inputX);
        }
        for(int j=0; j<N; j++){
            cin >> inputMeasure;
            pointMeasure[j] = double(inputMeasure);
        }

        double pointBalance[N-1];
        for(int j=0; j<N-1; j++){
            pointBalance[j] = calculateBalance(pointX[j], pointX[j+1], pointMeasure[j], pointMeasure[j+1]);
        }

        cout << '#' << i+1 << ' ';
        for(int j=0; j<N-1; j++){
            printf("%.10f ", pointBalance[j]);
        }
        cout << '\n';
    }

    return 0;
}