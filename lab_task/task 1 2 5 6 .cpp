/*
Name:JALIS MAHAMUD TARIF
ID:1521001042
*/

#include<iostream>

using namespace std;

class BST{
    struct Node{
        Node *left;
        int value;
        Node *right;
    };

private:
    Node * root;
    int total;


public:
    BST();
    ~BST();
    void addNode(Node *&base, int num);
    void addValue(int num);
    void printNode(Node *&base);
    void show();
    bool findNode(Node *&base, int num);
    bool retreiveItem(int num);
    void totalVal();
    int find_min(Node *&base);

    bool update_node_val(Node *&base,int num,int up_val);///task-6
    void update_val(int num,int up_val);///task-6
    void rebuild_tree();//task-6
    void new_tree_data(Node *&base1,Node *&base2);

    int all_nodes(Node *&base);///task-5
    void sum_of_nodes();///task-5


    int depth(Node *&base);///task-2
    void height();///task-2

    void min_val();
    void del_match(Node *&parent,Node *&match,bool left);///task-1
    void del_root_match();///task-1
    void del_node(Node *&base,int num);///task-1
    void del_key(int key);///task-1

};

BST:: BST(){
root = NULL;
total = 0;
}

BST:: ~BST(){
//cout<<"DIE"<<endl;
}

void BST:: addNode(Node *&base, int num){

    if(base==NULL){
      base = new Node;
      base->left = NULL;
      base->right = NULL;
      base->value = num;
      total+=1;
      //cout<< base->value<<" "<<endl;
    }
    else if(num<=base->value){
        addNode(base->left, num);
    }
    else {
        addNode(base->right, num);
    }


}

void BST:: addValue(int num){

        addNode(root, num);

}

void BST:: printNode(Node *&base){

    if(base==NULL){
                    return;
    }
    else{
        cout<< base->value<<" ";
        printNode(base->left);
        printNode(base->right);
    }
}

void BST:: show(){
    printNode(root);

}

void BST:: totalVal(){
    cout<<"Total value is:  "<<total<<endl;
}

bool BST:: findNode(Node *&base, int num){
    if(base->value==num){
        cout<<"YEP"<<endl;
        return true;
    }
    else if(num<base->value){
            if(base->left!=NULL)
                return findNode(base->left,num);
    }
    else if(num>base->value){
            if(base->right!=NULL)
                return findNode(base->right,num);
    }

         cout<<"Nope";
        return false;

}

 bool BST:: retreiveItem(int num){
    return findNode(root, num);


 }
int BST::find_min(Node *&base){
    if(base==NULL){
        return -1000;
    }
    else{
        if(base->left !=NULL){
            return find_min(base->left);
        }
        else{
            return base->value;
        }
    }

}
void BST::min_val(){
    int min_val=find_min(root);
    //cout<<"invoke"<<endl;
    cout<<min_val<<endl;
}
///task-6 update node value


void BST::new_tree_data(Node *&base1,Node *&base2){
    if(base2==NULL){
                    return;
    }
    else{

        addNode(base1,base2->value);
        printNode(base2->left);
        printNode(base2->right);
    }


}
void BST::rebuild_tree(){
    Node *new_node=NULL;
    new_tree_data(new_node,root);
    root=new_node;

}

bool BST::update_node_val(Node *&base,int num,int up_val){
        if(base->value==num){
            base->value=up_val;
            return true;
            }
    else if(num<base->value){
            if(base->left!=NULL)
                return update_node_val(base->left,num,up_val);
    }
    else if(num>base->value){
            if(base->right!=NULL)
                return update_node_val(base->right,num,up_val);
    }


        return false;

}
void BST::update_val(int num,int up_val){
    if(update_node_val(root,num,up_val)==true){
            cout<<"updated"<<endl;
            rebuild_tree();

    }
    else{
        cout<<"value not found"<<endl;
    }
}

///task-5 sum of nodes


int BST::all_nodes(Node *&base){
    if(base==NULL){

        return 0;
    }
    return (base->value+all_nodes(base->left)+all_nodes(base->right));

}

void BST::sum_of_nodes(){
    int sum=all_nodes(root);
    cout<<"sum of all node is:"<<sum<<endl;

}

///task-2 finding depth

int BST::depth(Node *&base){
    if(base == NULL){
        return 0;
    }
    int lheight = depth(base->left); // height of the left child
    int rheight = depth(base->right); // height of the right child
    int maxheight;
    if(lheight>=rheight)
        maxheight = lheight;
    else{
        maxheight = rheight;
    }
    return maxheight+1;


}

void BST::height(){
    int h=depth(root);
    cout<<"Depth is:"<<h<<endl;
}

///Task-1 deleing node
 void BST::del_match(Node *&parent,Node *&match,bool left){
     Node* temp;
     int match_key=match->value;
     int sml_right_sub_tree;
     if(match->right==NULL && match->left==NULL){
        temp=match;
        left==true ? parent->left=NULL : parent->right=NULL;
        delete temp;

     }
     else if(match->left ==NULL && match->right !=NULL){
            left==true ? parent->left =match->right : parent->right=match->right;
            match->right=NULL;
            delete temp;

     }
     else if(match->left !=NULL && match->right ==NULL){
            left==true ? parent->left =match->left : parent->right=match->left;

            match->left=NULL;
            delete temp;

     }
     else{
        sml_right_sub_tree=find_min(match->right);
        match->value=sml_right_sub_tree;

     }

 }
void BST::del_root_match(){
    if(root !=NULL){
        Node* temp=root;
        int root_key=root->value;
        int sml_rgt_sub_tree;
            ///case 0-0 child
        if(root->left ==NULL & root->right==NULL){
        root=NULL;
        delete temp;
        }
        else if(root->left==NULL && root->right !=NULL){
        root=root->right;
        temp->right=NULL;
        delete temp;
        }
        else if(root->right ==NULL && root->left !=NULL){
        root=root->left;
        temp->left=NULL;
        delete temp;
        }
        else{
        sml_rgt_sub_tree=find_min(root->right);
        del_node(root,sml_rgt_sub_tree);
        root->value=sml_rgt_sub_tree;
        }
    }
        else{
        cout<<"Tree is empty"<<endl;
    }
}
void BST::del_node(Node *&base,int num){
    if(base !=NULL){
        if(base->value==num){
            del_root_match();
        }
        else{
            if(num < base->value && base->left!=NULL){
                    if(base->left->value==num){
                        del_match(base,base->left,true);
                    }
                    else{
                        del_node(base->left,num);
                    }



            }
            else if(num < base->value && base->right!=NULL){
                    if(base->right->value==num){
                        del_match(base,base->right,true);
                    }
                    else{
                        del_node(base->right,num);
                    }



            }
            else{
                cout<<"key not found";
            }
        }
    }
    else{
        cout<<"Empty Tree"<<endl;
    }


}

void BST::del_key(int key){
    del_node(root,key);
}


int main(){

BST bst;

bst.addValue(5);
bst.addValue(10);
bst.addValue(15);
bst.addValue(25);
bst.addValue(3);
bst.addValue(1);


bst.show();
cout<<endl;

///del key
bst.del_key(1);///task1

cout<<"after delete a node"<<endl;
bst.show();
cout<<endl;
bst.height();///task2
bst.sum_of_nodes();///task5

///task6
bst.update_val(15,6);///here 15 node value and 6 new value
bst.show();



}
