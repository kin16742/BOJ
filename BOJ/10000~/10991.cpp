#include <iostream>
using namespace std;
int t;
int main(){
    cin >> t;
    for(int i=0;i<t;i++){
        for(int j=1;j<t;j++){
            cout << ' ';
        }
        for(int j=0;j<i;j++){
            cout << "* ";
        }
        cout << endl;
    }
}