#include <bits/stdc++.h>
using namespace std;

int main() {
  int p = 0;
  int ans = 0;
 
  cin >> p;
  
  if (p == 2) {
    cout << "0\n";
    return 0;
  }
  
  cout << 1 << endl << (p + 1) / 2 << " " << (p - 1) / 2 << endl;
  
  return 0;
}
