/* main.cpp
 *
 * Program to turn infix expressions into thier postfix counterpart through the use of a stack.
 */
 
// System Includes
#include <iostream>

// User-Defined Includes
#include "infixToPostfix.h"
#include "list.h"

using namespace std;

int main() {
    // output the purpose of program
    cout << "This program converts expressions from infix to their postfix form.\n\n";

    // get infix expression
    string infixExpression = getInfixExpression();

    // turn infix into postfix expression
    cout << "\nConverting from infix to postfix...\n";
    string postfix = infixToPostfix(infixExpression);
    
    // output postfix expression
    cout << "Complete\n\nThe postfix expression is: ";
    cout << postfix << '\n';
    
    return 0;
}