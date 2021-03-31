#include <string>
#include <iostream>
#include <unordered_map>
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

static inline int random_range(const int min, const int max) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(mt);
}

/* Method with hashmap, O(n) but takes extra space*/
void removeDuplicate( Node * n){
    unordered_map<int, int> map;
    Node * prev = nullptr;
    while( n != nullptr){
        if (map.find(n->data) != map.end()){
            prev->next = n->next;
        }
        else{
            map.insert({n->data,1});
            prev = n;
        }
        n=n->next;
    }
}

/*No extra memory usage but run time is longer*/
void removeDuplicate2( Node * n){
    Node * cur = n;
    while(cur != nullptr){
        Node * runner = cur;
        while(runner->next != nullptr){
            if(cur->data == runner->next->data){
                runner->next = runner->next->next;
            } else {
                runner = runner->next;
            }
        }
        cur = cur->next;
    }
}

int main() {
	std::cout << "Method 1 : \n";
	Node * head = nullptr;
	for ( int i = 0; i < 10; ++i ) {
		insert(head, random_range(1,7));
	}
	printList(head);
    cout << endl;
	removeDuplicate2(head);
	printList(head);
    cout << endl;
}
	