#include <iostream>
#include <algorithm>
using namespace std;
int a[5], avg;
int main(){
    for(int i=0;i<5;i++) cin >> a[i];
    sort(a,a+5);
    for(int i=0;i<5;i++){
        avg += a[i];
    }
    cout << avg/5 << endl;
    cout << a[2] << endl;
}