#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
    int cnt ;
    cin >> cnt ;
    char chr ;
    vector<vector<int>> info(cnt, vector<int>(2)) ;
    for (int i = 0; i < cnt; i++) {
        cin >> chr ;
        cin >> info[chr - 'A'][0] >> info[chr - 'A'][1] ;
    }

    vector<vector<int>> stack ;  // each element : [row, col]

    string input ;
    while (cin >> input) {
        if (input.length() == 1) {
            cout << 0 << endl ;
            continue ;
        }

        long long int ans = 0 ;
        bool error = false ;

        for (int i = 0; i < input.length(); i++) {
            char c = input[i] ;
            if (isalpha(c)) {
                stack.push_back(vector<int>({info[c - 'A'][0], info[c - 'A'][1]})) ;
            }
            else if (c == ')') {
                vector<int> m2 = stack.back() ;
                stack.pop_back() ;
                vector<int> m1 = stack.back() ;
                stack.pop_back() ;

                if (m1[1] != m2[0]) {
                    cout << "error\n" ;
                    error = true ;
                    break ;
                }

                ans += (m1[0] * m1[1] * m2[1]) ;
                stack.push_back(vector<int>({m1[0], m2[1]})) ;
            }
        }

        if (!error)
            cout << ans << endl ;
    }
}