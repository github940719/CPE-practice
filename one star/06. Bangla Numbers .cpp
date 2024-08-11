#include <iostream>
#include <string>
using namespace std;

void print(long long int n) {
    static string s ;
    if (n >= 10000000) {
        print(n / 10000000) ;  // notice!
        s += " kuti " ;
        n %= 10000000 ;
    }
    if (n >= 100000) {
        s += to_string(n / 100000) ;
        s += " lakh " ;
        n %= 100000 ;
    }

    if (n >= 1000) {
        s += to_string(n / 1000) ;
        s += " hajar " ;
        n %= 1000 ;
    }

    if (n >= 100) {
        s += to_string(n / 100) ;
        s += " shata " ;
        n %= 100 ;
    }

    if (n > 0) {
        s += to_string(n) ;
    }
    if (s[s.length()-1] == ' ') {  // important!
        s.erase(s.length()-1, 1) ;
    }
    cout << s ;
    s.clear() ;
}


int main() {
    long long int n ;
    int count = 1 ;
    while (cin >> n) {
        if (count >= 1000)
            cout << count++ << ". " ;
        else if (count >= 100)
            cout << " " << count++ << ". " ;
        else if (count >= 10)
            cout << "  " << count++ << ". " ;
        else 
            cout << "   " << count++ << ". " ;

        if (n == 0)
            cout << 0 ;  // important!
        else
            print(n) ;
        cout << endl ;
    }
}