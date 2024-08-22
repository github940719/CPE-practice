#include <iostream>
#include <vector>
using namespace std;


int largest(vector<string>& v, int row, int col, int r, int c) { 
    for (int extend = 1; ; extend++) {  // side length: 2 * extend - 1
        if (r-extend < 0 || c-extend < 0 || r+extend >= row || c+extend >= col) {
            return 2 * extend - 1 ;
        }

        for (int i = r-extend; i <= r+extend; i++) {
            for (int j = c-extend; j <= c+extend; j++) {
                if (v[i][j] != v[r][c]) {
                    return 2 * extend - 1 ;
                }
            }
        }
    }
}


int main() {
    int testCase ;
    cin >> testCase ;

    while (testCase--) {
        int row, col, center ;
        cin >> row >> col >> center ;
        cout << row << " " << col << " " << center << endl ;
        vector<string> v(row) ;
        for (int i = 0; i < row; i++) {
            cin >> v[i] ;
        }

        int r, c ;
        for (int i = 0; i < center; i++) {
            cin >> r >> c ;
            cout << largest(v, row, col, r, c) << endl ;
        }
    }
}