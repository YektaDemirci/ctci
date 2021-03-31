#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
	int data = 0;
	Node * next = nullptr;
    Node( int c ) : data{ c }, next{ nullptr } { }
};

void insert( Node * & head, int data ) {
  Node * newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

void printList( Node * head )
{
  while( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}

//As another option, you can find the length then chop off the difference.
//Then start from the head and find the intersection point

Node * intersection( Node * first, Node * second){
    Node * headSec = second;
    unordered_map <Node*, bool> visited;
    while(second != nullptr){
        if(second == first){
            return second;
        } else{
            visited.insert({second,true});
            second = second->next;
        }
    }
    first=first->next;
    while(first != nullptr){
        if(visited.find(first) != visited.end()){
            return first;
        } else{
            first=first->next;
        }
    }
    return nullptr;
}


int main()
{
  Node * list1 = new Node(3);
  list1->next = new Node(6);
  list1->next->next = new Node(9);
  list1->next->next->next = new Node(12);
  list1->next->next->next->next = new Node(15);
  list1->next->next->next->next->next = new Node(18);

  Node * list2 = new Node(7);
  list2->next = new Node(10);
  list2->next->next = list1->next->next->next;

  printList(list1);
  printList(list2);

  Node * intersectingNode = intersection( list1 , list2 );
  if (intersectingNode) {
    std::cout << "Intersecting Node of lists is :" << intersectingNode->data << std::endl;
  } else {
    std::cout << "Lists do not interset" << std::endl;
  }

  int A[10];
  cout << sizeof(A);
  return 0;
}