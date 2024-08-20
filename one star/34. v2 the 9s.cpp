#include <iostream>
#include <string>
using namespace std;


long long int multiple_of_nine(string s) {
    int sum = 0 ;
    for (int i = 0; i < s.length(); i++) {
        sum += (s[i] - '0') ;
    }
    return sum ;
}


int main() {
    string s ;
    while (cin >> s) {
        if (s == "0") {
            return 0 ;
        }

        long long int sum = multiple_of_nine(s) ;
        if (sum % 9 != 0) {
            cout << s << " is not a multiple of 9.\n" ;
            continue ;
        }
        
        int degree = 1 ;
        while (sum > 9) {
            degree++ ;
            sum = multiple_of_nine(to_string(sum)) ;
        }
        cout << s << " is a multiple of 9 and has 9-degree " << degree << ".\n" ;
        
    }
}