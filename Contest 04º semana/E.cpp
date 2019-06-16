#include <iostream>

using namespace std;

//Transforma uma letra minuscula em maiuscula
char toUpper(char c){
	if( (c >= 'a') and (c <= 'z') )
		return 'A' + (c-'a');

	return c;
}

//Transforma uma letra maiuscula em minuscula
char toLower(char c){
	if( (c >= 'A') and (c <= 'Z') )
		return 'a' + (c-'A');

	return c;
}

string title(string s){
	s[0] = toUpper(s[0]);

	for(int i=1; i<(int)s.size(); i++){
		if(s[i-1] == ' ')
			s[i] = toUpper(s[i]);
		else
			s[i] = toLower(s[i]);
	}
	
	return s;
}

int main(){ 
    string s;

    getline(cin, s);

    cout << title(s) << "\n";

    return 0;
}
