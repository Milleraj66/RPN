// Author: Arthur Miller
// File Name: RPN.cpp
// Purpose: Stack implementation of Reverse Polition Notation, using Singly Linked List code for ECE304 ExtrCredit1


#include "RPN.h"


// Add a Node to the head (front) of the linked list
void RPN::Push(int data){
    Head = new Node(data, Head);
    if(Tail == 0)
        Tail = Head;
} // END Push()
// Remove Node from head of linked list
void RPN::Pop(){

    if (Head == 0 && Tail == 0){
            cout << "Nothing to remove from head, the list is empty\n";

    }
    // If only one node left point head and tail to NULL to empty list
    else if(Head == Tail){
        //cout << "List is already empty" << endl;
        Head = NULL;
        Tail = NULL;
    }
    // Point Head to Head-> next effectively removing the head of the linked list
    else{
        Head = Head->Next;
    }
}// END Pop()
int RPN::NumberOfNodes(){
    Node *tmp = Head;
    // counter to hold how many nodes are in stack
    int counter = 0;
    do {
        // If list is empty cant use tmp->next must print that list is empty
        if(IsEmpty()){
            return 0;
        }
        else{
            counter++;
            tmp = tmp->Next;
        }

    }while(tmp != NULL);
    return (counter);
}
// Print full linked list
void RPN::Print(){
    Node *tmp = Head;
    do {
        // If list is empty cant use tmp->next must print that list is empty
        if(IsEmpty()){
            cout << "The List is empty, Nothing to Print\n";
        }
        else{
            cout << tmp->Data << " -> ";
            tmp = tmp->Next;
        }

    }while(tmp != NULL);
    cout << endl;
    delete tmp;
}// END Print()
/********************************** RPN METHODS *************************************/
// Convert Infix notation to Postfix (RPN) notation
void RPN::InfixToPostfix(char*){

}//END InfixToPostfix()
// Check if valid Infix expression
bool RPN::IsValidInfix(char*){


}//END IsValidInfix()
// Evaluate given Postfix (RPN) expression
int RPN::EvaluatePostfix(char* Expression){
    // parse the c-string expression, push each number encountered onto stack
    // when an operator is encountered pop of the last two elements and evaluate
    // the operator with the two popped off elements, repeate until c-string is empty

    for(int i=0; i < strlen(Expression); i++){
        //cout << Expression[i] << endl;
        // will hold variable to be pushed back onto stack after evaluating current operation
        // expetion handling
        try{
            if(Expression[i] == '+'){
                // Exeption handling
                // Test that Number of Nodes method is working
                cout << "number of nodes in stack: " << NumberOfNodes() << endl;
                if(NumberOfNodes() < 2){
                    throw 1;
                }

                // add the top two values on the stack and place in tmpPlusValue
                int tmpPlusValue = Head->Next->Data + Head->Data;
                cout << "DEBUG::EvaluatePostfix::if-- Addition of top two values on stack: ";
                cout << Head->Next->Data << " + " << Head->Data << " = " << tmpPlusValue << endl;
                // remove two top values that have just been added
                Pop();
                Pop();
                // push newly added number onto the stack as a replacement
                Push(tmpPlusValue);
                // print out what the stack looks like
                cout << "DEBUG::EvaluatePostfix::if-- New stack after addition: ";
                Print();
            }

            else if(Expression[i] == '-'){
                // Exeption handling
                // Test that Number of Nodes method is working
                cout << "number of nodes in stack: " << NumberOfNodes() << endl;
                if(NumberOfNodes() < 2){
                    throw 2;
                }

                // minus the top two values on the stack and place in tmpPlusValue
                int tmpMinusValue = Head->Next->Data - Head->Data;
                cout << "DEBUG::EvaluatePostfix::if-- Minus of top two values on stack: ";
                cout << Head->Next->Data << " - " << Head->Data << " = " << tmpMinusValue << endl;
                // remove two top values that have just been added
                Pop();
                Pop();
                // push newly added number onto the stack as a replacement
                Push(tmpMinusValue);
                // print out what the stack looks like
                cout << "DEBUG::EvaluatePostfix::if-- New stack after subtraction: ";
                Print();
            }
            else if(Expression[i] == '*'){
                // Exeption handling
                // Test that Number of Nodes method is working
                cout << "number of nodes in stack: " << NumberOfNodes() << endl;
                if(NumberOfNodes() < 2){
                    throw 3;
                }

                // multiply the top two values on the stack and place in tmpPlusValue
                int tmpMultValue = Head->Next->Data * Head->Data;
                cout << "DEBUG::EvaluatePostfix::if-- Multiplication of top two values on stack: ";
                cout << Head->Next->Data << " * " << Head->Data << " = " << tmpMultValue << endl;
                // remove two top values that have just been added
                Pop();
                Pop();
                // push newly added number onto the stack as a replacement
                Push(tmpMultValue);
                // print out what the stack looks like
                cout << "DEBUG::EvaluatePostfix::if-- New stack after Multiplicaiton: ";
                Print();
            }
            else if(Expression[i] == '/'){
                // Exeption handling
                // Test that Number of Nodes method is working
                cout << "number of nodes in stack: " << NumberOfNodes() << endl;
                if(NumberOfNodes() < 2){
                    throw 4;
                }

                // divide the top two values on the stack and place in tmpPlusValue
                int tmpDivValue = Head->Next->Data / Head->Data;
                cout << "DEBUG::EvaluatePostfix::if-- Divide of top two values on stack: ";
                cout << Head->Next->Data << " / " << Head->Data << " = " << tmpDivValue << endl;
                // remove two top values that have just been added
                Pop();
                Pop();
                // push newly added number onto the stack as a replacement
                Push(tmpDivValue);
                // print out what the stack looks like
                cout << "DEBUG::EvaluatePostfix::if-- New stack after division: ";
                Print();
            }

            // else the token is a value so it must be pushed onto stack
            // convert char value to int value and push onto stack
            else{
                int valueToBePushed = 0;
                // converts to char number to int number
                valueToBePushed = (Expression[i] - '0');
                Push(valueToBePushed);
                cout << "DEBUG::EvaluatePostfix::else-- newly pushed value on stack: " << Head->Data << endl;
            }
        }// END try block
        // If and error is found return specific error codes that will be used by IsValidPostfix()
        catch(int ERROR){
            // remove all elements in stack
            while(!IsEmpty()){
                cout << "Trying to clear stack after ERROR: Before: ";
                Print();
                Pop();
                cout << "Trying to clear stack after ERROR: After: ";
                Print();
            }

            // Error in addition block
            if(ERROR == 1)
                return (-1);
            // Error in subratno block
            else if(ERROR == 2)
                return (-1);
            // Error in Multiplicaiton block
            else if(ERROR == 3)
                return (-1);
            // Error in Division block
            else if(ERROR == 4)
                return (-1);
        }
    }// END for() loop

    // Exepetion handling for if there is more than one node at the end of calculations
    try{
        if(NumberOfNodes() > 1) throw 5;
        }
        catch(int e){
            // remove all elements in stack
            while(!IsEmpty()){
                cout << "Trying to clear stack after ERROR: Before: ";
                Print();
                Pop();
                cout << "Trying to clear stack after ERROR: After: ";
                Print();
            }
            // Return ERROR code
            return (-100001);
        }

    // tmpReturn holds the value needed to return, then we pop() to remove the last element and free
    // stack for next use
    int tmpReturn = Head->Data;
    Pop();
    return (tmpReturn);
}//END EvaluatePostfix()
// Check if given Postfix (RPN) expression is valid
bool RPN::IsValidPostfix(char* Expression){
    // if when operator is processed there is less than 2 elements ERROR
    if(EvaluatePostfix(Expression) == -1) return(0);
    else if(EvaluatePostfix(Expression) == -100001) return(0);
    else return (1);
    // if after processing is done there is more than one element in stack ERROR
}//END IsValidPostfix()

