//Hashmap solution takes O(N) time, there can be at most 1 odd letter
//A bitmap solution may take less space
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

bool palindrome(string inp){
    unordered_map<char, int> m;
    char c;
    int odd=0;
    for(int i=0; i<inp.length(); i++){
        c = tolower(inp[i]);
        if(c != ' '){
            auto it = m.find(c);
            if(it != m.end()){
                it->second = (it->second)+1;
                if(it->second % 2 == 1){
                    odd++;
                }
                else{
                    odd--;
                }
            }
            else{
                m.insert({c,1});
                odd++;
            }
        }
    }
    if(odd>1)
        return false;
    else
        return true;
}

int main()
{
    std::string str("Tact Coa");
    std::cout << "Approach 1:" << palindrome( str ) << std::endl;


    std::string str1("A big Cat");
    std::cout << "Approach 1:" << palindrome( str1 ) << std::endl;


    std::string str2("Aba cbc");
    std::cout << "Approach 1:" << palindrome( str2 ) << std::endl;
    return 0;
}