#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;


int main() {
    int testCase ;
    cin >> testCase ;

    while (testCase--) {
        int relative ;
        cin >> relative ;
        vector<int> pos(relative, 0) ;

        int minPos = INT_MAX, maxPos = 0 ;
        for (int i = 0; i < relative; i++) {
            cin >> pos[i] ;
            minPos = min(minPos, pos[i]) ;
            maxPos = max(maxPos, pos[i]) ;
        }

        int min_dist = INT_MAX ;
        for (int i = minPos; i <= maxPos; i++) {
            int dist = 0 ;
            for (int j = 0; j < relative; j++) {
                dist += abs(pos[j] - i) ;
            }
            if (dist < min_dist) {
                min_dist = dist ;
            }
        }
        cout << min_dist << endl ;
    }
    return 0 ;
}
