//
// Created by Keith_Lee on 2018. 9. 27..
//
#include <iostream>
#include <stack>

using namespace std;

int main(){
    for(int i=0; i<10; i++){
        int length;
        cin >> length;

        char String[length];
        stack<char> Stack;
        int valid = 1;

        for(int j=0; j<length; j++){
            cin >> String[j];
            if(String[j] == '{' || String[j] == '[' || String[j] == '(' || String[j] == '<'){
                Stack.push(String[j]);
            }
            else if(String[j] == '}'){
                if(Stack.top() != '{'){
                    valid = 0;
                }
                else{
                    Stack.pop();
                }
            }
            else if(String[j] == ']'){
                if(Stack.top() != '['){
                    valid = 0;
                }
                else{
                    Stack.pop();
                }
            }
            else if(String[j] == ')'){
                if(Stack.top() != '('){
                    valid = 0;
                }
                else{
                    Stack.pop();
                }
            }
            else if(String[j] == '>'){
                if(Stack.top() != '<'){
                    valid = 0;
                }
                else{
                    Stack.pop();
                }
            }
        }

        cout << '#' << i+1 << ' ' << valid << '\n';
    }

    return 0;
}