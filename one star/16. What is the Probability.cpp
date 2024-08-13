#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
    int testCase ;
    cin >> testCase ;

    while (testCase--) {
        int player_cnt, target_player ;
        float prob ;
        cin >> player_cnt >> prob >> target_player ;

        if (prob == 0) {
            cout << "0.0000\n" ;  // remember!
            continue ;
        }

        // (1-prob) ^ (target-1) * prob + (1-prob)^(total+target-1) * prob +
        // (1-prob) ^ (2*total+target-1) * prob + ...
        float initial = pow(1 - prob, target_player - 1) ;
        float r = pow(1 - prob, player_cnt) ;
        cout <<  fixed << setprecision(4) << prob * initial / (1 - r) << endl ;
    }
}