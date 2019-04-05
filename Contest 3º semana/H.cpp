#include <iostream>

using namespace std;

char aluno[100];
char gabarito[100];

int main() {
	int acertos = 0;
	int n;
	
	cin >> n;
	cin >> aluno;
	cin >> gabarito;
	
	for(int i=0; i<n; i++){
		if(aluno[i] == gabarito[i])
			acertos++;
	}
	
	cout << acertos << "\n";

	return 0;
}
