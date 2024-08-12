#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    string l ;
    string s ;
    getline(cin, l) ;
    int line = stoi(l) ;
    map<char, int> dict ;

    while (line--) {
        getline(cin, s) ;
        for (int i = 0; i < s.length(); i++) {
            if (!isalpha(s[i])) {
                continue ;
            }
            char c = toupper(s[i]) ;
            if (dict.find(c) != dict.end()) {
                dict[c] += 1 ;
            }
            else {
                dict[c] = 1 ;
            }
        }
    }

    // turn the map into vector in order to sort
    vector<pair<char, int>> v(dict.begin(), dict.end()) ;  
    sort(v.begin(), v.end(), [] (pair<char, int>& i, pair<char, int>& j) {
        return i.second > j.second ;
    }) ;

    for (auto i = v.begin(); i != v.end(); i++) {
        cout << i-> first << " " << i-> second << endl ;
    }
    return 0 ;
}