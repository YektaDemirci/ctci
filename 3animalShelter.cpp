//Be careful pop() is a void function
//Creating two stuff and managing them as 1 is considered as wrapping in Java
#include<iostream>
#include<queue>
#include<string>
using namespace std;

class animal{
private:
    queue<int> cat,dog;
    int order;
public:
    animal(){
        order=1;
    }
    int enque(string a){
        if(a=="dog"){
            dog.push(order);
            order++;
        } else if (a=="cat"){
            cat.push(order);
            order++;
        }
        return order-1;
    }
    int dequeAny(){
        int temp;
        if(dog.front()>cat.front()){
            temp = cat.front();
            cat.pop();
        } else{
            temp = dog.front();
            dog.pop();
        }
        return temp;
    }
    int dequeDog(){
        if(dog.empty()){
            cout << "There is no more dogs" << endl;
        }
        int temp = dog.front();
        dog.pop();
        return temp;
    }
    int dequeCat(){
        if(cat.empty()){
            cout << "There is no more cats" << endl;
        }
        int temp = cat.front();
        cat.pop();
        return temp;
    }
};

int main(){
    animal a;
    cout<<"Shelter received an dog with index "<<a.enque("dog")<<'\n';
    cout<<"Shelter received an cat with index "<<a.enque("cat")<<'\n';
    cout<<"Shelter received an cat with index "<<a.enque("cat")<<'\n';
    cout<<"Shelter received an dog with index "<<a.enque("dog")<<'\n';
    cout<<"Shelter received an cat with index "<<a.enque("cat")<<'\n';
    cout<<"Shelter received an dog with index "<<a.enque("dog")<<'\n';
    cout<<"Shelter received an cat with index "<<a.enque("cat")<<'\n';
    cout<<"Get an animal of any kind. The index is "<<a.dequeAny()<<'\n';
    cout<<"Get a dog. The index is "<<a.dequeDog()<<'\n';
    cout<<"Get a cat. The index is "<<a.dequeCat()<<'\n';
    cout<<"Get a dog. The index is "<<a.dequeDog()<<'\n';
    cout<<"Get a dog. The index is "<<a.dequeDog()<<'\n';
    cout<<"Get a dog. The index is "<<a.dequeDog()<<'\n';
}