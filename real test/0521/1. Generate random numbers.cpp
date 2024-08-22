#include <iostream>
#include <unordered_set>
using namespace std;


int main() {
    int n ;
    while (cin >> n) {
        if (n == 0) {
            return 0 ;
        }

        unordered_set<int> s ;
        while (s.find(n) == s.end()) {
            s.insert(n) ;
            n = n * n % 1000000 / 100 ;
        }
        cout << s.size() << endl ;
    }
}
