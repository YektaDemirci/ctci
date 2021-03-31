#include <iostream>
#include <random>
using namespace std;

struct Node {
	int data = 0;
	Node * next = nullptr;
    Node( int c ) : data{ c }, next{ nullptr } { }
};

void insert( Node * & head, int data ) {
  Node * newNode = new Node(data);
  if ( head == nullptr ) {
    head = newNode;
  } else {
    Node * curr = head;
    while( curr->next ) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
}

void printList( Node * head ) {
  while ( head != nullptr ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "nullptr" << std::endl;
}

Node * partition(Node * n, int k){
    Node * smallHead = nullptr;
    Node * smallTail = nullptr;
    Node * largeHead = nullptr;
    Node * largeTail = nullptr;
    while(n != nullptr){
        /* You need to breakup the next of n otherwise smallTail->next will bind next of n to n */
        Node * next = n->next;
        n->next = nullptr;
        if( (n->data) < k){
            if(smallHead == nullptr){
                smallHead = n;
                smallTail = n;
            } else {
                smallTail->next = n;
                smallTail = n;
            }
        } else {
            if(largeHead == nullptr){
                largeHead = n;
                largeTail = n;
            } else {
                largeTail->next = n;
                largeTail = n;
            }
        }
        n = next;
    }
}

//Given solution in ctci but it did not work
/* Node * partition2 (Node * n, int k){
    Node * head = n;
    Node * tail = n;
    while( n != nullptr){
        Node * next = n->next;
        if( (n->data) < k){
            n->next = head;
            head = n;
        } else {
            tail->next = n;
            tail = n;
        }
        n = next;
    }
    tail->next = nullptr;
    return head;
} */

int main() {
  Node * head = nullptr;
  for ( int i = 0; i < 10; ++i ) {
		insert(head, rand() % 9);
	}
  std::cout << "List before partition around 5:\n";
  printList(head);
  std::cout << "List after partition around 5:\n";
  printList(partition(head, 5));
  return 0;
}