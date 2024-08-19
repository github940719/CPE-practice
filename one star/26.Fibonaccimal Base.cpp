#include <iostream>
#include <vector>
using namespace std;

int len = 2 ;
vector<int> v = {1, 2} ;

string f(int n) {
    string ans = "" ;
    bool one = false ;
    for (int i = len-1; i >= 0; i--) {
        if (n >= v[i]) {
            ans += "1" ;
            n -= v[i] ;
            one = true ;
        }
        else if (one == true) {
            ans += "0" ;
        }
    }
    return ans ;
}


int main() {
    while (v[len-1] < 100000000) {
        v.push_back(v[len-2] + v[len-1]) ;
        len++ ;
    }

    int line ;
    cin >> line ;

    while (line--) {
        int n ;
        cin >> n ;
        cout << n << " = " << f(n) << " (fib)\n" ;
    }
}