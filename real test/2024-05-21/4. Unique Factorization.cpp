#include <iostream>
#include <vector>
using namespace std;


void fac(int num, int previous, vector<vector<int>>& ans, vector<int>& temp) {
    for (int i = previous; i * i <= num; i++) {
        if (num % i == 0) {
            vector<int> input(temp) ;
            input.push_back(i) ;
            fac(num / i, i, ans, input) ;
        }
    }

    if (!temp.empty()) {
        temp.push_back(num) ;
        ans.push_back(temp) ;
    }
}


int main() {
    int num ;
    while (cin >> num && num) {

        if (num == 1) {
            cout << "0\n" ;
            continue ;
        }

        vector<vector<int>> ans ;
        vector<int> temp ;
        fac(num, 2, ans, temp) ;
        cout << ans.size() << endl ;
        for (auto i = ans.begin(); i != ans.end(); i++) {
            cout << (*i)[0] ;
            for (auto j = i-> begin()+1; j != i-> end(); j++) {
                cout << " " << *j ;
            }
            cout << endl ;
        }
    }
}