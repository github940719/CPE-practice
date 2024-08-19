#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


bool isSeq(vector<int> v, int len) {
    if (v[0] < 1) {
        return false ;
    }
    for (int i = 1; i < len; i++) {
        if (v[i] <= v[i-1]) {
            return false ;
        }
    }
    
    unordered_set<int> s ;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (s.find(v[i] + v[j]) == s.end()) {
                s.insert(v[i] + v[j]) ;
            }
            else {
                return false ;
            }
        }
    }
    return true ;
}


int main() {
    int num, testCase = 1 ;
    while (cin >> num) {
        vector<int> seq(num, 0) ;
        for (int i = 0; i < num; i++) {
            cin >> seq[i] ;
        }
        cout << "Case #" << testCase << ": " ;
        if (isSeq(seq, num)) {
            cout << "It is a B2-Sequence.\n\n" ;
        }
        else {
            cout << "It is not a B2-Sequence.\n\n" ;
        }
        testCase++ ;
    }
}
