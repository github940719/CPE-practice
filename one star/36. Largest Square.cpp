#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool check(vector<string> v, int center_row, int center_col, int extend) {
    if (center_row - extend < 0 || center_col - extend < 0 || 
        center_row + extend >= v.size() || center_col + extend >= v[0].length()) {
        return false ;
    }

    char letter = v[center_row - extend][center_col - extend] ;
    for (int r = center_row - extend; r <= center_row + extend; r++) {
        for (int c = center_col - extend; c <= center_col + extend; c++) {
            if (v[r][c] != letter) {
                return false ;
            }
        }
    }
    return true ;
}

int main() {
    int testCase ;
    cin >> testCase ;

    while (testCase--) {
        int height, width, center ;
        cin >> height >> width >> center ;
        cout << height << " " << width << " " << center << endl ;
        
        vector<string> v(height, "") ;
        for (int h = 0; h < height; h++) {
            cin >> v[h] ;
        }

        while (center--) {
            int row, col ;
            cin >> row >> col ;

            int ans = 1 ;
            while (check(v, row, col, ans)) {
                ans++ ;
            }
            cout << 2 * ans - 1 << endl ;
        }
    }
    return 0 ;
}