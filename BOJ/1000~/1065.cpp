#include <iostream>
using namespace std;

int main(){
    int result = 0;
    int a;
    cin >> a;
    for(int i=1;i<=a;i++){
            if (i >= 100) {
		    int a1 = i / 100;
		    int a2 = (i % 100) / 10;
		    int a3 = i % 10;
		    if (a2 - a1 == a3 - a2) {
			    result++;
	        }
	    }
	    else {
	    	result++;
	    }
    }
    cout << result << endl;
}