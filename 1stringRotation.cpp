#include <string>
using namespace std; 

bool stringRot(string s1, string s2){
    if(s1.length() ==0 || s1.length() != s2.length() )
        return false;
    string concat = s1 + s1;
    if ( concat.find(s2) != string::npos )
		return true;
	else
		return false;
}

int main() {
	std::string s1, s2;
	std::cout << "Enter string 1 : ";
	std::cin >> s1;
	std::cout << "Enter string 2 : ";
	std::cin >> s2;
	if ( stringRot(s1, s2) ) {
		std::cout << "Yes! " << s2 << " is rotation of " << s1 << std::endl;
	} else {
		std::cout << "No! " << s2 << " is not a rotation of " << s1 << std::endl;
	}
	return 0;
}

