#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n ;
    while (cin >> n) {
        if (n == 0) {
            return 0 ;
        }

        string s ;
        int one = 0 ;
        while (n > 0) {
            if (n & 1) {  // n % 2 == 1
                one ++ ;
                s += "1" ;
            }
            else {
                s += "0" ;
            }
            n >>= 1 ;  // move rightward i.e. n /=2
        }
        reverse(s.begin(), s.end()) ;

        cout << "The parity of " << s << " is " << one << " (mod 2).\n" ;
    }
}
