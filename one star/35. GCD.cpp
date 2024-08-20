#include <iostream>
#include <string>
using namespace std;


int gcd(int a, int b) {
    while (b != 0) {
        int temp = a ;
        a = b ;
        b = temp % b ;
    }
    return a ;
}


int main() {
    int n ;
    while (cin >> n) {
        if(n == 0) {
            return 0 ;
        }

        long long int G = 0 ;
        for (int i = 1; i < n; i++) {
            for (int j = i+1; j <= n; j++) {
                G += gcd(j, i) ;
            }
        }
        cout << G << endl ;
    }
}