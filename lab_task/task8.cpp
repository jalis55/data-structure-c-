/*
Name:JALIS MAHAMUD TARIF
ID:1521001042
*/




#include <bits/stdc++.h>
using namespace std;

int stk[10];
int top=0;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int key){
        data = key;
        left = NULL;
        right = NULL;

    }
};
Node* insert(Node* root, int key);
void inorder(Node* root);


Node* insert(Node* root, int key){
    if(root==NULL){
        Node* node = new Node(key);
        root = node;
        return root;
    }
    if(root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}
void inorder(Node* root){

    if(root==NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void push(int val){
    stk[top++]=val;

}
int pop(){
    top--;
    return stk[top];
}

int check_prime(int num){
    if(num<=1){
        return false;
    }
    for(int i = 2; i <= num / 2; i++) {
      if(num % i == 0) {

         return false;
      }
    }
   return true;

}


int main(){
    Node* root=NULL;
    //considered raw input
    int data[10]={0,1,2,3,4,5,6,7,8,9};
    for(int i=0;i<10;i++){
        push(data[i]);

    }

    for(int n=10;n>0;n--){
        int val=pop();
        if(check_prime(val)){
            root=insert(root,val);
        }
    }


    cout<<"The BST is(inorder):";
    inorder(root);
    cout << endl;

}


