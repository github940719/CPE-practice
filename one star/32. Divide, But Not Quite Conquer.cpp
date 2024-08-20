#include <iostream>
#include <string>
using namespace std;


void divide(int a, int b) {
    if (a < 2 || b < 2) {
        cout << "Boring!\n" ;
        return ;
    }

    string s = to_string(a) ;
    while (a != 1) {
        if (a % b) {
            cout << "Boring!\n" ;
            return ;
        }
        a /= b ;
        s += " " ;
        s += to_string(a) ;
    }
    cout << s << endl ;
}


int main() {
    int a, b ;
    while (cin >> a >> b) {
        divide(a, b) ;
    }
}