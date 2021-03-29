#include<iostream>
#include<vector>
#include<list>
using namespace std;

struct Node{
    int data;
    Node *right, *left;
    Node (int x) : data(x), left(NULL), right(NULL) {}
};

void preOrder(Node * node)
{
	if(node == nullptr){
        return;
    }
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void createMinimalBST(Node* &root, vector<int> arr, int start, int end){
    if(start>end){
        return;
    }
    if(root == nullptr){
        int mid = (start+end)/2;
        Node *ptr = new Node(arr[mid]);
        root=ptr;
        createMinimalBST(root->left, arr, start, mid-1);
        createMinimalBST(root->right, arr, mid+1, end);
    }
}

void findLevelLinkedList(vector<list<Node*>> &res, Node * root){
    list<Node*> li;
    li.push_back(root);
    res.push_back(li);
    int depth=0;
    while(!res[depth].empty()){
        list<Node*> l;
        list<Node*>::iterator iter;
        for(iter = res[depth].begin(); iter!=res[depth].end(); iter++ ){
            //Be careful, the ptr poiner needs to access inside iter so *iter is used
            Node *ptr = *iter;
            if(ptr->left)
                l.push_back(ptr->left);
            if(ptr->right)
                l.push_back(ptr->right);
        }
        res.push_back(l);
        depth++;
    }
}

void printLevelLinkedList(vector<list<Node*>> res){
    int depth = 0;
    while(!res[depth].empty()){
        list<Node*>::iterator it;
        for(it=res[depth].begin(); it!=res[depth].end(); it++){
            Node* ptr = *it;
            cout << (*it)->data << " ";
        }
        depth++;
        cout << endl;
    }
}



int main(){
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> arr (A, A + sizeof(A)/sizeof(int));
    Node * root = nullptr;
    //Don't forget size()-1 in the following
    createMinimalBST(root, arr, 0, arr.size()-1);
    vector<list<Node*>> llist;
    findLevelLinkedList(llist,root);
    preOrder(root);
    cout << "list is created" << endl;
    printLevelLinkedList(llist);
}


//Cool way to print out, setw appends space before the variable
/* void postorder(node* p, int indent=0)
{
    if(p != NULL) {
        if(p->right) {
            postorder(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->data << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postorder(p->left, indent+4);
        }
    }
}
*/