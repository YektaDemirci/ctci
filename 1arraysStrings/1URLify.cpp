#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

void URLify(char *str, int len){
    int spaces = 0;
    int i=0, j=0;
    for( i=0; i<len; i++){
        if(str[i] == ' ')
            spaces++;
    }
    int extended = len + 2*spaces;
    i = extended-1;
    for(j=len-1; j>=0; j--){
        if( str[j] != ' '){
            str[i--] = str[j];
        } else{
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    }
}



//Failed solution because I did not properly check the input type
//I was also considering if there could be whitespace within the actual words like Mr   John    Smith
/* void URLify(string word){
    int flag=0;
    int letter=0;
    for(auto it=word.begin(); it!=word.end(); it++){
        if(*it == ' '){
            flag=1;
            word.erase(letter,1);
        } else{
            letter++;
            if(flag==1){
                word.insert(letter,"%20");
                flag=0;
            }
            
        }
    }
} */

int main()
{
    char str[] = "Mr John Smith    ";                       //String with extended length ( true length + 2* spaces)
    std::cout << "Actual string   : " << str << std::endl;
    URLify(str, 13);                                        //Length of "Mr John Smith" = 13
    std::cout << "URLified string : " << str << std::endl;
    return 0;
}