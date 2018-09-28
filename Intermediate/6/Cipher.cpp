//
// Created by Keith_Lee on 2018. 9. 28..
//
#include <iostream>
#include <queue>

using namespace std;

int main(){
    for(int i=0; i<10; i++){
        int caseNum;
        cin >> caseNum;

        queue<int> Queue;

        int num;
        for(int j=0; j<8; j++){
            cin >> num;
            Queue.push(num);
        }

        while(true){
            int check[8];
            int condition = 0;

            for(int j=1; j<6; j++){
                int temp = Queue.front() - j;
                if(temp <= 0){
                    temp = 0;
                    Queue.pop();
                    Queue.push(temp);
                    condition = 1;
                    break;
                }
                else{
                    Queue.pop();
                    Queue.push(temp);
                }
            }
            for(int j=0; j<8; j++){
                check[j] = Queue.front();
                Queue.pop();
            }

            if(condition == 1){
                for(int j=0; j<8; j++){
                    Queue.push(check[j]);
                }
                break;
            }
            else{
                for(int j=0; j<8; j++){
                    Queue.push(check[j]);
                }
            }
        }

        cout << '#' << caseNum << ' ';
        for(int j=0; j<8; j++){
            cout << Queue.front() << ' ';
            Queue.pop();
        }
        cout << '\n';
    }

    return 0;
}