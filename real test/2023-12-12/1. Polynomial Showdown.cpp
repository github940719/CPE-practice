#include <iostream>
#include <vector>
using namespace std;


void print(vector<int>& v) {
    bool start = true ;
    bool zero = true ;
    for (int i = 8; i > 0; i--) {
        int n = v[i] ;
        if (n) {
            zero = false ;
        }
        if (n) {
            if (start) {
                if (n > 0) {
                    if (n != 1) {
                        cout << n ;
                    }
                }
                else {
                    cout << "-" ;
                    if (n != -1) {
                        cout << -n ;
                    }
                }
                cout << "x" ;
                if (i != 1) {
                    cout << "^" << i ;
                }
                start = false ;
            }
            else {
                if (n > 0) {
                    cout << " + " ;
                }
                else {
                    cout << " - " ;
                    n = (-n) ;
                }

                if (n != 1) {
                    cout << n ;
                }

                cout << "x" ;
                if (i != 1) {
                    cout << "^" << i ;
                }
            }
        }
    }

    int n = v[0] ;
    if (zero) {
        cout << n ;
    }
    else if (n) {
        if (n > 0) {
            cout << " + " ;
        }
        else {
            cout << " - " ;
            n = (-n) ;
        }

        if (n)
            cout << n ;
    }
    cout << endl ;
}


int main() {
    int n ;
    while (cin >> n) {
        vector<int> v(9) ;
        // reverse
        v[8] = n ;
        for (int i = 7; i >= 0; i--) {
            cin >> v[i] ;
        }
        print(v) ;
    }
}
