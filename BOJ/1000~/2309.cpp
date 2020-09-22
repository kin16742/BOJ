#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int A[9], sum;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 9; i++) {
		cin >> A[i];
		sum += A[i];
	}
	bool c = false;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - A[i] - A[j] == 100) {
				A[i] = A[j] = 0;
				c = true;
				break;
			}
		}
		if (c) break;
	}
	sort(A, A + 9);
	for (int i = 0; i < 9; i++) {
		if (A[i] != 0) cout << A[i] << '\n';
	}
	return 0;
}