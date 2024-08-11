#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {
    int line ;
    cin >> line ;
    unordered_map<string, int> dict ;
    vector<string> v ;

    while (line--) {
        string country, name ;
        cin >> country ;
        getline(cin, name) ;
        if (dict.count(country)) {
            dict[country] += 1 ;
        }
        else {
            v.push_back(country) ;
            dict[country] = 1 ;
        }
    }

    sort(v.begin(), v.end()) ;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " << dict[v[i]] << endl ;
    }
    return 0 ;
}