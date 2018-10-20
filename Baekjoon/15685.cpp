//
// Created by Keith_Lee on 19/10/2018.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
int x, y, d, g;
int map[101][101];

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> x >> y >> d >> g;
        vector<int> directions;
        directions.push_back(d);

        while(g--){
            for(int j=directions.size()-1; j>=0; j--){
                int dir = directions[j];
                directions.push_back((dir+1 % 4));
            }
        }

        map[x][y] = 1;

        for(int j=0; j<directions.size(); j++){
            int dir = directions[j];

            if(dir == 0){
                x++;
            }
            else if(dir == 1){
                y--;
            }
            else if(dir == 2){
                x--;
            }
            else if(dir == 3){
                y++;
            }

            map[x][y] = 1;
        }
    }

    int result = 0;

    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1]){
                result++;
            }
        }
    }

    cout << result << '\n';

    return 0;
}