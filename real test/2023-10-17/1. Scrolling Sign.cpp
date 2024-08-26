#include <iostream>
#include <string>
using namespace std;


int countsame(string prev, string s, int chrlen) {
    int same ;
    for (same = chrlen; same > 0; same--) {
        string s1 = prev.substr(chrlen - same, same) ;
        string s2 = s.substr(0, same) ;
        if (s1 == s2) {
            return same ;
        }
    }
    return same ;
}


int main() {
    int testCase ;
    cin >> testCase ;

    while (testCase--) {
        int chrlen, wordCnt ;
        cin >> chrlen >> wordCnt ;

        string s ;
        cin >> s ;
        string prev = s ;
        int ans = s.length() ;
        wordCnt-- ;

        while (wordCnt--) {
            cin >> s ;
            int same = countsame(prev, s, chrlen) ;  // A"TE" "TE"S -> 2
            ans += (chrlen - same) ;
            prev = s ;
        }
        cout << ans << endl ;
    }
}
