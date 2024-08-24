#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


unordered_map<char, char> m ; // m[win] = lose


vector<vector<char>> judge(vector<vector<char>> v, int row, int col) {
    vector<vector<char>> temp(row, vector<char>(col, ' ')) ;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            char c = v[i][j] ;

            if (i > 0 && v[i-1][j] == m[c]) {
                temp[i-1][j] = c ;
            }
            if (i < row-1 && v[i+1][j] == m[c]) {
                temp[i+1][j] = c ;
            }
            if (j > 0 && v[i][j-1] == m[c]) {
                temp[i][j-1] = c ;
            }
            if (j < col-1 && v[i][j+1] == m[c]) {
                temp[i][j+1] = c ;
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (temp[i][j] == ' ') {
                temp[i][j] = v[i][j] ;
            }
        }
    }
    return temp ;
}


int main() {
    m['R'] = 'S' ;
    m['S'] = 'P' ;
    m['P'] = 'R' ;

    int t ;
    cin >> t ;

    while (t--) {
        int row, col, day ;
        cin >> row >> col >> day ;

        vector<vector<char>> v(row, vector<char>(col)) ;
        for (int i = 0; i < row; i++) {
            string s ;
            cin >> s ;
            for (int j = 0; j < col; j++) {
                v[i][j] = s[j] ;
            }
        }

        while (day--) {
            v = judge(v, row, col) ;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << v[i][j] ;
            }
            cout << endl ;
        }
        if (t) {
            cout << endl ;
        }
    }
}