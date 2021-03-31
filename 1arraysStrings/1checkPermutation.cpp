#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

//Instead of a hashTable a basic list would also work 

bool checkPerm(string word1, string word2){
    if(word1.length() != word2.length()){
        return false;
    }
    unordered_map<char,int> hashTable;
    for(int i=0; i < word1.length(); i++){
        auto it = hashTable.find(word1[i]);
        if(it == hashTable.end()){
            hashTable.insert({word1[i], 1});
        }
        else{
            it->second = it->second +1;
        }
    }
    for(int i=0; i < word2.length(); i++){
        auto it = hashTable.find(word2[i]);
        if( (it == hashTable.end()) || (it->second==0)){
            return false;
        }
        else{
            it->second = it->second-1;
        }
    }
    return true;
}


int main() {
// Test Method 1 - Using sort
    cout << "Method 1 - Using sort" << endl;
    string str1 = "testest";
    string str2 = "estxest";
    if(checkPerm(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
    if(checkPerm(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;

}

