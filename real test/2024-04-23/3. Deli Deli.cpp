#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int main() {
    int L, N ;
    cin >> L >> N ;

    unordered_map<string, string> dict ;
    while (L--) {
        string s1, s2 ;
        cin >> s1 >> s2 ;
        dict[s1] = s2 ;
    }

    string v = "aeiou" ;
    while (N--) {
        string s ;
        cin >> s ;
        if (dict.find(s) != dict.end()) {
            cout << dict[s] << endl ;
        }
        else {
            int len = s.length() ;
            if (v.find(s[len-2]) == string::npos && s[len-1] == 'y') {
                cout << s.substr(0, len-1) << "ies\n" ;
            }
            else if (s[len-1] == 'o' || s[len-1] == 's' ||s[len-1] == 'x') {
                cout << s << "es\n" ;
            }
            else if (s[len-1] == 'h' && (s[len-2] == 'c' || s[len-2] == 's')) {
                cout << s << "es\n" ;
            }
            else {
                cout << s << "s\n" ;
            }
        }
    }
}