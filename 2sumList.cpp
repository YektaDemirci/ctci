#include <iostream>
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

void printList( Node * head ) {
  while ( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "nullptr" << std::endl;
}

Node * twoSum( Node * num1, Node * num2){
    Node * head;
    Node * cur;
    int carry = 0;
    if(num1 != nullptr && num2 != nullptr){
        int val = num1->data + num2->data + carry;
        Node * temp = new Node(val %10);
        carry = val /10;
        head = temp;
        cur = temp;
        num1 = num1->next;
        num2 = num2->next;
    }    
    while( num1 != nullptr && num2 != nullptr){
        int val = num1->data + num2->data + carry;
        Node * temp = new Node(val %10);
        carry = val/10;
        cur->next = temp;
        cur=temp;
        num1 = num1->next;
        num2 = num2->next;
    }
    return head;
}

/* Recursive implementation, but there is additional input carry */
Node * twoSumRec ( Node * num1, Node * num2, int carry){
    if( num1 == nullptr && num2 == nullptr && carry == 0)
        return nullptr;
    
    int value = carry;
    if(num1 != nullptr)
        value += num1 -> data;
    if(num2 != nullptr)
        value += num2 -> data;
    Node * res = new Node(value % 10);
    if(num1 != nullptr || num2 != nullptr){
        res->next = twoSumRec( num1 == nullptr ? nullptr : num1->next,
                            num2 == nullptr ? nullptr : num2->next,
                            value >= 10 ? 1 :0);
    }
    return res;
}

/* Digits are stored in forward order */
void padList( Node * & list, int padding){
    for(int i=0; i<padding; i++)
        insert(list,0);
}

int length( Node * head) {
  int len = 0;
  while(head) {
    len++;
    head = head->next;
  }
  return len;
}

Node * add_followup_helper( Node * list1, Node * list2, int & carry ) {
  if ( list1 == nullptr && list2 == nullptr && carry == 0 ) {
    return nullptr;
  }

  Node * result = add_followup_helper(list1 ? (list1->next) : nullptr,
                                      list2 ? (list2->next) : nullptr,
                                      carry);

  int value = carry + (list1 ? list1->data : 0 ) + (list2 ? list2->data : 0);
  insert( result, value % 10 );
  carry = ( value > 9 ) ? 1 : 0;
  return result;
}

Node * add_followup( Node * list1, Node * list2 ) {
  int len1 = length(list1);
  int len2 = length(list2);

  //pad the smaller list
  if ( len1 > len2 ) {
    padList( list2, len1 - len2 );
  } else {
    padList( list1, len2 - len1 );
  }
  int carry = 0;
  Node * list3 = add_followup_helper( list1, list2, carry);
  if ( carry ) {
    insert( list3, carry);
  }
  return list3;
}

int main()
{
  //making list 1 for number 617
  Node * list1 = nullptr;
  insert(list1, 6);
  insert(list1, 1);
  insert(list1, 7);
  std::cout << "List1:  ";
  printList(list1);

  //making list2 for number 295
  Node * list2 = nullptr;
  insert(list2, 2);
  insert(list2, 9);
  insert(list2, 5);
  std::cout << "List2:  ";
  printList(list2);

  printList(twoSumRec(list1,list2,0));
}