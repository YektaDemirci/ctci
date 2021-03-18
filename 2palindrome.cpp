#include <iostream>
#include <deque>
using namespace std;


struct Node {
	char data = 0;
	Node * next = nullptr;
    Node( char c ) : data{ c }, next{ nullptr } { }
};

/* Inserting to the head */
void insert( Node * & head, int data ) {
  Node * newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

void printList( Node * head ) {
  while ( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "nullptr" << std::endl;
}

/* Using a queue */
bool palindrome(Node * n){
    deque<char> queue;
    int ctr = 0;
    Node * head = n;
    while(n != nullptr){
        queue.push_front(n->data);
        n = n->next;
    }
    while(head != nullptr){
        if(queue.front() == head->data){
            queue.pop_front();
            head=head->next;
        } else{
            return false;
        }
    }
    return true;
}

/* Using a stack (faster than queue) */

bool palindrome3(Node * n){
    Node * slow = n;
    Node * fast = n;
    deque<char> stack;
    
    while(fast != nullptr && fast->next != nullptr){
        stack.push_back(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast != nullptr)
        slow = slow->next;

    while(slow != nullptr){
        if(stack.back() == slow-> data){
            stack.pop_back();
            slow = slow->next;
        } else{
            return false;
        }
    }
    return true;
}

/* Using a queue */
bool palindrome2(Node * n){
    Node * h1 = n;
    Node * h2 = nullptr;
    int ctr = 0;
    while(n != nullptr){
        Node * temp = new Node (n->data);
        temp -> next = h2;
        h2 = temp;
        n = n->next;
    }
    while(h1 != nullptr){
        if(h1->data == h2->data){
            h1 = h1->next;
            h2 = h2->next;
        } else
            return false;
    }
    return true;
}

/* Checks the same stuff twice */
/*You need to send the left by ref, because it is being changed */
bool palinrec( Node * & left, Node * right){
    if(right == nullptr){
        return true;
    }
    bool isPal = palinrec(left, right->next);
    if (!isPal){
        return false;
    }
    isPal = (left->data == right->data);
    left=left->next;
    return isPal;
}


bool palindrome4(Node * n){
    return palinrec(n,n);
}

int main()
{
  Node * head1 = nullptr;
  insert( head1, 'a' );
  insert( head1, 'b' );
  insert( head1, 'c' );
  insert( head1, 'c' );
  insert( head1, 'b' );
  insert( head1, 'a' );

  std::cout << "List 1: ";
  printList(head1);
  if ( palindrome4(head1) ) {
    std::cout << "List 1 is pallindrome list\n";
  } else {
    std::cout << "List 1 is not a pallindrome list\n";
  }
  std::cout << "List 1: ";
  printList(head1);
}