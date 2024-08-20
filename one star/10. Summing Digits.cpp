#include <iostream>
using namespace std;


int main() {
    int n ;
    while (cin >> n) {
        if (n == 0) {
            return 0 ;
        }

        while (n > 9) {
            int sum = 0 ;
            while (n != 0) {
                sum += (n % 10) ;
                n /= 10 ;
            }
            n = sum ;
        }

        cout << n << endl ;
    }
}
