#include <iostream>
#include <random>

using namespace std;

struct Node {
	int data = 0;
	Node * next = nullptr;
};

void insert( Node * & head, int data )
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

void printList( Node * head ) {
	while(head) {
		std::cout << head->data << "-->";
		head = head->next;
    }
}

/* Recursive */
Node * rec(Node * n, int k, int & i){
    if(n == nullptr){
        return nullptr;
    }
    Node * temp = rec(n->next, k, i);
    i++;
    if(i==k){
        return n;
    }
    return temp;
}

Node * rec(Node * n, int k){
  int i = 0;
    return rec(n, k, i);
}

/* Iterative */
Node * it(Node * n, int k){
  Node * first = n;
  Node * second = n;
  for(int i = 0; i<k; i++){
    second=second->next;
  }
  while(second != nullptr){
    first = first->next;
    second = second->next;
  }
  return first;
}


int main() {
  Node * head = nullptr;
  for ( int i = 7; i > 0; i-- ) {
    insert(head, i+1);
  }
  std::cout << "List: ";
  printList(head);
  cout << endl;

  std::cout << "4th node from last (Recursive) : ";
  Node *node4 = it(head, 4);
  if ( node4 != nullptr ) {
    std::cout << node4->data << std::endl;
  } else {
    std::cout << "NULL NODE\n";
  }

  return 0;
}
