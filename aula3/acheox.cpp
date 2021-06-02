#include <bits/stdc++.h>
using namespace std;

int buscab(int *v, int n, int busca, int *menor) {
	int left = 0, right = n, chute = 0, middle = 0;

	while (left < right) {
		middle = (left + right) / 2;
		chute = v[middle];

		if (chute == busca) {
			return chute;
		} else if (chute < busca) {
			if ((middle+1 < n) && (v[middle+1] >= busca)) {
				*menor = chute;
				return v[middle+1];
			}
			left = middle + 1;
		} else {
			if ((0 <= middle-1) && (v[middle-1] <= busca)) {
				*menor = v[middle-1];
				return chute;
			}
			right = middle - 1;
		}
		
		*menor = chute;
	}

	return chute;
}
	
int main() {
	int n, m, tmp = 0;

	cin >> n >> m;

	int vetor[n];
	int queries[m];
	
	for (long long int i = 0; i < n; i++) {
		cin >> vetor[i];
	}

	for (long long int i = 0; i < m; i++) {
		cin >> queries[i];
	}

	for (long long int i = 0; i < m; i++) {
		if (queries[i] >= vetor[n-1]) {
			cout << vetor[n-1] << endl;
			continue;
		}

		if (queries[i] <= vetor[0]) {
			cout << vetor[0] << endl;
			continue;
		}

		int b = buscab(vetor, n, queries[i], &tmp);
		
		if (abs(tmp-queries[i]) <= abs(b-queries[i])) {
			cout << tmp << endl;
		} else {
			cout << b << endl;
		}
	}
	
	return 0;
}
