#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, m, A[55][55], res = 2000000000;
int dist[14][105];

struct node {
	int i, j;
};

vector<node> C;
vector<node> H;
vector<int> list;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			if (A[i][j] == 1) H.push_back({ i,j });
			else if (A[i][j] == 2) C.push_back({ i, j });
		}
	}

	for (int i = 0; i < C.size(); i++) {
		for (int j = 0; j < H.size(); j++) {
			dist[i][j] = abs(C[i].i - H[j].i) + abs(C[i].j - H[j].j);
		}
	}

	for (int i = 1; i < (1 << C.size()); i++) {
		int cnt = 0, temp = i, cnt2 = 0;
		while (temp != 0) {
			if ((temp & 1)) {
				cnt++;
				list.push_back(cnt2);
			}
			temp >>= 1;
			cnt2++;
		}
		if (cnt <= m) {
			int sum = 0;
			for (int j = 0; j < H.size(); j++) {
				int T = 200;
				for (int k = 0; k < list.size(); k++) {
					T = min(T, dist[list[k]][j]);
				}
				sum += T;
			}
			res = min(res, sum);
		}
		list.clear();
	}
	cout << res << '\n';
	return 0;
}