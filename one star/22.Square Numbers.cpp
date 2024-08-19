#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int a, b ;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) {
            return 0 ;
        }

        int success = 0 ;
        for (int i = a; i <=b; i++) {
            int s = sqrt(i) ;
            if (s * s == i) {
                success++ ;
            }
        }
        cout << success << endl ;
    }
}