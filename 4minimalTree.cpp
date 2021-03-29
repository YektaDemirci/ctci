#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
 };

void preOrder(Node *node)
{
	if(node == nullptr)
        return ;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}


Node *createMinimalBST(vector<int> arr, int low, int end){
    if(end<low){
        return nullptr;
    }
    int mid = (end+low)/2;
    Node * node = new Node(arr[mid]);
    node->left = createMinimalBST(arr, low, mid-1);
    node->right = createMinimalBST(arr, mid+1, end);
    return node;
}

Node *createMinimalBST(vector<int> arr)
{
    if (arr.size() == 0)
        return nullptr;
    return createMinimalBST( arr, 0, (arr.size()) - 1 );
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << A << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(A[0]) << endl;

    //A way to convert from int array to int vector
    vector<int> arr (A, A + sizeof(A) / sizeof(A[0]) );
    /*
        Convert List to BST {1,2,3,4,5,6,7}
                         4
                      /     \
                    2         6
                  /   \     /   \
                 1     3   5     7
    */
    Node *root = createMinimalBST(arr);
    cout<<"\nPreOrder Traversal of constructed BST : ";
    preOrder(root);

    return 0;
}