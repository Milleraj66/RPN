// Author: Arthur Miller
// File Name: DriverRPN.cpp
// Purpose: Driver function to test RPN.cpp



#include "RPN.h"


using namespace std;



int main()
{
    // c-string for infix style expression
    char Infix1[256] = "1*2*3+1-5+8";
    // c-string for postfix(ReversePolishNotation) style expression
    char PostFix1[256] = "512+4*+3";

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

    char a = '2';
    char b = '9';
    int tmp = 0;
    tmp = a*b;
    cout << tmp << endl;
    int tmpa = a-48;
    int tmpb = b-48;
    cout << tmpa << endl;
    cout << tmpb << endl;
    tmp = tmpa*tmpb;
    cout << tmp << endl;

    RPN L1;

    // Testing for Postfix evaluation of expression
    cout << L1.EvaluatePostfix(PostFix1) << endl;


    return 0;
}
