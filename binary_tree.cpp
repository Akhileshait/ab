#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left, *right;
    node(int d){
        left=right=NULL;
        data=d;
    }
};

void insert(node* root, int key){
    node* t=new node(key);
    node* temp=root;
    while(1){
        char ch;
        cout<<"Right or left of "<<temp->data;
        cin>>ch;

        if(ch=='l'){
            if(temp->left==NULL){
                temp->left=t;
                return;
            }else{
                temp=temp->left;
            }
        }else if(ch=='r'){
            if(temp->right==NULL){
                temp->right=t;
                return;
            }else{
                temp=temp->right;
            }
        }
    }
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        
        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);
        
        cout<<temp->data<<" ";
    }
} 

void iterative_inorder(node *root){
    stack<node*> st;
    st.push(root);
    node* temp=root;
    while(!st.empty()){
        while(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }

        temp=st.top();
        st.pop();
        
        cout<<temp->data<<" ";
        
            temp=temp->right;
    }
}


void iterative_preorder(node *root){
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        cout<<root->data<<" ";
        st.pop();
        if(root->right!=NULL)st.push(root->right);
        if(root->left!=NULL)st.push(root->left);
    }
}

void postorder_iterative(node* root) 
{ 
    if (root == NULL) 
        return; 
    stack<node*> s1, s2; 

    s1.push(root); 
    node* node; 
  
    while (!s1.empty()) { 
        node = s1.top(); 
        s1.pop(); 
        s2.push(node); 
  
        if (node->left) 
            s1.push(node->left); 
        if (node->right) 
            s1.push(node->right); 
    } 

    while (!s2.empty()) { 
        node = s2.top(); 
        s2.pop(); 
        cout<<node->data << " "; 
    } 
} 
  

int ht(node* root){
    if(root==NULL)
        return 0;
    else{
        int hl=ht(root->left);
        int hr=ht(root->right);
        return (max(hl, hr)+1);
    }
}


node* mirrorimg(node* root, node* temp){
    if(root!=NULL){
        node* x=new node(root->data);
        temp->right=mirrorimg(root->left, temp);
        temp->left=mirrorimg(root->right, temp);
        return x;
    }
    return temp;
}

node* clone(node* root, node* temp){
    if(root!=NULL){
        node* x=new node(root->data);
        temp->right=clone(root->right, temp);
        temp->left=clone(root->left, temp);
        return x;
    }
    return temp;
}

int identicalTrees(node* a, node* b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a != NULL && b != NULL) {
        return (a->data == b->data
                && identicalTrees(a->left, b->left)
                && identicalTrees(a->right, b->right));
    }

    return 0;
}


int main(){
    node* root=new node(10);
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        int k;
        cin>>k;
        insert(root, k);
    }

    cout<<"The inorder traversal of tree is:";
    inorder(root);
    cout<<endl;
    cout<<"The preorder traversal of tree is:";
    preorder(root);
    cout<<endl;
    cout<<"The postorder traversal of tree is:";
    postorder(root);
    cout<<endl;

    cout<<"Level order traversal: ";
    levelorder(root);
    cout<<endl;

     cout<<"The Iterative Preorder traversal of tree is:";
    iterative_preorder(root);
    cout<<endl;

    cout<<"The Iterative inorder traversal of tree is:";
    iterative_inorder(root);
    cout<<endl;

    cout<<"The Iterative Postorder traversal of tree is: ";
    postorder_iterative(root);
    cout<<endl;

    cout<<"Height of the tree is: ";
    cout<<ht(root);
    cout<<endl;

    node* img;
    mirrorimg(root, img);
    node* copy;
    copy=clone(root, copy);
    cout<<"If two trees are identical: "<<identicalTrees(root, copy)<<"\n";
}