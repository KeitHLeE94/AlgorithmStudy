//
// Created by Keith_Lee on 2018. 9. 25..
//
#include <iostream>

using namespace std;

int main(){
    int map[100][100];
    bool visit[100][100];

    for(int i=0; i<10; i++) {
        int caseNum;
        cin >> caseNum;

        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                cin >> map[j][k];
            }
        }

        int dist[100] = {0, };

        for (int j = 0; j < 100; j++) {
            int x, y;

            if (map[0][j]) {
                for (int k = 0; k < 100; k++) {
                    for (int l = 0; l < 100; l++) {
                        visit[k][l] = false;
                    }
                }

                x = 0;
                y = j;
                dist[j] = 0;

                visit[x][y] = true;

                while (x != 99) {
                    if (map[x][y + 1] && !visit[x][y + 1] && y < 99) {
                        y++;
                    } else if (map[x][y - 1] && !visit[x][y - 1] && y >= 1) {
                        y--;
                    } else if (map[x + 1][y] && !visit[x + 1][y] && x < 99) {
                        x++;
                    }
                    visit[x][y] = true;
                    dist[j] += 1;
                }
            }
        }

        int min = 9999;
        int index = 0;

        for(int j=0; j<100; j++){
            if(min >= dist[j] && dist[j] != 0){
                min = dist[j];
                index = j;
            }
        }

        cout << '#' << caseNum << ' ' << index << '\n';
    }

    return 0;
}