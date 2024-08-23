#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
    int testCase ;
    cin >> testCase ;

    while (testCase--) {
        int num ;
        cin >> num ;
        vector<int> pos(num) ;
        for (int i = 0; i < num; i++) {
            cin >> pos[i] ;
        }
        sort(pos.begin(), pos.end()) ;

        int minPos = pos[num / 2], dist = 0 ;

        for (int i = 0; i < num; i++) {
            dist += abs(pos[i] - minPos) ;
        }

        cout << dist << endl ;
    }
}
