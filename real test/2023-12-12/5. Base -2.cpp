#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void f(int n) {
    if (n == 0) {
        cout << 0 ;
        return ;
    }

    string s ;
    while (n) {
        int mod = n % (-2) ;
        if (mod) {
            s += "1" ;
            n /= (-2) ;
            if (mod == -1) {
                n++ ;
            }
        }
        else {
            s += "0" ;
            n /= (-2) ;
        }
    }
    

    // reverse
    reverse(s.begin(), s.end()) ;
    cout << s ;
}


int main() {
    int t, n ;
    cin >> t ;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " ;
        cin >> n ;
        f(n) ;
        cout << endl ;
    }
}