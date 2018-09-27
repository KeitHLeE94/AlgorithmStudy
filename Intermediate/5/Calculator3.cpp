//
// Created by Keith_Lee on 2018. 9. 28..
//
#include <iostream>
#include <stack>

using namespace std;

int length;

int back_calculate(string back_expression){
    stack<int> Stack;

    for(int i=0; i<back_expression.length(); i++){
        if(back_expression[i] == '*'){
            int front, back;

            back = Stack.top();
            Stack.pop();
            front = Stack.top();
            Stack.pop();

            int temp = front * back;
            Stack.push(temp);
        }
        else if(back_expression[i] == '+'){
            int front, back;

            back = Stack.top();
            Stack.pop();
            front = Stack.top();
            Stack.pop();

            int temp = front + back;
            Stack.push(temp);
        }
        else{
            Stack.push(back_expression[i] - '0');
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

            if(temp == '*'){
                Stack.push(temp);
            }
            else if(temp == '+'){
                while(!Stack.empty()){
                    if(Stack.top() == '('){
                        break;
                    }
                    back_expression.push_back(Stack.top());
                    Stack.pop();
                }
                Stack.push(temp);
            }
            else if(temp == '('){
                Stack.push(temp);
            }
            else if(temp == ')'){
                while(Stack.top() != '('){
                    back_expression.push_back(Stack.top());
                    Stack.pop();
                }
                Stack.pop();
            }
            else{
                back_expression.push_back(temp);
            }
        }

        while(!Stack.empty()){
            back_expression.push_back(Stack.top());
            Stack.pop();
        }

        int answer = back_calculate(back_expression);

        cout << '#' << i+1 << ' ' << answer << '\n';
    }

    return 0;
}