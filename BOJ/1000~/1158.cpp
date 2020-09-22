#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, d, k = -1;
bool chk[5010];
int main() {
	cin >> n >> m;
	d = n;
	cout << '<';
	while (d--) {
		int cnt = m;
		while (cnt > 0) {
			k++;
			if (!chk[k%n]) 
				cnt--;
		} 
		chk[k % n] = true;
		if (d > 0)
			cout << k % n + 1 << ", ";
		else
			cout << k % n + 1 << ">\n";
	}
}