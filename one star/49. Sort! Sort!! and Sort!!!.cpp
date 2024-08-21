#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n ,m ;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            cout << 0 << " " << 0 << endl ;
            return 0 ;
        }
        cout << n << " " << m << endl ;
        vector<int> v(n) ;
        for (int j = 0; j < n; j++) {
            cin >> v[j] ;
        }
        sort(v.begin(), v.end(), [m] (int& a, int& b) {
            if ((a % m) < (b % m)) {
                return true ;
            }
            if ((a % m) > (b % m)) {
                return false ;
            }

            if (a & 1) {
                if (! (b & 1)) {
                    return true ;
                }
                return (a > b) ;
            }
            else {
                if (b & 1) {
                    return false ;
                }
                return (a < b) ;
            }
        }) ;

        for (int i = 0; i < n; i++) {
            cout << v[i] << endl ;
        }
    }
}