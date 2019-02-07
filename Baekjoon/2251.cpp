//
// Created by Keith_Lee on 07/02/2019.
//

#include <iostream>
#include <queue>

using namespace std;

struct water{
    int a, b, c;
};

int A, B, C;
bool visit[201][201];
bool result[201];

void BFS(){
    queue<water> Queue;
    Queue.push({0, 0, C});

    while(!Queue.empty()){
        water current = Queue.front();
        Queue.pop();

        if(visit[current.a][current.b]){
            continue;
        }

        visit[current.a][current.b] = true;

        if(current.a == 0){
            result[current.c] = true;
        }

        if(current.a + current.b > B) { // A -> B / A + B가 B보다 크면 B는 가득, A는 A + B - B의 용량만큼 찬다.
            Queue.push({current.a + current.b - B, B, current.c});
        }
        else{ // A + B가 B보다 작으므로 A의 물을 전부 B로 붓는다.
            Queue.push({0, current.a + current.b, current.c});
        }

        if(current.a + current.b > A){ // B -> A
            Queue.push({A, current.a + current.b - A, current.c});
        }
        else{
            Queue.push({current.a + current.b, 0, current.c});
        }

        if(current.a + current.c > C){ // A -> C
            Queue.push({current.a + current.c - C, current.b, C});
        }
        else{
            Queue.push({0, current.b, current.a + current.c});
        }

        if(current.a + current.c > A){ // C -> A
            Queue.push({A, current.b, current.a + current.c - A});
        }
        else{
            Queue.push({current.a + current.c, current.b, 0});
        }

        if(current.b + current.c > C){ // B -> C
            Queue.push({current.a, current.b + current.c - C, C});
        }
        else{
            Queue.push({current.a, 0, current.b + current.c});
        }

        if(current.b + current.c > B){ // C -> B
            Queue.push({current.a, B, current.b + current.c - B});
        }
        else{
            Queue.push({current.a, current.b + current.c, 0});
        }
    }
}

int main(){
    cin >> A >> B >> C;

    BFS();

    for(int i=0; i<201; i++){
        if(result[i]){
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}