#include <iostream>
#include <vector>
using namespace std;


int main() {
    int testCase ;
    cin >> testCase ;

    for (int i = 1; i <= testCase; i++) {
        cout << "Case #" << i << ":\n" ;

        vector<string> urls(10) ;
        vector<int> count(10) ;
        int maxCount = -1 ;

        for (int j = 0; j < 10; j++) {
            cin >> urls[j] >> count[j] ;
            maxCount = max(maxCount, count[j]) ;
        }

        for (int j = 0; j < 10; j++) {
            if (count[j] == maxCount) {
                cout << urls[j] << endl ;
            }
        }
    }
}