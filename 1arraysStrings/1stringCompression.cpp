//Run time is O(p+k^2) where p is the size of the string and k is the numb of char seq because of concenation.
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

string stringCompression(string word){
    char old = word[0];
    int ctr = 1;
    string nWord;
    for(int i=1; i<word.length(); i++){
        if(word[i] != old){
            if(ctr>0){
                nWord = nWord + word[i-1] + to_string(ctr);
            }
            ctr=1;
            old = word[i];
        }
        else{
            ctr++;
        }
    }
    nWord = nWord + word[word.length()-1] + to_string(ctr);
    return nWord.length()<word.length() ? nWord : word;
}


int main()
{
	std::string str, out;
	std::cout << "Enter a string:\n";
	std::cin >> str;
	out = stringCompression(str);
    std::cout << out[out.length()] << endl;
	if (str.compare(out)) {
		std::cout << str << " can be compressed to " << out << std::endl;
	} else {
		std::cout << str << " can not be compressed\n";
	}
	return 0;
}