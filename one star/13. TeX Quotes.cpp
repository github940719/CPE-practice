#include <iostream>
#include <string>
using namespace std;


int main() {
    string s ;
    bool first = true ;
    while (getline(cin, s)) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '\"') {
                if (first) {
                    first = false ;
                    cout << "``" ;
                }
                else {
                    first = true ;
                    cout << "\'\'" ;
                }
            }
            else {
                cout << s[i] ;
            }
        }
        cout << endl ;
    }
}