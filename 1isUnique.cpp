#include <string>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

bool isUnique(const string str){
		if (str.length() > 128){
			return false;
		}
		vector<bool> char_set(128);
		for (int i = 0; i < str.length(); i++){
			int val = str[i];
			if (char_set[val]){
				return false;
			}
			char_set[val] = true;
		}
		return true;
}

bool isUniqueUp(const string str){
    if (str.length()> 128) {
        return false;
    }
    bitset<256> bits(0);
    for(int i=0; i< str.length(); i++) {
        int val = str[i];
        if(bits.test(val) > 0){
            return false;
        }
        bits.set(val);
    }
    return true;
}

int main(){
		vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
		for (auto word : words)
		{
			cout << "1st test" << word << string(": ") << boolalpha << isUnique(word) <<endl;
		}
        for (auto word : words)
		{
			cout <<"2nd test" << word << string(": ") << boolalpha << isUniqueUp(word) <<endl;
		}
}