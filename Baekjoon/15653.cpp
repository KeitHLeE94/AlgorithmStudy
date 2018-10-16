//
// Created by Keith_Lee on 15/10/2018.
//
#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <cstring>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int d[10][10][10][10];
int holeX, holeY;

pair<bool, bool> simulate(vector<string> &board, int direction, int &x, int &y){
    if(board[x][y] == '.'){
        return make_pair(false, false);
    }
    int n = board.size();
    int m = board[0].size();

    bool moved = false;

    while(true){
        int nextX = x + dx[direction];
        int nextY = y + dy[direction];

        if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m){
            return make_pair(moved, false);
        }

        if(board[nextX][nextY] == '#'){
            return make_pair(moved, false);
        }
        else if(board[nextX][nextY] == 'R' || board[nextX][nextY] == 'B'){
            return make_pair(moved, false);
        }
        else if(board[nextX][nextY] == '.'){
            swap(board[nextX][nextY], board[x][y]);
            x = nextX;
            y = nextY;
            moved = true;
        }
        else if(board[nextX][nextY] == '0'){
            board[x][y] = '.';
            moved = true;
            return make_pair(moved, true);
        }
    }

    return make_pair(false, false);
}

pair<bool, bool> next(vector<string> board, int &redX, int &redY, int &blueX, int &blueY, int direction){
    board[redX][redY] = 'R';
    board[blueX][blueY] = 'B';
    bool hole1 = false, hole2 = false;

    while(true){
        auto p1 = simulate(board, direction, redX, redY);
        auto p2 = simulate(board, direction, blueX, blueY);

        if(!p1.first && !p2.first){
            break;
        }
        if(p1.second){
            hole1 = true;
        }
        if(p2.second){
            hole2 = true;
        }
    }

    return make_pair(hole1, hole2);
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<string> board(N);
    for(int i=0; i<N; i++) {
        cin >> board[i];
    }
    int answer = -1;
    queue<tuple<int, int, int, int>> Queue;
    int redX, redY, blueX, blueY;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j] == '0'){
                holeX = i;
                holeY = j;
            }
            else if(board[i][j] == 'R'){
                redX = i;
                redY = j;
                board[i][j] = '.';
            }
            else if(board[i][j] == 'B'){
                blueX = i;
                blueY = j;
                board[i][j] = '.';
            }
        }
    }
    memset(d, -1, sizeof(d));
    Queue.emplace(redX, redY, blueX, blueY);
    d[redX][redY][blueX][blueY] = 0;
    bool found = false;

    while(!Queue.empty()){
        tie(redX, redY, blueX, blueY) = Queue.front();
        Queue.pop();
        for(int i=0; i<4; i++){
            bool hole1, hole2;
            int nredX = redX;
            int nredY = redY;
            int nblueX = blueX;
            int nblueY = blueY;

            tie(hole1, hole2) = next(board, nredX, nredY, nblueX, nblueY, i);
            if(hole2){
                continue;
            }
            if(hole1){
                found = true;
                answer = d[redX][redY][blueX][blueY] + 1;
                break;
            }
            if(d[nredX][nredY][nblueX][nblueY] != -1){
                continue;
            }
            Queue.emplace(nredX, nredY, nblueX, nblueY);
            d[nredX][nredY][nblueX][nblueY] = d[redX][redY][blueX][blueY] + 1;
        }
        if(found){
            break;
        }
    }

    cout << answer << '\n';

    return 0;
}