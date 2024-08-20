#include <iostream>
using namespace std;


int main() {
    int x, y ;
    while (cin >> x >> y) {
        if (x == 0 && y == 0) {
            return 0 ;
        }
        
        int carry = 0 ;
        int digit = 0 ;
        for (int i = 0; i < 10; i++) {
            int a = x % 10, b = y % 10 ;
            if (a + b + digit > 9) {
                digit = 1 ;
                carry++ ;
            }
            else {
                digit = 0 ;
            }
            x /= 10 ;
            y /= 10 ;
        }

        if (carry == 0) {
            cout << "No carry operation.\n" ;
        } 
        else if (carry == 1) {
            cout << "1 carry operation.\n" ;
        }
        else {
            cout << carry << " carry operations.\n" ;
        }
    }
    return 0 ;
}
