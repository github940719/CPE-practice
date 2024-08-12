#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
    int testCase ;
    cin >> testCase ;
    vector<int> date = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;

    // 1 / 1 : Saturday
    vector<string> day = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", 
                        "Wednesday", "Thursday"} ;

    while (testCase--) {
        int m, d ;
        cin >> m >> d ;

        int accu = 0 ;
        for (int i = 1; i < m; i++) {
            accu += date[i-1] ;
        }
        accu += d ;
        cout << day[accu % 7] << endl ;
    }
}