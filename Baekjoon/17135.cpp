//
// Created by Keith_Lee on 17/06/2019.
//

#include <iostream>
#include <vector>

using namespace std;

struct Enemy{
    int x, y; // 적 위치
    bool alive; // 적 생존여부
};

int N, M, D;
int map[16][16] = {0, };

int distance(int archerY, int enemyX, int enemyY){ // 거리 구하는 함수
    return abs((N+1) - enemyX) + abs(archerY - enemyY);
}

int main(){
    cin >> N >> M >> D;

    vector<Enemy> realEnemies; // 입력으로 주어진 적들

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];

            if(map[i][j] == 1){
                realEnemies.push_back({i, j, true});
            }
        }
    }

    int maxKill = -1; // 최대값

    // 궁수 위치 조합
    for(int i=1; i<=M; i++){
        for(int j=i+1; j<=M; j++){
            for(int k=j+1; k<=M; k++){
                int kill = 0; // 현재 위치에서 킬수

                vector<Enemy> enemies; // 현재 살아있는 적들

                for(int e=0; e<realEnemies.size(); e++){ // 입력으로 주어진 적들로 현재 살아있는 적들 vector 초기화
                    enemies.push_back(realEnemies[e]);
                }

                while(!enemies.empty()){ // 적이 전부 없어질때까지 반복
                    int firstDist = D; // 첫번째 궁수가 죽일 적까지의 거리
                    int firstY = M+1; // 첫번째 궁수가 죽일 적의 위치(왼쪽에서 몇번째인지)
                    int firstKill = -1; // 첫번째 궁수가 죽일 적의 vector 내 인덱스
                    for(int first=0; first<enemies.size(); first++){
                        int temp = distance(i, enemies[first].x, enemies[first].y); // 첫번째 궁수와 적과의 거리

                        if(temp < firstDist){ // 더 가까운 곳에 적이 있는 경우
                            firstY = enemies[first].y;
                            firstDist = temp;
                            firstKill = first;
                        }
                        else if(temp == firstDist){
                            if(enemies[first].y < firstY){ // 적과의 거리가 같고 현재 타겟보다 왼쪽에 적이 있는 경우
                                firstY = enemies[first].y;
                                firstDist = temp;
                                firstKill = first;
                            }
                        }
                    }

                    if(firstKill >= 0 && enemies[firstKill].alive){ // 이미 죽은 적이 아닐 경우
                        kill++; // 킬수 늘림
                        enemies[firstKill].alive = false; // 맞은 적 죽었다고 표시
                    }

                    int secondDist = D; // 두번째 궁수가 죽일 적까지의 거리
                    int secondY = M+1; // 두번째 궁수가 죽일 적의 위치(왼쪽에서 몇번째인지)
                    int secondKill = -1; // 두번째 궁수가 죽일 적의 vector 내 인덱스
                    for(int second=0; second<enemies.size(); second++){
                        int temp = distance(j, enemies[second].x, enemies[second].y); // 두번째 궁수와 적과의 거리

                        if(temp < secondDist){ // 더 가까운 곳에 적이 있는 경우
                            secondY = enemies[second].y;
                            secondDist = temp;
                            secondKill = second;
                        }
                        else if(temp == secondDist){
                            if(enemies[second].y < secondY){ // 적과의 거리가 같고 현재 타겟보다 왼쪽에 적이 있는 경우
                                secondY = enemies[second].y;
                                secondDist = temp;
                                secondKill = second;
                            }
                        }
                    }

                    if(secondKill >= 0 && enemies[secondKill].alive){ // 이미 죽은 적이 아닐 경우
                        kill++; // 킬수 늘림
                        enemies[secondKill].alive = false; // 맞은 적 죽었다고 표시
                    }

                    int thirdDist = D; // 세번째 궁수가 죽일 적까지의 거리
                    int thirdY = M+1; // 세번째 궁수가 죽일 적의 위치(왼쪽에서 몇번째인지)
                    int thirdKill = -1; // 세번째 궁수가 죽일 적의 vector 내 인덱스
                    for(int third=0; third<enemies.size(); third++){
                        int temp = distance(k, enemies[third].x, enemies[third].y); // 세번째 궁수와 적과의 거리

                        if(temp < thirdDist){ // 더 가까운 곳에 적이 있는 경우
                            thirdY = enemies[third].y;
                            thirdDist = temp;
                            thirdKill = third;
                        }
                        else if(temp == thirdDist){
                            if(enemies[third].y < thirdY){ // 적과의 거리가 같고 현재 타겟보다 왼쪽에 적이 있는 경우
                                thirdY = enemies[third].y;
                                thirdDist = temp;
                                thirdKill = third;
                            }
                        }
                    }

                    if(thirdKill >= 0 && enemies[thirdKill].alive){ // 이미 죽은 적이 아닐 경우
                        kill++; // 킬수 늘림
                        enemies[thirdKill].alive = false; // 맞은 적 죽었다고 표시
                    }

                    vector<Enemy> aliveEnemy; // 라운드 끝난 후 살아있는 적

                    for(int ae=0; ae<enemies.size(); ae++){
                        if(enemies[ae].alive){ // 한 라운드 진행 후 살아있는 적들에 대해
                            enemies[ae].x++; // 성쪽으로 한칸 이동

                            if(enemies[ae].x <= N){ // 이동 후 성에 닿지 않았으면
                                aliveEnemy.push_back(enemies[ae]); // 라운드 끝난 후 살아있는 적 vector에 추가
                            }
                        }
                    }

                    enemies.clear(); // 현재 살아있는 적 초기화

                    for(int ae=0; ae<aliveEnemy.size(); ae++){
                        enemies.push_back(aliveEnemy[ae]); // 현재 살아있는 적들로 적 vector 갱신
                    }

                }

                maxKill = maxKill < kill ? kill : maxKill; // 전부 진행한 후 킬수 최대값 갱신
            }
        }
    }

    cout << maxKill << '\n';

    return 0;
}