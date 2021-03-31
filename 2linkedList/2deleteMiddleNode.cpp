#include <iostream>

using namespace std;


struct Node {
	char data = 0;
	Node * next = nullptr;
    Node( char c ) : data{ c }, next{ nullptr } { }
};

void printList( Node * head ) {
	while(head) {
		std::cout << head->data << "-->";
		head = head->next;
    }
}

void delMid(Node * n){
    n->data = n->next->data;
    n->next = n->next->next;
}

int main() {
  Node * head = new Node('a');
  head->next = new Node('b');
  head->next->next = new Node('c');
  head->next->next->next = new Node('d');
  head->next->next->next->next = new Node('e');
  std::cout << "List before deletion:\n";
  printList(head);
  std::cout << "Deleting node containing data as 'c'\n";
  delMid(head->next->next);
  std::cout << "List after deletion:\n";
  printList(head);
  return 0;
}

