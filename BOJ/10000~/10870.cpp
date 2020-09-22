#include <iostream>
using namespace std;

int main(){
    int n;
    int p1, p2, temp;
    temp = 0;
    p1 = 0;
    p2 = 1;
    cin >> n;
    while(n--){
        temp = p1 + p2;
        p1 = p2;
        p2 = temp;
    }
    cout << p1 << endl;
    return 0;
}