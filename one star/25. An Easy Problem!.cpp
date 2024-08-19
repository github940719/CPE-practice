#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int main() {
    unordered_map<char, int> dict ;
    for (int i = 0; i < 10; i++) {
        dict['0' + i] = i ;
    }
    for (int i = 0; i < 26; i++) {
        dict['A' + i] = 10 + i ;
    }
    for (int i = 0; i < 26; i++) {
        dict['a' + i] = 36 + i ;
    }
    
    string s;
    while (cin >> s) {
        int max_digit = -1, sum = 0 ;
        for (int i = 0; i < s.length(); i++) {
            max_digit = max(max_digit, dict[s[i]]) ;
            sum += dict[s[i]] ;
        }

        bool success = false ;
        for (int i = max(2, max_digit+1); i < 63; i++) {
            if (sum % (i-1) == 0) {
                cout << i << endl ;
                success = true ;
                break ;
            }
        }

        if (success == false)
            cout << "such number is impossible!" << endl ;
    }
}
