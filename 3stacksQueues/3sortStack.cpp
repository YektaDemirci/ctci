//Be careful pop() is a void function
#include<iostream>
#include<stack>
using namespace std;

void sort(stack<int> &s){
    stack<int> r;
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        while(!r.empty() && (r.top()>temp) ){
            s.push(r.top());
            r.pop();
        }
        r.push(temp);
    }
    while(!r.empty()){
        s.push(r.top());
        r.pop();
    }
}

int main(){
    stack<int> mystack;
    int arr[] = {6, 4, 8, 9, 10, 99, 7, 1, 100};
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        cout<<"Push in element "<<arr[i]<<endl;
        mystack.push(arr[i]);
    }
    sort(mystack);
    cout<<"The sorted stack is: "<<endl;
    while(!mystack.empty()){
        cout<<mystack.top()<<'\n';
        mystack.pop();
    }
}