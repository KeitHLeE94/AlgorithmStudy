//
// Created by Keith_Lee on 2018. 9. 29..
//
#include <iostream>
#include <queue>

using namespace std;

struct listNode{
    char data;
    listNode* next;
};

struct BTreeNode{
    char data;
    BTreeNode* left;
    BTreeNode* right;
};

void push_list(listNode** cursor, char data){
    listNode* temp = new listNode;
    temp->data = data;
    temp->next = *cursor;
    *cursor = temp;
}

BTreeNode* newBTreeNode(char data){
    BTreeNode* temp = new BTreeNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void list2tree(listNode* head, BTreeNode* &root){
    queue<BTreeNode*> Queue;

    if(head == NULL){
        root = NULL;
        return;
    }

    root = newBTreeNode(head->data);
    Queue.push(root);

    head = head->next;

    while(head){
        BTreeNode* parent = Queue.front();
        Queue.pop();

        BTreeNode* leftChild = NULL;
        BTreeNode* rightChild = NULL;

        leftChild = newBTreeNode(head->data);
        Queue.push(leftChild);
        head = head->next;

        if(head){
            rightChild = newBTreeNode(head->data);
            Queue.push(rightChild);
            head = head->next;
        }

        parent->left = leftChild;
        parent->right = rightChild;
    }
}

void Inorder_Traversal(BTreeNode* root){
    if(root){
        Inorder_Traversal(root->left);
        cout << root->data;
        Inorder_Traversal(root->right);
    }
}

int main(){
    for(int i=0; i<10; i++){
        int N;
        cin >> N;

        int nodeIndex;
        char word[N+1];
        int left, right;

        if(N == 1){
            cin >> nodeIndex >> word;
        }
        else{
            for(int j=0; j<N/2; j++){
                if(j == N/2 - 1 && N%2 == 0){
                    cin >> nodeIndex >> word[nodeIndex] >> left;
                }
                else{
                    cin >> nodeIndex >> word[nodeIndex] >> left >> right;
                }
            }
            for(int j=0; j<N-N/2; j++){
                cin >> nodeIndex >> word[nodeIndex];
            }
        }

        listNode* head = NULL;

        for(int j=N; j>0; j--){
            push_list(&head, word[j]);
        }

        BTreeNode* root = NULL;
        list2tree(head, root);

        cout << '#' << i+1 << ' ';
        Inorder_Traversal(root);
        cout << '\n';
    }

    return 0;
}