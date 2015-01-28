// Author: Arthur Miller
// File Name: DriverRPN.cpp
// Purpose: Driver function to test RPN.cpp
// Date: 01-27-14


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

    // Object for testing PostFix1 expression
    RPN PostfixObject;
    // Will return the evaluated expression value as an int
    cout << "The PostFix1 expression evaluated is : ";
    cout << PostfixObject.EvaluatePostfix(PostFix1);

    return 0;
}
