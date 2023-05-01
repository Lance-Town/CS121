/* infixToPostfix.h
 *
 * function prototypes for the algorithm to turn an infix expression into a postfix one
 */
 
#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

// System includes
#include <string>

// Global variables
const char OPEN_PAREN = '(';
const char CLOSED_PAREN = ')';

using namespace std;

string stripSpace(string);          // strip spaces from the expression
string getInfixExpression();         // get valid infix expression from user
bool isBalanced(string);            // check if expression is balanced
bool isOperator(char);              // check if character is a valid operator
bool conatainValidChars(string);    // make sure string only contains valid operators/numbers
string infixToPostfix(string);        // convert infix to postfix expression
bool compareOperator(char, char);   // compare the operator to the order of operations
bool parenMatch(char, char);        // ensure the parenthesis match open to closed

#endif /* INFIX_TO_POSTFIX_H */