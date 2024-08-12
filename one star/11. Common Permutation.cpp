#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    string s1, s2 ;
    while (getline(cin, s1) && getline(cin, s2)) {
        multiset<char> set ;  // remain repeated element
        for (int i = 0; i < s1.length(); i++) {
            auto index = s2.find(s1[i]) ;
            if (index != string::npos) {
                set.insert(s1[i]) ;
                s2[index] = '0' ;  // important! s1 = ttt, s2 = tt -> ans should be tt
            }
        }

        // inorder traversal: sorted!
        for (auto i = set.begin(); i != set.end(); i++) {
            cout << *i ;
        }
        cout << endl ;
    }
}