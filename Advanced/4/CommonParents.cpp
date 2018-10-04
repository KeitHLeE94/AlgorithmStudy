//
// Created by Keith_Lee on 2018. 10. 3..
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nodeCount;

void search_ancestor(int nodeList[], vector<int>* ancestor, int current){
    if(nodeList[current] == 0){
        return;
    }
    else{
        ancestor->push_back(nodeList[current]);
        search_ancestor(nodeList, ancestor, nodeList[current]);
    }
}

void child_count(int nodeList[], int root){
    for(int i=0; i<10001; i++){
        if(nodeList[i] == root){
            nodeCount++;
            child_count(nodeList, i);
        }
    }
}

int main(){
    int caseNum;
    cin >> caseNum;

    for(int i=0; i<caseNum; i++){
        nodeCount = 1;

        int V, E, node1, node2;
        cin >> V >> E >> node1 >> node2;

        int nodeList[10001] = {0, };

        int parent, child;
        for(int j=0; j<E; j++){
            cin >> parent >> child;
            nodeList[child] = parent;
        }

        vector<int> ancestor1, ancestor2;

        search_ancestor(nodeList, &ancestor1, node1);
        search_ancestor(nodeList, &ancestor2, node2);

        int result = 0;

        vector<int> common_ancestors;
        for(int j=0; j<ancestor1.size(); j++){
            for(int k=ancestor2.size()-1; k>=0; k--){
                if(ancestor1[j] == ancestor2[k]){
                    common_ancestors.push_back(ancestor1[j]);
                }
            }
        }

        result = common_ancestors[0];

        child_count(nodeList, result);

        cout << '#' << i+1 << ' ' << result << ' ' << nodeCount << '\n';
    }

    return 0;
}