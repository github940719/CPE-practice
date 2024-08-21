#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;



int main() {
    int testCase ;
    cin >> testCase ;
    unordered_map<char, vector<bool>> dict ;
    dict['c'] = {0, 1, 1, 1, 0, 0, 1, 1, 1, 1} ;
    dict['d'] = {0, 1, 1, 1, 0, 0, 1, 1, 1, 0} ;
    dict['e'] = {0, 1, 1, 1, 0, 0, 1, 1, 0, 0} ;
    dict['f'] = {0, 1, 1, 1, 0, 0, 1, 0, 0, 0} ;
    dict['g'] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0} ;
    dict['a'] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0} ;
    dict['b'] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0} ;
    dict['C'] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0} ;
    dict['D'] = {1, 1, 1, 1, 0, 0, 1, 1, 1, 0} ;
    dict['E'] = {1, 1, 1, 1, 0, 0, 1, 1, 0, 0} ;
    dict['F'] = {1, 1, 1, 1, 0, 0, 1, 0, 0, 0} ;
    dict['G'] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0} ;
    dict['A'] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0} ;
    dict['B'] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0} ;

    cin.ignore() ;
    while (testCase--) {
        string s ;
        getline(cin, s) ;  // the song may be empty, so cin >> s is WRONG!
        vector<int> count(10, 0) ;
        vector<bool> press(10, false) ;

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 10; j++) {
                if (press[j] == false && dict[s[i]][j] == true) {
                    count[j]++ ;
                    press[j] = true ;
                }
                else if (press[j] == true && dict[s[i]][j] == false) {
                    press[j] = false ;
                }
            }
        }

        cout << count[0] ;
        for (int i = 1; i < 10; i++) {
            cout << " " << count[i] ;
        }
        cout << endl ;
    }
}