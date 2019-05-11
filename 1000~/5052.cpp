#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

const int length = 10;
char aa[10000][11];
ll t, n;

class Trie {
private:
	Trie* children[length];
	bool terminal;
public:
	Trie()
		:terminal(false) {
		fill(children, children + length, nullptr);
	}
	~Trie() {
		for (int i = 0; i < length; i++) {
			if (children[i]) delete children[i];
		}
	}
	void insert(const char* key) {
		if (*key == 0) {
			terminal = true;
		}
		else {
			int next = (*key) - '0';
			if (children[next] == nullptr) children[next] = new Trie();
			children[next]->insert(key + 1);
		}
	}

	bool chk(const char *key) {
		if (*key == '\0') return false;
		else if (terminal) return true;
		else {
			int next = (*key) - '0';
			return children[next]->chk(key + 1);
		}
	}
};


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		bool res = 0;
		memset(aa, 0, sizeof(aa));
		Trie *root = new Trie;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> aa[i];
			root->insert(aa[i]);
		}
		for (int i = 0; i < n; i++) {
			if (root->chk(aa[i])) res = 1;
		}
		if (res) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}