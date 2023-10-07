#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* createTree(node* root){
    cout<<"Enter data" <<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data to left of " <<data<<endl;
    root->left = createTree(root->left);
    cout << "Enter data to right of " <<data<<endl;
    root->right = createTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inOrder(node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data <<endl;
    inOrder(root->right);
}

void preOrder(node* root){
    if(root == NULL){
        return;
    }

    cout << root->data <<endl;
    preOrder(root->left);
    preOrder(root->right);

}

void postOrder(node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data <<endl;
}

int main(){
    node* root = NULL;

    root = createTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    cout << "Level Order Traversal is:";
    levelOrderTraversal(root);

    cout<<"InOrder Traversal is:";
    inOrder(root);

    cout<<"PreOrder Traversal is:";
    preOrder(root);

    cout<<"PostOrder Traversal is:";
    postOrder(root);
}