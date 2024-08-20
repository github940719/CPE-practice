#include <iostream>
#include <string>
using namespace std;


long long int toint(string s) {
    long long int ans = 0 ;
    long long int two_to_ = 1 ;
    for (int i = s.length()-1; i >= 0; i--) {
        ans += (s[i] - '0') * two_to_ ;
        two_to_ *= 2 ;
    }
    return ans ;
}


bool relative_prime(long long int n1, long long int n2) {
    if (n1 < n2) {
        long long int temp = n1 ;
        n1 = n2 ;
        n2 = temp ;
    }

    while (n2 != 0) {
        long long int temp = n1 ;
        n1 = n2 ;
        n2 = temp % n1 ;
    }
    return (n1 == 1) ;
}


int main() {
    int testCase ;
    cin >> testCase ;

    for (int i = 1; i <= testCase; i++) {
        cout << "Pair #" << i << ": " ;
        
        string s1, s2 ;
        cin >> s1 >> s2 ;

        if (relative_prime(toint(s1), toint(s2))) {
            cout << "Love is not all you need!\n" ;
        }
        else {
            cout << "All you need is love!\n" ;
        }
    }
}