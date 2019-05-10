#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
using namespace std;

int n, m, cnt;
string pname;
char poke[21];
map<string, int> dogam;
string pokeNames[100001];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	cnt = 1;
	while (n--) {
		cin >> pname;
		pokeNames[cnt] = pname;
		dogam.insert(pair<string, int>(pname, cnt++));
	}
	while (m--) {
		cin >> poke;
		if (poke[0] < 65) {
			int pokeNum = 0;
			for (int i = 0; i < strlen(poke); i++) {
				pokeNum *= 10;
				pokeNum += poke[i] - 48;
			}
			cout << pokeNames[pokeNum] << '\n';
		}
		else {
			pname = poke;
			cout << dogam[pname] << '\n';
		}
	}
	return 0;
}
