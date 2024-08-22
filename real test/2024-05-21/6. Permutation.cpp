#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int sample ;
    cin >> sample ;

    vector<long long int> fac (21, 1) ;
    for (int i = 2; i <= 20; i++) {
        fac[i] = fac[i-1] * i ;
    }

    while (sample--) {
        string s ;
        cin >> s ;
        sort(s.begin(), s.end()) ;
        long long int n ;
        cin >> n ;
        
        string ans ;
        for (int i = s.length()-1; i >= 0; i--) {
            int index = n / fac[i] ;
            ans += s[index] ;
            s.erase(index, 1) ;  // from index, length = 1
            n %= fac[i] ;
        }

        cout << ans << endl ;
    }
}