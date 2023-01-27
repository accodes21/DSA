#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    //new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp; 
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void print(Node* &head){
    if(head == NULL){
        cout << "List is empty" << endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL){
        cout << temp ->data << " ";
        temp = temp ->next;
    }
    cout << endl;
}

int main(){
    //creating node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
    Node* head = node1; 
    Node* tail = node1;

    insertAtHead(head, 12);
    insertAtTail(tail, 20);

    print(head);

    return 0;
}