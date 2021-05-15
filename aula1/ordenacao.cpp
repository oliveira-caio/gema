#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[3];
 
	cin >> arr[0];
	cin >> arr[1];
	cin >> arr[2];
 
	sort(arr, arr+3, greater<int>());
 
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << endl;
	}
  
	return 0;
}
