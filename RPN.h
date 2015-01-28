#ifndef __SSL_H_INCLUDED__   // if x.h hasn't been included yet...
#define __SLL_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <iostream>
#include <cstring>
using namespace std;


// Node for the Linked List
class Node{
        public:
            char Data;
            Node *Next;
            // Constructor
            Node(char el, Node *ptr = 0){
                 Data = el;
                 Next = ptr;
            }
}; // end class Node

// Linked List: used to form and edit linked list data structure
class RPN{
    private:
        Node *Head; // starting node
        Node *Tail; // last node
    public:
        // Constructor
        RPN(){
            Head = 0;
            Tail = 0;
        }
        // Destructor
        /*~RPN(){
            for(Node *p; !IsEmpty();){
                p = Head->Next;
                delete Head;
                Head = p;
            }


            while(!IsEmpty()){
                Node *p = Head->Next;
                delete Head;
                Head = p;
            }
        }*/

        // Methods
        bool IsEmpty(){
            return Tail==0;
        }
        // Stack Methods
        void Push(char data);
        void Pop();
        void Print(); // print out fill list
        // RPN Methods

        // Convert Infix notation to Postfix (RPN) notation
        void InfixToPostfix(char []);
        // Check if valid Infix expression
        bool IsValidInfix(char []);
        // Evaluate given Postfix (RPN) expression
        int EvaluatePostfix(char []);
        // Check if given Postfix (RPN) expression is valid
        bool IsValidPostfix(char []);

};
#endif
