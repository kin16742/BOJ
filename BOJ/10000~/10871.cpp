#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[10001], s, d;
	cin >> s >> d;
	for (int i = 0; i < s; i++) cin >> a[i];
	for (int i = 0; i < s; i++) if (a[i] < d) cout << a[i] << ' '; 
}