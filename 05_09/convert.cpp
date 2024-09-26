#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (int i = 0; i < infix.length(); ++i) {
        char ch = infix[i];

        if (ch == ' ') {
            continue;
        }

        if (isOperand(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            operators.push(ch);
        }
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); 
        }
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
				
                postfix += operators.top();
                operators.pop();
            }

            operators.push(ch);

        }
    }
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
	
	    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix("(" + infix+")");
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
