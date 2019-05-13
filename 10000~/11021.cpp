#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, a, b;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> b;
		cout <<"Case #" << i << ": "<< a + b << '\n';
	}
	return 0;
}

