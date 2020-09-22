#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n, t, m;
int v[100005];

void bSearch(int start, int end, int val) {
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (v[mid] == val) {
			printf("1\n");
			return;
		}
		else if (v[mid] > val)
			end = mid - 1;
		else
			start = mid + 1;
	}
	printf("0\n");
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&v[i]);
	}
	sort(v, v + n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		bSearch(0, n - 1, t);
	}
}