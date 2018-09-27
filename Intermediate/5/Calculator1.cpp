//
// Created by Keith_Lee on 2018. 9. 27..
//
#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>

using namespace std;

int length;

int back_calculate(string back_expression){
    stack<int> Stack;

    for(int i=0; i<length; i++){
        if(back_expression[i] != '+'){
            Stack.push(back_expression[i] - '0');
        }
        else{
            int front, back;

            back = Stack.top();
            Stack.pop();
            front = Stack.top();
            Stack.pop();

            int temp = front + back;
            Stack.push(temp);
        }
    }

    int result = Stack.top();
    Stack.pop();

    return result;
}

int main(){
    for(int i=0; i<10; i++){
        cin >> length;

        string expression;
        string back_expression;

        stack<char> Stack;

        for(int j=0; j<length; j++){
            char temp;
            cin >> temp;
            expression.push_back(temp);
            if(temp == '+'){
                while(!Stack.empty()){
                    back_expression.push_back(Stack.top());
                    Stack.pop();
                }
                Stack.push(temp);
            }
            else{
                back_expression.push_back(temp);
            }
        }

        back_expression.push_back(Stack.top());
        Stack.pop();

        int answer = back_calculate(back_expression);

        cout << '#' << i+1 << ' ' << answer << '\n';
    }

    return 0;
}