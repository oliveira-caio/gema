#include <bits/stdc++.h>
using namespace std;

void buscab(int chute, int left, int right) {
	int resposta = 0;
	cout << chute << endl;
	fflush(stdout);
	cin >> resposta;
	if (resposta == 1) { // maior
		buscab((chute + right) / 2, chute, right);
	} else if (resposta == 0) { // menor
		buscab((left + chute) / 2, left, chute);
	} else if (resposta == 2) { // acertou
		return;
	}
}

int main() {
	buscab(5, 0, 11);
}
