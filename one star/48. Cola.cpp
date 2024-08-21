#include <iostream>
using namespace std;


int main() {
    int n ;
    while (cin >> n) {
        int total = n ;
        while (n >= 3) {
            total += (n / 3) ;
            n = (n % 3) + (n / 3) ;
        }

        if (n == 2) {
            total++ ;
        }
        cout << total << endl ;
    }
}