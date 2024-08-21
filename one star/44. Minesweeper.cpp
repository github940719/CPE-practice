#include <iostream>
#include <string>
#include <vector>
using namespace std;


string count(int i, int j, vector<string>& map, int row, int col) {
    if (map[i][j] == '*') {
        return "*" ;
    }
    int ans = 0 ;
    for (int a = i-1; a <= i+1; a++) {
        if (a < 0 || a >= row) {
            continue ;
        }
        for (int b = j-1; b <= j+1; b++) {
            if (b < 0 || b >= col) {
                continue ;
            }
            if (map[a][b] == '*') {
                ans++ ;
            }
        }
    }
    return to_string(ans) ;
}


int main() {
    string ans ;
    int line, col ;
    cin >> line >> col ;
    for (int i = 1; ; i++) {
        cout << "Field #" << i << ":\n" ;

        vector<string> v ;
        for (int i = 0; i < line; i++) {
            string s ;
            cin >> s ;
            v.push_back(s) ;
        }

        for (int i = 0; i < line; i++) {
            for (int j = 0; j < col; j++) {
                cout << count(i, j, v, line, col) ;
            }
            cout << endl ;
        }

        cin >> line >> col ;
        if (line == 0 && col == 0) {
            return 0 ;
        }
        cout << endl ;
    }
}