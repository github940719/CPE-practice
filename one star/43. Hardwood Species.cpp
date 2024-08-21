#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;


int main() {
    int testCase ;
    cin >> testCase ;
    cin.ignore() ;
    cin.ignore() ;

    while (testCase--) {
        string s ;
        map<string, int> dict ;
        double total = 0 ;
        while (getline(cin, s)) {
            if (s == "") {
                break ;
            }
            dict[s]++ ;
            total++ ;
        }

        cout << fixed << setprecision(4) ;
        for (auto i = dict.begin(); i != dict.end(); i++) {
            cout << i-> first << " " << i-> second / total * 100 << endl ;
        }
        if (testCase != 0) {
            cout << endl ;
        }
    }
}