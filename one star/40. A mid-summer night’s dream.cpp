#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int num ;
    while (cin >> num) {
        vector<int> x(num, 0) ;
        for (int i = 0; i < num; i++) {
            cin >> x[i] ;
        }

        sort(x.begin(), x.end()) ;
        int A1 = x[(num-1)/2], A2 = x[num/2], AinInput = 0, diffA = 0 ;

        for (int i = 0; i < num; i++) {
            if (x[i] == A1 || x[i] == A2) {
                AinInput++ ;
            }
        }

        cout << A1 << " " << AinInput << " " << A2 - A1 + 1 << endl ;
    }
}