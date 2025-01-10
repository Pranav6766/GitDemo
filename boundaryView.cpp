
//BFS traversals

#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};
void leftB(Node *root){
    if(root==nullptr) return;
    if(root->left==nullptr and root->right==nullptr) return;
    cout<<root->val<<" ";
    leftB(root->left);
    if(root->left==nullptr) leftB(root->right);
}
void leafN(Node *root){
    if(root==nullptr) return;
    if(root->left==nullptr and root->right==nullptr) {
        cout<<root->val<<" ";
        return;
    }
    leafN(root->left);
    leafN(root->right);
}
void rightB(Node *root){
    if(root==nullptr) return;
    if(root->left==nullptr and root->right==nullptr) return;
    rightB(root->right);
    if(root->right==nullptr) rightB(root->left);
    cout<<root->val<<" ";
}
int main (){
    Node* a=new Node(1);//root node
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);
    Node* h=new Node(8);
    Node* i=new Node(9);
    Node* j=new Node(10);
    Node* k=new Node(11);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f; 
    c->right=g;
    d->left=h;
    e->left=i;
    e->right=j;
    g->left=k;
    
    //boundary view
    //left+leaf+right

    //1.left
    leftB(a);
    //2.leaf
    leafN(a);
    //3.right
    rightB(a->right);
    return 0;
}