#include <iostream>
#include<queue>
using namespace std;

class Node{
	public:
	int data;
	Node* right;
	Node* left;
	
	Node(int d){
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}

void preOrder(Node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node* root){
	if(root == NULL){
		return;
	}
	
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void postOrder(Node* root){
	if(root == NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data << " ";
}

Node* minVal(Node* root){
	Node* temp = root;
	
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

Node* maxVal(Node* root){
	Node* temp = root;
	
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}

Node* deleteFromBST(Node* root, int d){
	if(root == NULL){
		return root;
	}
	
	if(root->data == d){
		//0 child
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}
		
		//1 child
		//left
		if(root->left != NULL && root->right == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		//right
		if(root->left == NULL && root->right != NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		
		//2child
		if(root->left != NULL && root->right != NULL){
			int min = minVal(root->right) -> data;
			root->data = min;
			root->right = deleteFromBST(root->right, min);
			return root;
		}
	}
	else if(root->data>d){
		root->left = deleteFromBST(root->left,d);
	}
	else{
		root->right = deleteFromBST(root->right,d);
	}
}

Node* insertBST(Node* root, int d){
	if(root == NULL){
		root = new Node(d);
		
		return root;
	}
	
	if(d>root->data){
		root->right = insertBST(root->right, d);
	}
	else{
		root->left = insertBST(root->left, d);
	}
	
	return root;
	
}

void takeInput(Node* &root){
	int data;
	cin >> data;
	
	while(data != -1){
		root = insertBST(root,data);
		cin >> data;
	}
}

int main(){
	Node* root = NULL;
	
	cout << "Enter data end with -1" << endl;
	takeInput(root);
	
	cout << "Level Order Traversal:" << endl;
	levelOrderTraversal(root);
	
	cout << "InOrder Traversal:" << endl;
	inOrder(root);
	
	cout << endl << "PreOrder Traversal:" << endl;
	preOrder(root);
	
	cout << endl << "PostOrder Traversal:" << endl;
	postOrder(root);
	
	cout << endl << "Min Value:" << minVal(root) -> data << endl;
	
	cout << endl << "Max Value:" << maxVal(root) -> data << endl;
	
	root = deleteFromBST(root, 10);
	
	cout << "Level Order Traversal:" << endl;
	levelOrderTraversal(root);
	
	cout << "InOrder Traversal:" << endl;
	inOrder(root);
	
	cout << endl << "PreOrder Traversal:" << endl;
	preOrder(root);
	
	cout << endl << "PostOrder Traversal:" << endl;
	postOrder(root);
	
	cout << endl << "Min Value:" << minVal(root) -> data<< endl;
	
	cout << "Max Value:" << maxVal(root) -> data << endl;
		
	return 0;
}
