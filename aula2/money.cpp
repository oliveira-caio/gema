#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector<int> vec;

	cin >> n;

	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.begin()+n);

	cout << vec[n-1] - vec[0] << endl;
	
	return 0;
}
