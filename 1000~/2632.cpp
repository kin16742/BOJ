#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int s, m, n, cnt, temp, tA, tB;
vector<int> A, B;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		A.push_back(temp);
		tA += temp;
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		B.push_back(temp);
		tB += temp;
	}
	for (int i = 0; i < m; i++) {
		temp = A[i];
		for (int j = i + 1; j < i + m - 1; j++) {
			temp += A[j%m];
			A.push_back(temp);
		}
	}
	for (int i = 0; i < n; i++) {
		temp = B[i];
		for (int j = i + 1; j < i + n - 1; j++) {
			temp += B[j%n];
			B.push_back(temp);
		}
	}
	A.push_back(0);
	A.push_back(tA);
	B.push_back(0);
	B.push_back(tB);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0; i < A.size(); i++) {
		if (A[i] > s) break;

		int tem = s - A[i];
		cnt += (int)(upper_bound(B.begin(), B.end(), tem) - lower_bound(B.begin(), B.end(), tem));
	}
	cout << cnt << '\n';
	return 0;
}