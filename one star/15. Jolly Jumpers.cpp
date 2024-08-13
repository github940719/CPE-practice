#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


bool jolly(vector<int>& v, int len) {
    vector<bool> exist(len, false) ;
    for (int i = 1; i < len; i++) {
        // remember to check the boundry!
        int diff = abs(v[i] - v[i-1]) ;
        if (diff >= len || diff == 0 || exist[diff]) {
            return false ;
        }
        exist[diff] = true ;
    }
    return true ;
}


int main() {
    int num ;
    while (cin >> num) {
        vector<int> v(num, 0) ;
        for (int i = 0; i < num; i++) {
            cin >> v[i] ;
        }
        if (jolly(v, num)) {
            cout << "Jolly\n" ;
        }
        else {
            cout << "Not jolly\n" ;
        }
    }
}