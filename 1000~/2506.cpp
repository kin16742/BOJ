#include <iostream>
using namespace std;

int t, a, arr[105], result;

int main() {
	cin >> t;
    for(int i=0;i<t;i++) cin >> arr[i];
    for(int i=1;i<t;i++){
        if(arr[i] != 0) arr[i] += arr[i-1];
    }
    for(int i=0;i<t;i++) result += arr[i];
    cout << result << endl;
}