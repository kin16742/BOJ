#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
int n, x;
char c[100];

int main() {
	cin >> n;
	while (n--) {
		int cnt = 0;
		bool flag = true;
		cin >> c;
		for (int i = 0; i < strlen(c); i++) {
			if (c[i] == '(') {
				cnt++;
			}
			if (c[i] == ')') {
				if (!cnt) flag = false;
				cnt--;
			}
		}
		if (cnt) flag = false;
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}