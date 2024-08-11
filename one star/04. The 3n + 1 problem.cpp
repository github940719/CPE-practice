#include <iostream>
using namespace std;


unsigned int cycle(unsigned int n) {
    unsigned int count = 1 ;
    while (n != 1){
        count++ ;
        if (n % 2 == 0) {
            n /= 2 ;
        }
        else {
            n = n * 3 + 1 ;
        }
    }
    return count ;
}


int main() {
    unsigned int x, y ;
    while (cin >> x >> y) {
        cout << x << " " << y << " " ;
        if (x > y) {  // notice!
            unsigned temp = x ;
            x = y ;
            y = temp ;
        }

        unsigned int maxCycle = cycle(y) ;
        for (int i = x; i < y; i++) {
            maxCycle = max(maxCycle, cycle(i)) ;
        }
        cout << maxCycle << endl ;
    }
}