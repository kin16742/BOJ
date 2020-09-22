#include <iostream>
#include <algorithm>
using namespace std;

int a[5000000], n, k;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    cout << a[k - 1] << '\n';
    return 0;
}