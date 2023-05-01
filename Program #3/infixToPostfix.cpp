/* infixToPostfix.cpp
 *
 * function definitions for the algorithm to turn an infix expression into a postfix one
 */
 
// System includes
#include <iostream>
#include <string>

// User Defined includes
#include "infixToPostfix.h"
#include "stack.h"

using namespace std;

// global variables
extern const char OPEN_PAREN;
extern const char CLOSED_PAREN;

// strip the space between an expression
string stripSpace(string expression) {
    string newExpression = "";
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] != ' ') {
            newExpression.push_back(expression[i]);
        }
    }
    return newExpression;
}

// return a valid infix expression 
string getInfixExpression() {
    string expression;
    cout << "Please enter an infix expression: ";
    getline(cin, expression);

    expression = stripSpace(expression);

    // make sure expression is balanced
    while (!isBalanced(expression) || !(conatainValidChars(expression))) {
        // output error
        cout << "Error: Expression not valid\nPlease re-enter infix expression: ";

        // get new input
        getline(cin, expression);
        
        // strip space between expression
        expression = stripSpace(expression);
    }

    return expression;
}

// check if the character is an allowed operator
bool isOperator(char c) {
    switch (c) {
        case '+':
            return true;
            break;
        case '-':
            return true;
            break;
        case '*':
            return true;
            break;
        case '/':
            return true;
            break;
        case '^':
            return true;
            break;
        case OPEN_PAREN:
            return true;
            break;
        case CLOSED_PAREN:
            return true;
            break;
        default:
            return false;
            break;
    }
}

// make sure the string only contains valid operators/numbers
bool conatainValidChars(string expression) {
    // return false if any expression is neither an operator or a valid number
    for (int i = 0; i < expression.length(); i++) {
        if ( !( ( isOperator(expression[i]) ) || ( expression[i] >= '0' && expression[i] <= '9' ) ) ) {
            // character is neither an operator or valid number
            // cout << "Not valid chars\n";
            return false;
        }
    }
    // all chars are valid
    return true;
}

// make sure the parenthesis match
bool parenMatch( char currToken, char stackToken ) {
    return (stackToken == OPEN_PAREN && currToken == CLOSED_PAREN);
}

// check to make sure the parenthesis are correct within expression
bool isBalanced(string expression) {
    char currToken;         // current token
    char stackToken;        // token on top of stack
    bool balanced = true;
    Stack s;

    int i = 0;

    while (i < expression.length() && balanced) {
        currToken = expression[i];
        if (currToken == OPEN_PAREN) {
            s.push(currToken);
        } else if (currToken == CLOSED_PAREN) {
            if (s.isEmpty()) {
                balanced = false;
            } else {
                stackToken = s.pop();
                balanced = parenMatch(currToken, stackToken);
            }
        }
        i++;
    }

    return (balanced && s.isEmpty());
}

// ('+' == '-') < ('*' == '/') < ('^')
// compare operator one to operator two, where opOne is the current, and opTwo
// operator at top of stack
bool compareOperator(char token, char stackOp) {
    if ((token == '^') && ( stackOp == '^' || stackOp == '*' || stackOp == '/' || stackOp == '+' || stackOp == '-')) {
        // ^ > +, -, *, /
        return true;
    } else if ((token == '*' || token == '/') && (stackOp == '*' || stackOp == '/')) {
        // *,/ == *, /
        return true;
    } else if ((token == '*' || token == '/') && (stackOp == '+' || stackOp == '-')) {
        // *, / > +, -
        return true;
    } else if ((token == '+' || token == '-') && (stackOp == '+' || stackOp == '-')) {
        // +, - == +, -
        return true;
    } else {
        return false;
    }
}

// turn the infix expression to postfix expression
string infixToPostfix(string infix) {
    string postfix = "";

    Stack s;

    // push a open paren onto stack
    s.push(OPEN_PAREN);
    // add a closed paren to end of infix expression
    infix.push_back(CLOSED_PAREN);

    int i = 0;
    char token;
    char c;

    // while stack is not empty
    while (!s.isEmpty()) {
        // get next token of infix expression
        token = infix[i];

        if ( token == OPEN_PAREN ) {
            // if token is an open paren
            s.push(token);
        } else if ( token >= '0' && token <= '9' ) {
            // add number to end of postfix expression
            postfix.push_back(token);
        } else if ( token == CLOSED_PAREN ) {
            // token is a closed paren
            // pop element c from the stack
            c = s.pop();
            // while the character is not an open paren
            while (c != OPEN_PAREN) {
                // place c at end of postfix expression
                postfix.push_back(c);
                // pop next element off stack
                c = s.pop();
            }
        } else {
            // token is an operator
            // while top of stack is an operator with precedence >= to token
            while (compareOperator(s.peek(), token)) {
                // pop element c from stack
                c = s.pop();
                // place it at end of postfix
                postfix.push_back(c);
            }
            // push token onto stack
            s.push(token);
        }
        i++;
    }

    return postfix;
}