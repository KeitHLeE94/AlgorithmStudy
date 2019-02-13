//
// Created by Keith_Lee on 13/02/2019.
//

#include <iostream>
#include <queue>
#include <strings.h>

using namespace std;

int T;
int A, B;
string result;

bool visit[10000] = {false, };
char delta[4] = {'D', 'S', 'L', 'R'};

queue<pair<int, string>> Queue;

void BFS(){
    Queue.push(make_pair(A, ""));
    visit[A] = true;

    while(!Queue.empty()){
        int current = Queue.front().first;
        string currentAnswer = Queue.front().second;
        Queue.pop();

        if(current == B){
            result = currentAnswer;
            break;
        }

        for(int i=0; i<4; i++){
            int next = 0;
            string temp = "";
            if(delta[i] == 'D'){
                next = (current * 2) % 10000;
            }
            else if(delta[i] == 'S'){
                if(current - 1 >= 0){
                    next = (current - 1) % 10000;
                }
                else{
                    next = 9999;
                }
            }
            else if(delta[i] == 'L'){
                next += (current % 1000) * 10;
                next += current / 1000;
            }
            else if(delta[i] == 'R'){
                next += current / 10;
                next += (current % 10) * 1000;
            }

            if(!visit[next]){
                visit[next] = true;
                temp += delta[i];
                Queue.push(make_pair(next, currentAnswer + temp));
            }
        }
    }
}

int main(){
    cin >> T;

    for(int test=0; test<T; test++){
        result = "";
        bzero(visit, sizeof(visit));

        cin >> A >> B;

        BFS();

        while(!Queue.empty()){
            Queue.pop();
        }

        cout << result << '\n';
    }

    return 0;
}