//
// Created by Keith_Lee on 2018. 10. 9..
//
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Node{
    int x;
    int y;
    int mul;
};

int caseNum;
int n;
int map[100][100] = {0, };
bool visit[100][100] = {false, };

Node* newNode(int a, int b){
    Node* temp = new Node;
    temp->x = a;
    temp->y = b;
    temp->mul = a * b;

    return temp;
}

int compare(Node* a, Node* b){
    if(a->mul == b->mul){
        return a->x < b->x;
    }
    return a->mul < b->mul;
}

void BFS(queue<pair<int, int>> *Queue, int startX, int startY, vector<pair<int, int>> *result){
    Queue->push(make_pair(startX, startY));
    visit[startX][startY] = true;
    int sizeX = 1;
    int sizeY = 1;
    Queue->push(make_pair(sizeX, sizeY));

    while(!Queue->empty()){
        int nextX = Queue->front().first;
        int nextY = Queue->front().second;
        Queue->pop();
        int x = Queue->front().first;
        int y = Queue->front().second;
        Queue->pop();

        if(nextY+1<n && map[nextX][nextY+1] && !visit[nextX][nextY+1]){
            visit[nextX][nextY+1] = true;
            Queue->push(make_pair(nextX, nextY+1));
            Queue->push(make_pair(x, y+1));
        }
        if(nextX+1<n && map[nextX+1][nextY] && !visit[nextX+1][nextY]){
            visit[nextX+1][nextY] = true;
            Queue->push(make_pair(nextX+1, nextY));
            Queue->push(make_pair(x+1, y));
        }
        sizeX = x;
        sizeY = y;
    }

    result->push_back(make_pair(sizeX, sizeY));
}

int main(){
    cin >> caseNum;

    for(int i=0; i<caseNum; i++){
        cin >> n;
        for(int j=0; j<100; j++){
            for(int k=0; k<100; k++){
                map[j][k] = 0;
                visit[j][k] = false;
            }
        }

        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cin >> map[j][k];
            }
        }

        queue<pair<int, int>> Queue;
        vector<pair<int, int>> result;

        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(!visit[j][k] && map[j][k] != 0){
                    BFS(&Queue, j, k, &result);
                }
            }
        }

        vector<Node*> temp;

        for(int j=0; j<result.size(); j++){
            Node* node = newNode(result[j].first, result[j].second);
            temp.push_back(node);
        }

        sort(temp.begin(), temp.end(), compare);

        cout << '#' << i+1 << ' ' << temp.size() << ' ';
        for(int j=0; j<temp.size(); j++){
            cout << temp[j]->x << ' ' << temp[j]->y << ' ';
        }
        cout << '\n';
    }

    return 0;
}