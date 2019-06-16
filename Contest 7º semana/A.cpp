#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;
	
int main(){
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	int ok = true;
	
	//Dá para fazer apenas com um contador ao invés da pilha.
	//Escolhemos a piha pois conseguimos mostrar uma aplicação do mesmo.
	stack<char> pilha;
	
	cin >> n;
	
	string texto;
	
	//Ignorar o \n do número digitado
	cin.ignore();
	while( getline(cin, texto)  ){	
		for(char c: texto){			
			if(c == '{'){
				pilha.push(c);
			}else if(c == '}'){
				if(!pilha.empty()){
					pilha.pop();
				}else{
					ok = false;
					break;
				}
			}			
		}			   		
  	}
	
	if(pilha.size() > 0) 
		ok = false;
	
	if(ok)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	
		 				   				
	return 0;
}   
