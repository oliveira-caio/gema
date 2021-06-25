#include <bits/stdc++.h>

using namespace std;

int main() {
	long int n;
	stack<char> st;
	
	cin >> n;

	if (n % 2 != 0) {
		cout << "DEU RUIM" << endl;
		return 0;
	}

	for (long int i = 0; i < n; i++) {
		char x, y;
		cin >> x;
		if (st.size() == 0 && (x == '}' || x == ']' || x == ')')) {
			cout << "DEU RUIM" << endl;
			return 0;
		}
		if (x == '{' || x == '(' || x == '[') {
			st.push(x);
			continue;
		}
		y = st.top();
		if (x == '}' && y == '{') {
			st.pop();
			continue;
		}
		if (x == ')' && y == '(') {
			st.pop();
			continue;
		}
		if (x == ']' && y == '[') {
			st.pop();
			continue;
		}
	}

	if (st.size() == 0) {
		cout << "COMPLETINHA" << endl;
		return 0;
	} else {
		cout << "DEU RUIM" << endl;
		return 0;
	}
}
