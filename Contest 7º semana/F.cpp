#include <iostream>
#include <queue>

using namespace std;

int main(){
	queue<char> fila;
	
	for(char c='A'; c<='P'; c++)
		fila.push(c);
	
	for(int i=0; i<15; i++){
		int g1, g2;
		char t1, t2;
		cin >> g1 >> g2;

		t1 = fila.front();
		fila.pop();
		t2 = fila.front();
		fila.pop();
		
		if(g1 > g2){
			fila.push(t1);
		}else{
			fila.push(t2);
		}
	}
	
	cout << fila.front() << endl;

	return 0;
}
