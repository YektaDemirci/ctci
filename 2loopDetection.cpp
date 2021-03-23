#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

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

Node * loopDetection1(Node * head){
    unordered_map<Node*, bool> visited;
    while( visited.find( head ) == visited.end() ){
        visited.insert({head,1});
        head=head->next;
    }
    cout << head << endl;
    return head;
}

/* Slow is k away to the loop, fast is k into the loop. K = mod(n, loop_size) 
loop_size - K difference. Fast moves 2*(loop_size-K) in the meantime.
It was already K into it, after 2*(loop_size-K) move it is K before the beginning of the loop.
After meeting if you move from the head and meet again, that is the beginning of the loop
*/
Node * loopDetection2(Node * head){
    Node * slow = head;
    Node * fast = head;

    while(fast != nullptr && slow != nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    }
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return fast;
}



int main()
{
    Node * head = nullptr;
    insert( head , 1 );
    insert( head , 2 );
    insert( head , 3 );
    insert( head , 4 );
    insert( head , 5 );
    std::cout << "Current List:\n";
    printList( head );
    std::cout << "Inserting loop, connecting 1 to 4 \n";
    head->next->next->next->next->next = head->next;
    cout << loopDetection2(head)->data << endl;
    return 0;

}