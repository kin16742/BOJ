#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll a, res, A = 0, B = 0;
char c;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> c;
		if (c == 'A') A++;
		else B++;
	}
	if (A == B) cout << "Tie\n";
	else if (A > B) cout << "A\n";
	else cout << "B\n";
	return 0;

}