#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[3], b[3];
    for(int i = 0; i < 3; i++){
        cin >> a[i] >> b[i];
    }
    sort(a, a + 3);
    sort(b, b + 3);

    if(a[0] == a[1]) cout << a[2];
    else cout << a[0];
    cout << ' ';

    if(b[0] == b[1]) cout << b[2];
    else cout << b[0];
    cout << endl;
}