#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int main() {
    unordered_map<char, int> m ;
    for (int i = 0; i < 10; i++) {
        m['0' + i] = i ;
    }
    for (int i = 0; i < 26; i++) {
        m['A' + i] =  i + 10 ;
    }
    for (int i = 0; i < 26; i++) {
        m['a' + i] = i + 36 ;
    }

    string s ;
    while (cin >> s) {

        int maxD = -1, sum = 0 ;
        for (int i = 0; i < s.length(); i++) {
            maxD = max(maxD, m[s[i]]) ;
            sum += m[s[i]]  ;
        }

        bool possible = false ;
        for (int ans = max(2, maxD+1); ans <= 62; ans++) { // 2 to 62!
            if (sum % (ans-1) == 0) {
                cout << ans << endl ;
                possible = true ;
                break ;
            }
        }
        if (!possible) {
            cout << "such number is impossible!\n" ;
        }
    }
}