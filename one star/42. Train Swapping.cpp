#include <iostream>
#include <vector>
using namespace std;


int f(int& len, vector<int>& order) {  // bubble sort
    int swap = 0 ;
    for (int i = len-1; i >= 1; i--) {
        for (int j = 1; j <= i; j++ ) {
            if (order[j] < order[j-1]) {
                int temp = order[j] ;
                order[j] = order[j-1] ;
                order[j-1] = temp ;
                swap++ ;
            }
        }
    }
    return swap ;
}


int main() {
    int testCase, trainLen ;
    cin >> testCase ;

    while (testCase--) {
        cin >> trainLen ;
        vector<int> order(trainLen, 0) ;
        for (int i = 0; i < trainLen; i++) {
            cin >> order[i] ;
        }
        cout << "Optimal train swapping takes " << f(trainLen, order) << " swaps.\n" ;
    }
}