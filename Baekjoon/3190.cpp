//
// Created by Keith_Lee on 30/04/2019.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int map[101][101] = {0, }; // 0: 빈칸, 1: 뱀, 2: 사과
int direction = 0; // 0: 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
deque<pair<int, int>> snake;
char change[10001];

int main(){
    map[1][1] = 1; // 뱀 초기위치

    int N, K;
    cin >> N >> K;

    for(int i=0; i<K; i++){
        int a, b;
        cin >> a >> b;

        map[a][b] = 2; // 사과
    }

    int L;
    cin >> L;

    for(int i=0; i<L; i++){
        int x;
        char c;

        cin >> x >> c;

        change[x] = c;
    }

    int count = 0;
    snake.push_front(make_pair(1, 1));

    while(true){
        if(change[count] == 'D'){
            if(direction == 3){
                direction = 0;
            }
            else{
                direction++;
            }
        }
        else if(change[count] == 'L'){
            if(direction == 0){
                direction = 3;
            }
            else{
                direction--;
            }
        }

        int headX = snake.front().first;
        int headY = snake.front().second;

        int nextHeadX = headX + dx[direction];
        int nextHeadY = headY + dy[direction];

        if(nextHeadX <= 0 || nextHeadX > N || nextHeadY <= 0 || nextHeadY > N){ // 벽에 닿으면(나가면)
            break;
        }

        if(map[nextHeadX][nextHeadY] == 1){ // 몸에 닿으면
            break;
        }
        else if(map[nextHeadX][nextHeadY] == 2){ // 길이 늘림
            snake.push_front(make_pair(nextHeadX, nextHeadY));
            map[nextHeadX][nextHeadY] = 1;
        }
        else{
            int tailX = snake.back().first;
            int tailY = snake.back().second;
            snake.pop_back();
            map[tailX][tailY] = 0;

            snake.push_front(make_pair(nextHeadX, nextHeadY));
            map[nextHeadX][nextHeadY] = 1;
        }

        count++;
    }

    cout << count + 1 << '\n';

    return 0;
}