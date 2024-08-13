#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


int main() {
    int x ;
    string s, coefficients ;
    while (cin >> x) {
        cin.ignore() ;  // ignore '\n'
        getline(cin, s) ;
        stringstream ss(s) ;
        vector<long long int> v ;

        while (ss >> coefficients) {
            v.push_back(stoll(coefficients)) ;  // 2^31!
        }
        v.pop_back() ;  // constant term

        long long int ans = 0, exp = 1 ;
        int n = 1 ;

        for (int index = v.size()-1; index >= 0; index--) {
            ans += (n * v[index] * exp) ;
            n++ ;
            exp *= x ;
        }
        
        cout << ans << endl ;
    }
}