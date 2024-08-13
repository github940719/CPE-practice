#include <iostream>
using namespace std;


int main() {
    int testCase ;
    cin >> testCase ;

    int sum, diff ;  // sum > diff 
    while (cin >> sum >> diff) {
        if (sum < diff || (sum + diff) % 2 == 1) {  // remember to check!
            cout << "impossible\n" ;
            continue ;
        }
        int a = (sum + diff) / 2 ;
        int b = (sum - a) ;
        cout << a << " " << b << endl ;
    }
}