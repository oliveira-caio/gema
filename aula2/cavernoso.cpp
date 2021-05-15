#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, max = 0;
	vector<int> freq(1000, 0);

	cin >> n;
	
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		freq[s.size()]++;
	}

	for(int i=0; i<1000; i++) {
		if (freq[i] >= freq[max]) {
			max = i;
		}
	}
	
	cout << max << endl;
	
	return 0;
}
