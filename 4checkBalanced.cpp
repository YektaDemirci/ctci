#include<iostream>
#include <cmath> 
using namespace std;

struct node{
    int data;
    node *right, *left;
    node (int x) : data(x), left(nullptr), right(nullptr) {}
};

int max(int x, int y){
    return (x>=y) ? x : y;
}

void createMinimalBst(node* &root, int arr[], int start, int end){
    if(start>end)
        return;
    if(root=nullptr){
        int mid = (start+end)/2;
        node *ptr = new node(arr[mid]);
        root=ptr;
        createMinimalBst(root->left, arr, start, mid-1);
        createMinimalBst(root->right, arr, mid+1, end);
    }
}

//////////////////Solution 1////////////// Runs N*log(N) where N is the node number
int getHeight(node* root){
    if(root == nullptr) return -1;
    else{
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
}

bool isBalanced(node* root){
    if(root == nullptr)
        return true;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    if ( abs(left-right)<=1 && isBalanced(root->right) && isBalanced(root->left) )
        return true;
    else return false;
}

//////////////////Solution 2////////////// Runs N
int isBalanced2(node* root){
    if (root == nullptr)
        return -1;
    int left = isBalanced2(root->left);
    if (left == -100) return -100;

    int right = isBalanced2(root->right);
    if (right == -100) return -100;

    int dif = left-right;
    if( abs(dif)>1) return -100;
    else max(left,right)+1;
}



int main(){
    int arr[] = {2, 2, 3, 4, 5, 6, 7, 8, 9};    //is BST
    node* root;
    root = NULL;
    createMinimalBst(root, arr, 0, 8);
    if(isBalanced(root))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");
    
    if(isBalanced2(root) == -100)
        cout << "Tree is not balanced" << endl;
    else
        cout << "Tree is balanced" << endl;
    return 0;


}