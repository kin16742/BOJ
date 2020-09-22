#include <iostream>
using namespace std;

int t, a;

int main() {
	cin >> t;
	while(t--){
        int arr[105] = {0,}, result = 0;
        cin >> a;   
        for(int i=1;i<=a;i++){
            for(int j=i;j<=a;j+=i) arr[j]++;
        }
        for(int i=1;i<=a;i++){
            if(arr[i]%2) result++;
        }
        cout << result << endl;
    }
}