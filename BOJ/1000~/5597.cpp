#include <iostream>
using namespace std;
int a[31], t;
int main(){
    for(int i=0;i<28;i++){
        cin >> t;
        a[t] = 1;
    }
    for(int i=1;i<=30;i++){
        if(!a[i]) cout << i << endl;
    }
}