#include <iostream>
using namespace std;
int t;
int main(){
    cin >> t;
    while(t--){
        int a, temp, result = 0;
        cin >> a;
        for(int i=0;i<a;i++){
            cin >> temp;
            result += temp;
        }
        cout << result << endl;
    }
}