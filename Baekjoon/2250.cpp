//
// Created by Keith_Lee on 21/02/2019.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node{
    int num = -1;
    int left = 0;
    int right = 0;
    int parent = -1;
    int level = -1;
    int location = 0;
};

int N;
int lastLevel = 0; // 트리 최대 레벨
int place = 1;

Node nodeTree[10001] = {{-1, -1, -1, -1}, }; // 입력따라 트리 저장할 공간
bool visit[10001] = {false, };

void inOrder(int start){
    if(!visit[nodeTree[start].left]){
        inOrder(nodeTree[start].left);
    }

    nodeTree[start].location = place++;
    visit[start] = true;

    if(!visit[nodeTree[start].right]){
        inOrder(nodeTree[start].right);
    }
}

void BFS(Node start){ // 각 노드들의 레벨을 찾는다.
    int level = 1;
    queue<Node> Queue;
    vector<Node> nodes;

    Queue.push(start);

    while(!Queue.empty()){
        nodes.clear();

        while(!Queue.empty()){
            Node temp = Queue.front();
            Queue.pop();
            nodes.push_back(temp);
        }

        for(int i=0; i<nodes.size(); i++){
            Node current = nodes[i];
            nodeTree[current.num].level = level;

            if(current.left != -1){
                Queue.push(nodeTree[current.left]);
            }
            if(current.right != -1){
                Queue.push(nodeTree[current.right]);
            }
        }

        level++;
    }
}

int main(){
    visit[0] = true;
    cin >> N;

    int nodeNum;
    int leftChild;
    int rightChild;

    for(int i=1; i<=N; i++){
        cin >> nodeNum >> leftChild >> rightChild;

        nodeTree[nodeNum].num = nodeNum;
        if(leftChild == -1){
            nodeTree[nodeNum].left = 0;
        }
        else{
            nodeTree[nodeNum].left = leftChild;
            nodeTree[leftChild].parent = nodeNum;
        }

        if(rightChild == -1){
            nodeTree[nodeNum].right = 0;
        }
        else{
            nodeTree[nodeNum].right = rightChild;
            nodeTree[rightChild].parent = nodeNum;
        }
    }

    int root = 0;

    for(int i=1; i<=N; i++){
        if(nodeTree[i].parent == -1){
            root = nodeTree[i].num;
            break;
        }
    }

    BFS(nodeTree[root]); // 각 노드의 레벨을 지정한다.

    inOrder(root);

    for(int i=1; i<=N; i++){
        if(lastLevel < nodeTree[i].level){
            lastLevel = nodeTree[i].level;
        }
    }

    int maxWidth = 0;
    int maxLevel = 0;

    vector<int> levels;
    for(int i=1; i<=lastLevel; i++){
        levels.clear();

        for(int j=1; j<=N; j++){
            if(nodeTree[j].level == i){
                levels.push_back(nodeTree[j].location);
            }
        }

        sort(levels.begin(), levels.end());

        int width = levels[levels.size()-1] - levels[0] + 1;

        if(maxWidth < width){
            maxLevel = i;
            maxWidth = width;
        }
    }

    cout << maxLevel << ' ' << maxWidth << '\n';

    return 0;
}