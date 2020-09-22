#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;
    if(a==0){
        cout << 1 << '\n';
        return 0;
    }
    for(int i=a-1;i>0;i--){
        a *= i;
    }
    cout << a << '\n';
    return 0;
}