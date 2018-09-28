//
// Created by Keith_Lee on 2018. 9. 29..
//
#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

class LinkedList{
private:
    Node* head = new Node;
    Node* tail = new Node;
public:
    LinkedList(){
        head->data = 0;
        head->next = NULL;
        tail->data = 0;
        tail->next = NULL;
    }

    void insert(int num){
        Node* temp = new Node;
        temp->data = num;
        temp->next = NULL;

        if(head->next == NULL){
            head->next = temp;
            temp->next = tail;
        }
        else{
            Node* cursor = head;
            while(cursor->next != tail){
                cursor = cursor->next;
            }
            cursor->next = temp;
            temp->next = tail;
        }
    }

    void insert_at(int position, int num){
        Node* temp = new Node;
        temp->data = num;
        temp->next = NULL;

        Node* cursor = head;
        for(int i=0; i<position; i++){
            cursor = cursor->next;
        }

        temp->next = cursor->next;
        cursor->next = temp;
    }

    void print(){
        Node* cursor = head;
        for(int i=0; i<10; i++){
            cursor = cursor->next;
            cout << cursor->data << ' ';
        }
    }

    void delete_at(int position, int count){
        Node* cursor = head;
        for(int i=0; i<position-1; i++){
            cursor = cursor->next;
        }

        Node* nextNode = cursor->next;
        for(int i=0; i<count; i++){
            Node* deleteNode = nextNode;
            nextNode = nextNode->next;
            delete deleteNode;
        }

        cursor->next = nextNode;
    }
};

int main(){
    for(int i=0; i<10; i++){
        int length;
        cin >> length;

        LinkedList cipher;

        int word;
        for(int j=0; j<length; j++){
            cin >> word;
            cipher.insert(word);
        }

        int orderNum;
        cin >> orderNum;

        for(int j=0; j<orderNum; j++){
            char orderType;
            cin >> orderType;

            if(orderType == 'I'){
                int position;
                cin >> position;

                int insertNum;
                cin >> insertNum;

                int to_insert;
                for(int k=0; k<insertNum; k++){
                    cin >> to_insert;
                    cipher.insert_at(position, to_insert);
                    position++;
                }
            }
            else if(orderType == 'D'){
                int position;
                cin >> position;

                int deleteNum;
                cin >> deleteNum;

                cipher.delete_at(position, deleteNum);
            }
        }

        cout << '#' << i+1 << ' ';
        cipher.print();
        cout << '\n';
    }

    return 0;
}