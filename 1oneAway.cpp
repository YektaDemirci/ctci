//You can actually merge check1 and check2 to make code less longer
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

bool check1(string l, string s){
    int ctr = 0;
    for(int i=0; i<l.length(); i++){
        if(l[i]==s[i]){
            continue;
        }
        else{
            ctr++;
        }
    }
    return (ctr<2) ? true : false;
}

bool check2(string l, string s){
    int j=0, ctr=0;
    for(int i=0; i<l.length();i++){
        if(l[i]==s[j]){
            j++;
        }
        else{
            ctr++;
            if(ctr>1){
                break;
            }
        }
    }
    return (ctr<2) ? true : false;
}

bool oneAway(string word1, string word2){
    if (word1.length() == word2.length())
        return check1(word1,word2);
    else if (word1.length() > word2.length()){
        return check2(word1,word2);
    } else{
        return check2(word2,word1);
    }
}

void translate( bool result, const std::string str1, const std::string str2 )
{
    if (result == true ) {
        std::cout << str1 << " and " << str2 << " 1\n";
    } else {
        std::cout << str1 << " and " << str2 << " 0\n";
    }
}

int main()
{
    translate ( oneAway("pale", "ple"), "pale", "ple" );
    translate ( oneAway("pales", "pale"), "pales", "pale" );
    translate ( oneAway("pale", "pales"), "pale", "pales" );
    translate ( oneAway("pale", "bale"), "pale", "bale" );
    translate ( oneAway("pale", "bake"), "pale", "bake" );
    return 0;

}


