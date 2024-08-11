#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;



int main() {
    string s ;
    while (cin >> s) {
        if (s == "0") {
            return 0 ;
        }

        int odd = 0, even = 0 ;
        for (int i = 0; ;) {
            try {
                odd += (s.at(i++) - '0') ;
                even += (s.at(i++) - '0') ;
            }

            catch (exception e) {
                if (abs(odd - even) % 11 == 0)
                    cout << s << " is a multiple of 11.\n" ;
                else 
                    cout << s << " is not a multiple of 11.\n" ;
                break ;
            }
        }
    }
}