#include<iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    node *right, *left;
};

/*Build a BST first, and searching for in-order successor of a given node.*/
void createMinimalBst(node* &root, int arr[], int start, int end){
    if(start>end)
        return;
    if(root==NULL){
        node *ptr = new node;
        int ind = start + (end-start)/2;
        ptr->data = arr[ind];
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
        createMinimalBst(root->left, arr, start, ind-1);
        createMinimalBst(root->right, arr, ind+1, end);
    }
}

node * leftmost(node* node){
    struct node* current = node;

    while(current->left != nullptr)
        current = current->left;
    
    return current;
}

node * inOrderSuccessor(node* root, node* n){
    if(n->right != nullptr)
        return leftmost(n->right);
    
    node* succ = nullptr;
    while(root!= nullptr){
        if( n->data < root->data){
            succ = root;
            root = root->left;
        } else if (n->data > root->data)
            root = root->right;
        else
            break;
    }
    if(succ != nullptr) return succ;
}

//Assume you can access to the parent
node * inOrderSuccessor(node* root){
    if(n->right != nullptr){
        return leftmost(n->right);
    } else {
        node* q = n;
        node* x = q.parent;

        while(x != nullptr && x.left != q){
            q = x;
            x = x.parent;
        }
        return x; 
    }

}



int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    node* root;
    root = NULL;
    createMinimalBst(root, arr, 0, 8);
    node* searchedNode1 = inOrderSuccessor(root, root->left);
    cout<<"Successor found: "<<searchedNode1->data<<'\n';
    node* searchedNode2 = inOrderSuccessor(root, root->right->right->right);
    cout<<"Successor found: "<<searchedNode2->data<<'\n';
}