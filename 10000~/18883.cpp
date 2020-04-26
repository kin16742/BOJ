#include <iostream>
using namespace std;

int m, n;
int main() {
	cin >> n >> m;

	for(int i=0;i<n;i++){
		for(int j=1;j<m;j++){
			cout << i*m + j << ' ';
		}
		cout << (i+1)*m << '\n';
	}
}