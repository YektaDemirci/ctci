#include<iostream>
#include <climits>
using namespace std;

struct node{
    int data;
    node *right, *left;
    node (int x) : data(x), left(NULL), right(NULL) {}
};

void createMinimalBst(node* &root, int arr[], int start, int end){
    if(start>end)
        return;
    else{
        int mid = (start+end) / 2;
        node *ptr = new node(arr[mid]);
        root = ptr;
        createMinimalBst(root->left, arr, start, mid-1);
        createMinimalBst(root->right, arr, mid+1, end);
    }
}

bool checkBST(node* root, int &last){
    if(root == nullptr)
        return true;
    if(!checkBST(root->left, last)) return false;
    if( (last != INT_MIN) && (root->data <= last) ) return false;
    last = root->data;
    if(!checkBST(root->right, last)) return false;
    return true;
}


bool isBST(node* root, int min, int max){
    if(root == nullptr){
        return true;
    }
    if(root->data<=min || root->data>max){
        return false;
    }
    if (!isBST(root->left, min, root->data) || !isBST(root->right, root->data, max)){
        return false;
    }
    return true;
}

bool isBST2(node* root, int min, int max){
    if(root==nullptr) return true;
    //Check the current level
    if( (root->data <= min) || (root->data > max) ){
        return false;
    }
    //Check the subtrees
    if( !isBST2(root->left, min, root->data) || !isBST2(root->right, root->data, max) ){
        return false;
    }
    return true;
}

int main(){
    int arr1[] = {1, 2, 3, 4, 15, 6, 7, 8, 9};    //NOT a BST since we assume a sorted   array is provided before we create the BST
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};    //is a BST
    node* root1;
    node* root2;
    root1 = nullptr;
    root2= nullptr;
    createMinimalBst(root1, arr1, 0, 8);
    createMinimalBst(root2, arr2, 0, 8);
    int min = INT_MIN;
    cout<<boolalpha<<checkBST(root1, min) << endl;
    min = INT_MIN;
    cout<<boolalpha<<checkBST(root2, min) << endl;
    cout<<boolalpha<<isBST2(root1, INT_MIN, INT_MAX) << endl;
    cout<<boolalpha<<isBST2(root2, INT_MIN, INT_MAX) << endl;

}