//
// Created by Keith_Lee on 2018. 10. 3..
//
#include <iostream>
#include <vector>

using namespace std;

int nodeCount = 0;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int parentInfo;
    bool visit;
};

Node* find_node(vector<Node*> nodeList, int info){
    for(int i=0; i<nodeList.size(); i++){
        if(nodeList[i]->data == info){
            return nodeList[i];
        }
    }
}

void search_ancestor(vector<Node*> nodeList, vector<int>* ancestor, Node* current){
    if(current->parent == NULL){
        return;
    }
    for(int i=1; i<10001; i++){
        if(i == current->parentInfo){
            ancestor->push_back(i);
            search_ancestor(nodeList, ancestor, current->parent);
        }
    }
}

void DFS(Node* current){
    nodeCount++;
    current->visit = true;
    if(current->left && !current->left->visit){
        DFS(current->left);
    }
    if(current->right && !current->right->visit){
        DFS(current->right);
    }
    else{
        return;
    }
}

int main(){
    int caseNum;
    cin >> caseNum;

    for(int i=0; i<caseNum; i++){
        nodeCount = 0;
        vector<Node*> nodeList;

        int V, E, node1, node2;
        cin >> V >> E >> node1 >> node2;

        int parent, child;

        Node* root = new Node;
        root->data = 1;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        root->visit = false;

        nodeList.push_back(root);

        for(int j=0; j<E; j++){
            cin >> parent >> child;

            Node* parentNode = find_node(nodeList, parent);

            Node* newNode = new Node;
            newNode->data = child;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = parentNode;
            newNode->parentInfo = parent;
            newNode->visit = false;

            if(parentNode->left == NULL){
                parentNode->left = newNode;
            }
            else if(parentNode->left != NULL && parentNode->right == NULL){
                parentNode->right = newNode;
            }

            nodeList.push_back(newNode);
        }

        vector<int> ancestor1, ancestor2;

        Node* child1 = find_node(nodeList, node1);
        Node* child2 = find_node(nodeList, node2);

        search_ancestor(nodeList, &ancestor1, child1);
        search_ancestor(nodeList, &ancestor2, child2);

        for(int j=0; j<ancestor1.size(); j++){
            cout << ancestor1[j] << ' ';
        }
        cout << '\n';

        for(int j=0; j<ancestor2.size(); j++){
            cout << ancestor2[j] << ' ';
        }
        cout << '\n';

        int result = 0;
        for(int j=0; j<ancestor1.size(); j++){
            for(int k=0; k<ancestor2.size(); k++){
                if(ancestor1[j] == ancestor2[k]){
                    result = max(ancestor1[j], result);
                }
            }
        }

        DFS(find_node(nodeList, result));
        cout << '#' << i+1 << ' ' << result << ' ' << nodeCount << '\n';
    }

    return 0;
}