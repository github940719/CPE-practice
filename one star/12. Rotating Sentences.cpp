#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    string s ;
    vector<string> v ;
    int maxlen = 0 ;
    while (getline(cin, s)) {
        v.push_back(s) ;
        maxlen = max(maxlen, static_cast<int>(s.length())) ;
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = v[i].length(); j < maxlen; j++) {
            v[i] += " " ;
        }
    }

    for (int i = 0; i < maxlen; i++) {
        for (int j = v.size()-1; j >= 0 ; j--) {
            cout << v[j][i] ;
        }
        cout << endl ;
    }
}