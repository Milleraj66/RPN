// Author: Arthur Miller
// File Name: DriverRPN.cpp
// Purpose: Driver function to test RPN.cpp
// Date: 01-27-14
// Currently can take a valid Postfix expression with number values from 0 to 9 as a c-string
// and evaluate the expression to a valid integer value using EvaluatePostfix() method

// Added number of nodes in stack method
// Added exeption handling in EvaluatePostfix
// Added IsValidPostfix code
#include "RPN.h"


using namespace std;

// each number in postfix expression must be from 0 to 9

int main()
{
    // c-string for infix style expression
    char Infix1[256] = "1*2*3+1-5+8";
    // c-string for postfix(ReversePolishNotation) style expression
    char PostFix1[256] = "512+4*+3-2/";

    // print intial infix expressions
    cout << "Infix1 Expression: ";
    for(int i=0;i<strlen(Infix1);i++){
        cout << Infix1[i];
    }
    cout << endl;

    // print intial postfix expressions
    cout << "Postfix1 Expression: ";
    for(int i=0;i<strlen(PostFix1);i++){
        cout << PostFix1[i];
    }
    cout << endl;

    /*************************** Testing for RPN *************************/
    // Object for testing PostFix1 expression
    RPN PostfixObject;
    // Will return the evaluated expression value as an int
    cout << "The PostFix1 expression evaluated is : ";
    cout << PostfixObject.EvaluatePostfix(PostFix1);

    // Will return 1 if valid expression 0 if invalid
    cout << "The expression is valid and should return (1): ";
    cout << PostfixObject.IsValidPostfix(PostFix1) << endl;

    return 0;
}
