//
// Created by Keith_Lee on 2018. 10. 1..
//
#include <iostream>
#include <math.h>

using namespace std;

int N;
int calCount;
double pointX[10];
double pointMeasure[10];

double calculate(double x1, double x2, double current){
    double forceTotal = 0;

    for(int i=0; i<N; i++){
        double distance = fabs(pointX[i]-current);

        if(pointX[i] < current){
            forceTotal += pointMeasure[i] / (distance*distance);
        }
        else if(pointX[i] > current){
            forceTotal -= pointMeasure[i] / (distance*distance);
        }
    }

    if(fabs(x2 - x1) < 1e-13 || calCount++ > 500){
        return current;
    }

    if(forceTotal <= 0){
        return calculate(x1, current, (x1+current)/2);
    }
    else if(forceTotal > 0){
        return calculate(current, x2, (current+x2)/2);
    }
}

int main(){
    int caseNum;
    cin >> caseNum;

    for(int i=0; i<caseNum; i++){
        for(int j=0; j<10; j++){
            pointX[j] = 0;
            pointMeasure[j] = 0;
        }
        cin >> N;
        calCount = 0;

        for(int j=0; j<N; j++){
            scanf("%lf", &pointX[j]);
        }
        for(int j=0; j<N; j++){
            scanf("%lf", &pointMeasure[j]);
        }

        cout << '#' << i+1 << ' ';
        for(int j=0; j<N-1; j++){
            printf("%.10lf ", calculate(pointX[j], pointX[j+1], (pointX[j] + pointX[j+1])/2));
        }
        cout << '\n';
    }

    return 0;
}