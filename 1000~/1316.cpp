#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n, cnt; 
char dd[101];
bool alpha[26];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--) {
		memset(alpha,0,sizeof(alpha));
		bool ct = true;
		cin >> dd;
		for (int i = 0; i < strlen(dd); i++) {
			if (alpha[dd[i] - 97] == 0) {
				alpha[dd[i] - 97] = 1;
				while (dd[i] == dd[i + 1]) i++;
			}
			else {
				ct = false;
				break;
			}
		}
		if (ct) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}
