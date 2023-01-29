#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this ->data = data;
        this ->next = NULL;
    }
};

Node* reverseLL(Node* head){
    if(head == NULL || head ->next ==NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr ->next;
        curr ->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;

}