//
// Created by Keith_Lee on 17/06/2019.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Enemy{
    int x, y;
    bool alive;
};

int N, M, D;
int map[16][16] = {0, };

int distance(int archerY, int enemyX, int enemyY){
    return enemyX + abs(archerY - enemyY);
}

int main(){
    cin >> N >> M >> D;

    vector<Enemy> realEnemies;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];

            if(map[i][j] == 1){
                realEnemies.push_back({i, j, true});
            }
        }
    }

    int maxKill = -1;

    for(int i=1; i<=M; i++){
        for(int j=i+1; j<=M; j++){
            for(int k=j+1; k<=M; k++){
                cout << "archers: ";
                cout << i << ' ' << j << ' ' << k << '\n';
                int kill = 0;

                vector<Enemy> enemies;

                for(int e=0; e<realEnemies.size(); e++){
                    enemies.push_back(realEnemies[e]);
                }

                while(!enemies.empty()){
//                    int tempMap[16][15] = {0, };
//
//                    for(int e=0; e<enemies.size(); e++){
//                        tempMap[enemies[e].x][enemies[e].y] = 1;
//                    }
//
//                    cout << "Before" << '\n';
//
//                    for(int r=1; r<=N; r++){
//                        for(int c=0; c<M; c++){
//                            cout << tempMap[r][c] << ' ';
//                        }
//                        cout << '\n';
//                    }

                    int firstDist = D;
                    int firstY = M;
                    int firstKill = -1;
                    for(int first=0; first<enemies.size(); first++){
                        cout << enemies[first].x << ", " << enemies[first].y << ": ";
                        int temp = distance(i, enemies[first].x, enemies[first].y);
                        cout << temp << '\n';

                        if(temp < firstDist){
                            firstY = enemies[first].y;
                            firstDist = temp;
                            firstKill = first;
                        }
                        else if(temp == firstDist){
                            if(enemies[first].y < firstY){
                                firstY = enemies[first].y;
                                firstDist = temp;
                                firstKill = first;
                            }
                        }
                    }

                    if(firstKill >= 0 && enemies[firstKill].alive){
                        cout << "first: (" << enemies[firstKill].x << ", " << enemies[firstKill].y << ")\n";
                        kill++;
                        enemies[firstKill].alive = false;
                    }
                    cout << '\n';

                    int secondDist = D;
                    int secondY = M;
                    int secondKill = -1;
                    for(int second=0; second<enemies.size(); second++){
                        cout << enemies[second].x << ", " << enemies[second].y << ": ";
                        int temp = distance(j, enemies[second].x, enemies[second].y);
                        cout << temp << '\n';

                        if(temp < secondDist){
                            secondY = enemies[second].y;
                            secondDist = temp;
                            secondKill = second;
                        }
                        else if(temp == secondDist){
                            if(enemies[second].y < secondY){
                                secondY = enemies[second].y;
                                secondDist = temp;
                                secondKill = second;
                            }
                        }
                    }

                    if(secondKill >= 0 && enemies[secondKill].alive){
                        cout << "second: (" << enemies[secondKill].x << ", " << enemies[secondKill].y << ")\n";
                        kill++;
                        enemies[secondKill].alive = false;
                    }
                    cout << '\n';

                    int thirdDist = D;
                    int thirdY = M;
                    int thirdKill = -1;
                    for(int third=0; third<enemies.size(); third++){
                        cout << enemies[third].x << ", " << enemies[third].y << ": ";
                        int temp = distance(k, enemies[third].x, enemies[third].y);
                        cout << temp << '\n';

                        if(temp < thirdDist){
                            thirdY = enemies[third].y;
                            thirdDist = temp;
                            thirdKill = third;
                        }
                        else if(temp == thirdDist){
                            if(enemies[third].y < thirdY){
                                thirdY = enemies[third].y;
                                thirdDist = temp;
                                thirdKill = third;
                            }
                        }
                    }

                    if(thirdKill >= 0 && enemies[thirdKill].alive){
                        cout << "third: (" << enemies[thirdKill].x << ", " << enemies[thirdKill].y << ")\n";
                        kill++;
                        enemies[thirdKill].alive = false;
                    }

                    vector<Enemy> aliveEnemy;

                    for(int ae=0; ae<enemies.size(); ae++){
                        if(enemies[ae].alive){
                            enemies[ae].x--;

                            if(enemies[ae].x > 0){
                                aliveEnemy.push_back(enemies[ae]);
                            }
                        }
                    }

                    enemies.clear();

                    for(int ae=0; ae<aliveEnemy.size(); ae++){
                        enemies.push_back(aliveEnemy[ae]);
                    }

//                    bzero(tempMap, sizeof(tempMap));
//
//                    for(int e=0; e<enemies.size(); e++){
//                        tempMap[enemies[e].x][enemies[e].y] = 1;
//                    }
//
//                    cout << "After" << '\n';
//
//                    for(int r=1; r<=N; r++){
//                        for(int c=0; c<M; c++){
//                            cout << tempMap[r][c] << ' ';
//                        }
//                        cout << '\n';
//                    }

                    cout << '\n';
                }

                cout << "totalKill: " << kill << '\n';
                cout << "======================================================" << '\n';

                maxKill = maxKill < kill ? kill : maxKill;
            }
        }
    }

    cout << maxKill << '\n';

    return 0;
}