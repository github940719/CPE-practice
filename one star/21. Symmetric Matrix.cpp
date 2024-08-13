#include <iostream>
#include <vector>
using namespace std;


bool symmetric(vector<vector<long long int>>& v, int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (v[i][j] < 0) {
                return false ;
            }
            if (v[i][j] != v[row-i-1][row-j-1]) {
                return false ;
            }
        }
    }
    return true ;
}


int main() {
    int testCase ;
    cin >> testCase ;

    for (int test = 1; test <= testCase; test++) {
        for (int _ = 0; _ < 5; _++) {
            cin.ignore() ;
        }
        int row ;
        cin >> row ;
        
        vector<vector<long long int>> v ;
        for (int i = 0; i < row; i++) {
            vector<long long int> vi ;
            for (int j = 0; j < row; j++) {
                long long int n ;
                cin >> n ;
                vi.push_back(n) ;
            }
            v.push_back(vi) ;
        }

        cout << "Test #" << test << ": " ;

        if (symmetric(v, row)) {
            cout << "Symmetric.\n" ;
        }
        else {
            cout << "Non-symmetric.\n" ;
        }
    }
}