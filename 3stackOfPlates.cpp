/*
    Copied as a reference from:
    https://github.com/careercup/CtCI-6th-Edition-cpp/blob/master/Chapter-3-Stacks-and-Queues/3.3_stack_of_plastes
    It is beautifully written
*/
#include<iostream>
#include<stack>
#include<climits>
using namespace std;
#define STACK_NUM 100

class newStack{
private:
    stack<int> *myStack;
    int threshold;
    int curStack;
public:
    newStack(){
        threshold = 10;
        myStack = new stack<int>[STACK_NUM];  //allocates the memory of an array of stacks
        curStack = 0;
    }
    void push(int data){
        if(myStack[curStack].size()>=threshold){
            curStack++;
        }
        myStack[curStack].push(data);
    }
    void pop(){
        if(myStack[curStack].empty()){
            if(curStack == 0){
                cout<<"Current stack is empty\n";
                return;
            }
            curStack--;
        }
        myStack[curStack].pop();
    }
    int top(){
        if(myStack[curStack].empty()){
            if(curStack == 0){
                return INT_MIN;
            }
            curStack--;
        }
        return myStack[curStack].top();
    }
    bool empty(){
        if(curStack == 0){
            return myStack[curStack].empty();
        }
        else
            return false;
    }
    void popAt(int index){
        if(myStack[index].empty()){
            cout<<index<<"th sub-stack is empty"<<'\n';
            return;
        }
        myStack[index].pop();
    }
};

int main(){
    newStack mystack;
    for(int i=0; i<100; i++)
        mystack.push(i);
    cout<<"Pop out one element from 4th stack "<<endl;
    mystack.popAt(4);
    cout<<"Pop out all elements from plates of stack."<<endl;
    for(int i=0; i<101; i++){
        cout<<"Pop out the element: "<<mystack.top()<<endl;
        mystack.pop();
    }
    return 0;
}
