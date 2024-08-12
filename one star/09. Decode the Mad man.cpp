#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int main() {
    string s ;
    getline(cin, s) ;
    unordered_map<char, char> dict ;
    string key   = "ertyuiop[]dfghjkl;\'cvbnm,. " ;
    string value = "qwertyuiopasdfghjklzxcvbnm " ;
    for (int i = 0; i < key.length(); i++) {
        dict[key[i]] = value[i] ;
    }

    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i] ;
        if (isupper(c)) {
            c = tolower(c) ;
        }
        cout << dict[c] ;
    }
    cout << endl ;
    return 0 ;
}
