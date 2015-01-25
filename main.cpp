// Author: Arthur Miller
// File Name: RPN.cpp
// Purpose: Stack implementation of Reverse Polition Notation, using Singly Linked List code for ECE304 ExtrCredit1


#include <iostream>

using namespace std;

// Node for the Linked List
class Node{
        public:
            int Data;
            Node *Next;
            // Constructor
            Node(int el, Node *ptr = 0){
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
            Head = NULL;
            Tail = NULL;
        }
        // Destructor
        ~RPN(){
            for(Node *p; !IsEmpty();){
                p = Head->Next;
                delete Head;
                Head = p;
            }
            /*

            while(!IsEmpty()){
                Node *p = Head->Next;
                delete Head;
                Head = p;
            }*/
        }

        // Methods
        int IsEmpty(){
            return Tail==0;
        }
        // Stack Methods
        void Push(int data);
        void Pop();
        void Print(); // print out fill list
        // RPN Methods




};


int main()
{
    RPN L1;
    cout << "IsEmpty: " << L1.IsEmpty() << endl;
    L1.Push(1);
    cout << "IsEmpty: " << L1.IsEmpty() << endl;
    L1.Pop();
    cout << "IsEmpty: " << L1.IsEmpty() << endl;
    L1.Push(2);
    cout << "IsEmpty: " << L1.IsEmpty() << endl;
    L1.Push(3);
    L1.Push(4);
    L1.Push(5);
    L1.Push(6);
    L1.Push(7);
    L1.Print();
    L1.Pop();
    L1.Print();
    L1.Pop();
    L1.Print();
    L1.Pop();
    L1.Print();
    L1.Pop();
    L1.Print();
    cout << "IsEmpty: " << L1.IsEmpty() << endl;
    L1.Pop();
    L1.Print();
    cout << "IsEmpty: " << L1.IsEmpty() << endl;
    L1.Pop();
    L1.Print();
    cout << "IsEmpty: " << L1.IsEmpty() << endl;
    L1.Pop();
    L1.Print();
    cout << "IsEmpty: " << L1.IsEmpty() << endl;
    L1.Pop();
    L1.Print();



    return 0;
}

// Add a Node to the head (front) of the linked list
void RPN::Push(int data){
    Head = new Node(data, Head);
    if(Tail == 0)
        Tail = Head;
} // END Push()
// Remove Node from head of linked list
void RPN::Pop(){

    if (Head == NULL && Tail == NULL){
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
