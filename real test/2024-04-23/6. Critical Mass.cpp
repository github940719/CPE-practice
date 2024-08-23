#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


long long int C(int n, int m) {
    m = min(m, n - m) ;
    long long int ans = 1 ;
    for (int i = n; i > n - m; i--) {
        ans *= i ;
        ans /= (n - i + 1) ;
    }
    return ans ;
}


int main() {
    int n ;
    while (cin >> n && n) {
        long long int legal = 0 ;

        for (int u1 = 0; 2 * u1 - 1 <= n; u1++) {
            for (int u2 = 0; ; u2++) {
                int L = n - u1 - 2 * u2 ;
                if (u1 + u2 > L+1) {
                    break ;
                }
                legal += C(L+1, u1) * C(L+1-u1, u2) ;
            }
        }
        
        cout << static_cast<long long int>(pow(2, n)) - legal << endl ;
    }
}