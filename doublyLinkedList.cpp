#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this ->data = d;
        this ->next = NULL;
        this ->prev = NULL;
    }

    ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp ->data << " ";
        temp = temp ->next;
    }
    cout << endl;
}

void insertAtHead(Node* &tail, Node* &head, int d){
    //empty list
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp ->next = head;
        head ->prev = temp;
        head = temp; 
    }
}

void insertAtTail(Node* &tail, Node* &head, int d){
    //empty list
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail ->next = temp;
        temp ->prev = tail;
        tail = temp;
    }
}

void insertNode(Node* &tail, Node* &head, int pos, int d){
    //insert start
    if(pos==1){
        insertAtHead(tail, head, d);
        return ;
    }

    Node* temp = head;
    int c = 1;
    while(c < pos-1){
        temp = temp ->next;
        c++;
    }

    //insert at end
    if(temp -> next == NULL){
        insertAtTail(tail, head, d);
        return ;
    }

    //creating a new node
    Node* nodetoInsert = new Node(d);
    nodetoInsert -> next = temp ->next;
    temp ->next->prev = nodetoInsert;
    temp ->next = nodetoInsert;
    nodetoInsert ->prev = temp;
}

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}

int main(){
    //Node* node1 = new Node(10);
    Node* head  = NULL;
    Node* tail  = NULL;
    
    insertNode(tail, head, 1, 1);
    print(head);

    insertAtHead(tail, head, 12);
    print(head);

    insertAtTail(tail, head, 15);
    print(head);

    insertNode(tail, head, 2, 30);
    print(head);

    insertNode(tail, head, 1, 10);
    print(head);

    return 0;
}