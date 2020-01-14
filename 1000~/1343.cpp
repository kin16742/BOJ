#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

char c[550];
vector<int> v;
int main() {
	cin >> c;
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] == 'X') {
			int cnt = 0;
			for (i; i < strlen(c) + 1; i++) {
				if (c[i] == 'X') cnt++;
				else {
					v.push_back(cnt);
					break;
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2) {
			cout << -1 << '\n';
			return 0;
		}
	}
	int idx = 0;
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] == '.') cout << c[i];
		else {
			while (v[idx]) {
				if (v[idx] >= 4) {
					cout << "AAAA";
					v[idx] -= 4;
					i += 4;
				}
				else {
					cout << "BB";
					v[idx] -= 2;
					i += 2;
				}
			}
			idx++;
			i--;
		}
	}
	cout << '\n';
}