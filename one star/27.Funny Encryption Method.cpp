#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    int testCase ;
    cin >> testCase ;

    while (testCase--) {
        int n ;
        cin >> n ;
        int n16 = n;

        // step1
        int b1 = 0 ;
        while (n > 0) {
            if (n % 2 == 1) {
                b1 += 1 ;
            }
            n /= 2 ;
        }

        unordered_map<int, int> dict ;
        dict[0] = 0;
        dict[1] = 1;
        dict[2] = 1;
        dict[3] = 2;
        dict[4] = 1;
        dict[5] = 2;
        dict[6] = 2;
        dict[7] = 3;
        dict[8] = 1;
        dict[9] = 2;

        int b2 = 0 ;
        while (n16 > 0) {
            b2 += dict[n16 % 10] ;
            n16 /= 10 ;
        }

        cout << b1 << " " << b2 << endl ;
    }
}