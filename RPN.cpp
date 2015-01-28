// Author: Arthur Miller
// File Name: RPN.cpp
// Purpose: Stack implementation of Reverse Polition Notation, using Singly Linked List code for ECE304 ExtrCredit1


#include "RPN.h"


// Add a Node to the head (front) of the linked list
void RPN::Push(char data){
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
        int tmp = 0;
        int tmp1 = 0;
        int tmp2 = 0;
        if(Expression[i] == '+'){
            tmp1 = (Head->Data - 48);
            tmp2 = (Head->Next->Data - 48);
            tmp = tmp1 + tmp2;
            //tmp = (Head->Data - 48) + (Head->Next->Data - 48);
            cout << Head->Data << " + " << Head->Next->Data << endl;
            Pop();
            //Print();
            Pop();
            //Print();
            Push(tmp+48);
            Print();
            //return tmp;
        }
        else if(Expression[i] == '*'){
            tmp1 = (Head->Data - 48);
            tmp2 = (Head->Next->Data - 48);
            tmp = tmp1 * tmp2;

            //tmp = (Head->Data - 48) * (Head->Next->Data - 48);
            cout << Head->Data << " * " << Head->Next->Data << endl;
            Pop();
            //Print();
            Pop();
            //Print();
            Push(tmp+48);
            Print();
        }
        else if(Expression[i] == '/'){
            tmp1 = (Head->Data - 48);
            tmp2 = (Head->Next->Data - 48);
            tmp = tmp1 / tmp2;

            //tmp = (Head->Data - 48) / (Head->Next->Data - 48);
            cout << Head->Data << " / " << Head->Next->Data << endl;
            Pop();
            //Print();
            Pop();
            //Print();
            Push(tmp+48);
            Print();
        }
        else if(Expression[i] == '-'){
            tmp1 = (Head->Data - 48);
            tmp2 = (Head->Next->Data - 48);
            tmp = tmp1 - tmp2;

            //tmp = (Head->Data - 48) - (Head->Next->Data - 48);
            cout << Head->Data << " - " << Head->Next->Data << endl;
            Pop();
            //Print();
            Pop();
            //Print();
            Push(tmp+48);
            Print();
        }
        // else it is a number so push onto stack
        // need to add conditional checks for number
        else{
            Push(Expression[i]);
            cout << "Push: " << Expression[i] << endl;
        }
    }
    return (Head->Data - 48);

}//END EvaluatePostfix()
// Check if given Postfix (RPN) expression is valid
bool RPN::IsValidPostfix(char*){

}//END IsValidPostfix()

