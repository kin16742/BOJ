#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

const int length = 26;
char aa[501];
ll n, m, res = 0;

class Trie {
private:
	Trie* children[length];
public:
	bool terminal;
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
			int next = (*key) - 'a';
			if (children[next] == nullptr) children[next] = new Trie();
			children[next]->insert(key + 1);
		}
	}

	bool chk(const char *key) {
		if (*key == '\0' && terminal) return true;
		else if (terminal) return false;
		else {
			int next = (*key) - 'a';
			if (children[next] == nullptr) return false;
			return children[next]->chk(key + 1);
		}
	}
};


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	Trie *root = new Trie;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> aa;
		root->insert(aa);
	}
	for (int i = 0; i < m; i++) {
		cin >> aa;
		if (root->chk(aa)) res++;
	}

	cout << res << '\n';
	return 0;
}