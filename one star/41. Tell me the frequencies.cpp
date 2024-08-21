#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


void f(string& s) {
    unordered_map<char, int> dict ;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '\r' || s[i] == '\n') {
            continue ;
        }
        if (dict.find(s[i]) != dict.end()) {
            dict[s[i]]++ ;
        }
        else {
            dict[s[i]] = 1 ;
        }
    }

    vector<pair<char, int>> v(dict.begin(), dict.end()) ;
    sort(v.begin(), v.end(), [] (pair<char, int> i, pair<char, int> j) {
        if (i.second == j.second) {
            return i.first > j.first ;
        }
        return i.second < j.second ;
    }) ;

    for (auto i = v.begin(); i != v.end(); i++) {
        cout << static_cast<int>(i-> first) << " " << i-> second << endl ;
    }
}


int main() {
    string s ;
    getline(cin, s) ;
    f(s) ;

    while (getline(cin, s)) {
        cout << endl ;
        f(s) ;
    }
}