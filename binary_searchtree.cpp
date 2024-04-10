#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int d){
        left=right=NULL;
        data=d;
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

void preorder(node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
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

node* deletenode(node* root, int key){
    if (root == NULL) return root;

  // Find the node to be deleted
    if (key < root->data)
        root->left = deletenode(root->left, key);
    else if (key > root->data)
        root->right = deletenode(root->right, key);
    else {
        if (root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }
    node *temp;
    while (temp && temp->left != NULL)
        temp = temp->left;

    root->data = temp->data;

    root->right = deletenode(root->right, temp->data);
  }
  return root;
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



int main(){
    node* root=new node(100);
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

    cout<<"Height of the tree is: ";
    cout<<ht(root);
    cout<<endl;


    int g;
    cout<<"Enter the node that you want to delete: ";
    cin>>g;

}