//
// Created by Keith_Lee on 06/05/2019.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 왼쪽 아래, 오른쪽 아래, 오른쪽 위, 왼쪽 위 순서
int dx[] = {1, 1, -1, -1};
int dy[] = {-1, 1, 1, -1};

int main(){
    int T;
    cin >> T;

    for(int test=1; test<=T; test++){
        int N;
        cin >> N;

        int map[21][21] = {0, };

        int result = -1;

        vector<pair<int, int>> starts; // 출발점들 집합

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> map[i][j];

                if(i >= 1 && i <= N-2 && j != 1 && j != N){
                    starts.push_back(make_pair(i, j));
                }
            }
        }

        for(int i=0; i<starts.size(); i++){ // 각 출발점들에 대해
            int startX = starts[i].first, startY = starts[i].second; // 시작점
            int leftX = 0, leftY = 0; // 왼쪽 아래 꼭지점
            int rightBX = 0, rightBY = 0; // 오른쪽 아래 꼭지점
            int rightUX = 0, rightUY = 0; // 오른쪽 위 꼭지점

            for(int j=N; j>0; j--){
                leftX = startX + dx[0] * j;
                leftY = startY + dy[0] * j;

                if(leftX >= 1 && leftX <= N && leftY >= 1 && leftY <= N){ // 왼쪽 아래 꼭지점 지정
                    for(int k=N; k>0; k--){
                        rightBX = leftX + dx[1] * k;
                        rightBY = leftY + dy[1] * k;

                        if(rightBX >= 1 && rightBX <= N && rightBY >= 1 && rightBY <= N){ // 오른쪽 아래 꼭지점 지정
                            rightUX = rightBX + dx[2] * j;
                            rightUY = rightBY + dy[2] * j;

                            if(rightUX + dx[3] * k == startX && rightUY + dy[3] * k == startY){ // 네 꼭지점이 모두 지정된 경우
                                bool available = true;
                                set<pair<int, int>> points; // 직사각형의 모든 꼭지점들

                                for(int m=0; m<=j; m++){
                                    int tempX = startX + dx[0] * m;
                                    int tempY = startY + dy[0] * m;

                                    points.insert(make_pair(tempX, tempY)); // 출발점과 왼쪽아래 꼭지점 사이의 모든 점을 set에 추가
                                }

                                for(int m=0; m<=k; m++){
                                    int tempX = leftX + dx[1] * m;
                                    int tempY = leftY + dy[1] * m;

                                    points.insert(make_pair(tempX, tempY));
                                }

                                for(int m=0; m<=j; m++){
                                    int tempX = rightBX + dx[2] * m;
                                    int tempY = rightBY + dy[2] * m;

                                    points.insert(make_pair(tempX, tempY));
                                }

                                for(int m=0; m<=k; m++){
                                    int tempX = rightUX + dx[3] * m;
                                    int tempY = rightUY + dy[3] * m;

                                    points.insert(make_pair(tempX, tempY));
                                }

                                if(points.size() % 2 == 1){
                                    available = false;
                                }

                                bool cafes[101] = {false, };
                                for(pair<int, int> p: points){
                                    int num = map[p.first][p.second];

                                    if(num < 1){
                                        available = false;
                                        break;
                                    }

                                    if(cafes[num]){
                                        available = false;
                                        break;
                                    }

                                    if(!cafes[num]){
                                        cafes[num] = true;
                                    }
                                }

                                if(!available){
                                    continue;
                                }

                                if(result < (int)points.size()){
                                    result = (int)points.size();
                                }
                            }

                        }
                    }
                }
            }
        }

        cout << "#" << test << ' ' << result << '\n';
    }
}