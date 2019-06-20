//
// Created by Keith_Lee on 20/06/2019.
//

#include <iostream>
#include <vector>
#include <strings.h>

using namespace std;

int A[100][100] = {0, };

int main(){
    int r, c, k;
    cin >> r >> c >> k;

    int rowCount = 3;
    int colCount = 3;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> A[i][j];
        }
    }

    int answer = -1;

    if(A[r-1][c-1] == k){
        answer = 0;
    }
    else{
        for(int time=1; time<=100; time++){
            if(rowCount >= colCount){ // R
                int maxRowLength = 0; // 정렬 후 가장 길이가 긴 row의 길이(rowCount 갱신하려고 씀)

                for(int i=0; i<rowCount; i++){
                    int numCount[101] = {0, };
                    vector<int> sorted;

                    for(int j=0; j<colCount; j++){
                        if(A[i][j] != 0){
                            numCount[A[i][j]]++;
                        }
                    }

                    for(int j=0; j<colCount; j++){
                        int minIndex = 0; // 가장 앞에 위치할 숫자
                        int minValue = 101; // 그 숫자의 등장 횟수

                        for(int k=1; k<=100; k++){
                            if(numCount[k] > 0){ // 0번 이상 등장한 숫자
                                if(minValue > numCount[k]){ // 현재 최소 등장 횟수보다 적게 등장했을 경우
                                    minValue = numCount[k];
                                    minIndex = k;
                                }
                                else if(minValue == numCount[k]){ // 현재 최소 등장 횟수와 같은 빈도로 등장했을 경우
                                    if(minIndex > k){ // 이 숫자가 현재 최소로 등장한 숫자보다 작으면
                                        minIndex = k; // 갱신
                                    }
                                }
                            }
                        }

                        if(minIndex == 0){ // 이 행은 정렬이 끝난 상태
                            break;
                        }

                        sorted.push_back(minIndex); // 숫자 먼저 넣고
                        sorted.push_back(minValue); // 빈도 넣음
                        numCount[minIndex] = 0; // 0으로 바꾸고 다음 숫자 탐색
                    }

                    maxRowLength = maxRowLength < sorted.size() ? sorted.size() : maxRowLength;
                    bzero(A[i], sizeof(A[i]));

                    for(int j=0; j<sorted.size(); j++){ // 정렬 끝났음
                        if(j < 100){ // 처음 100개까지만
                            A[i][j] = sorted[j]; // 정렬된 그대로 채워넣음
                        }
                    }
                }

                colCount = maxRowLength; // 정렬 완료 후 가장 긴 행 길이 갱신
            }
            else{ // C
                int maxColLength = 0; // 정렬 후 가장 길이가 긴 col의 길이(colCount 갱신하려고 씀)

                for(int i=0; i<colCount; i++){
                    int numCount[101] = {0, };
                    vector<int> sorted;

                    for(int j=0; j<rowCount; j++){
                        if(A[j][i] != 0){
                            numCount[A[j][i]]++;
                        }
                    }

                    for(int j=0; j<rowCount; j++){
                        int minIndex = 0; // 가장 앞에 위치할 숫자
                        int minValue = 101; // 그 숫자의 등장 횟수

                        for(int k=1; k<=100; k++){
                            if(numCount[k] > 0){ // 0번 이상 등장한 숫자
                                if(minValue > numCount[k]){ // 현재 최소 등장 횟수보다 적게 등장했을 경우
                                    minValue = numCount[k];
                                    minIndex = k;
                                }
                                else if(minValue == numCount[k]){ // 현재 최소 등장 횟수와 같은 빈도로 등장했을 경우
                                    if(minIndex > k){ // 이 숫자가 현재 최소로 등장한 숫자보다 작으면
                                        minIndex = k; // 갱신
                                    }
                                }
                            }
                        }

                        if(minIndex == 0){ // 이 행은 정렬이 끝난 상태
                            break;
                        }

                        sorted.push_back(minIndex); // 숫자 먼저 넣고
                        sorted.push_back(minValue); // 빈도 넣음
                        numCount[minIndex] = 0; // 0으로 바꾸고 다음 숫자 탐색
                    }

                    maxColLength = maxColLength < sorted.size() ? sorted.size() : maxColLength;
                    for(int j=0; j<rowCount; j++){
                        A[j][i] = 0;
                    }

                    for(int j=0; j<sorted.size(); j++){ // 정렬 끝났음
                        if(j < 100){ // 처음 100개까지만
                            A[j][i] = sorted[j]; // 정렬된 그대로 채워넣음
                        }
                    }
                }

                rowCount = maxColLength; // 정렬 완료 후 가장 긴 행 길이 갱신
            }

            if(A[r-1][c-1] == k){
                answer = time;
                break;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}