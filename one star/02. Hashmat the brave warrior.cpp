#include <iostream>
#include <cmath>
using namespace std;


int main() {
    long long int n, m ;  // because max = 2^32 , INT_MAX = 2^31
    while (cin >> n >> m) {
        cout << abs(n - m) << endl ;
    }
}