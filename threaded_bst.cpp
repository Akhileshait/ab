#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left, *right;
    bool isthread;
    node(int d){
        left=right=NULL;
        data=d;
        isthread=false;
    }
    
};

void insert(node* root, int key){
    node* temp=root;
    while(1){
        if(key<(temp->data)){
            if(temp->left==NULL){
                temp->left=new node(key);
                return;
            }else{
                temp=temp->left;
            } 
        }else{
            if(temp->right==NULL){
                temp->right=new node(key);
                return;
            }else{
                temp=temp->right;
            }
            
        }
    }
}

vector<node*> inorder(node* root){
    vector<node*> v;
    if(root!=NULL){
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }
    return v;
}

void inorder(node *root, node *previous){

        if(root==nullptr){
            return;
        }else{
            inorder(root->right, previous);
            if(root->right==nullptr &&  previous!=nullptr){
                root->right = previous;
                root->isthread=true;
            }
            inorder(root->left, root);
        }
} ;

node* leftmost(node* root){
    node* temp=root;
    if(temp==NULL){
        return temp;
    }
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

void thread_traverse(node* root){
    node* temp=leftmost(root);
    while(temp!=NULL){

        cout<<temp->data<<" ";
        if(temp->isthread)
            temp = temp->right;
        else 
            temp = leftmost(temp->right);
    }
    cout<<endl;
}

node* search(node* root, int key){
    node* temp=root;
    while(1){
        if(key==temp->left->data || key==temp->left->data){
            return temp;
        }else if(key<(temp->data)){
            temp=temp->left;
        }else if(key>(temp->data)){
            temp=temp->right;
        }
    }
}

void right_insert(node* root, int parent_key, int key){
    node* parent=search(root, parent_key);
    node* child=new node(key);
    child->right=parent->right;
    parent->right=child;
    child->left=parent;
}

int main(){
    node* root=new node(100);
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        int k;
        cin>>k;

        insert(root, k);
    }
    inorder(root, nullptr);
    cout<<"Threaded BST traversal: ";
    thread_traverse(root);
}
