#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> count(vector<int> ans, vector<int> v) {
    vector<int> output(2, 0) ;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == v[i]) {
            ans[i] = -1 ;
            v[i] = -1 ;
            output[0]++ ;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i] != -1) {
            for (int j = 0; j < ans.size(); j++) {
                if (ans[j] == v[i]) {
                    ans[j] = -1 ;
                    output[1]++ ;
                    break ;
                }
            }
        }
    }
    return output ;
}


int main() {
    int len ;
    int game = 1 ;
    while (cin >> len && len) {
        cout << "Game " << game++ << ":\n" ;
        vector<int> ans(len, 0) ;
        vector<int> v(len, 0) ;
        for (int i = 0; i < len; i++) {
            cin >> ans[i] ;
        }
        while (true) {
            bool zero = true ;
            for (int i = 0; i < len; i++) {
                cin >> v[i] ;
                if (v[i] != 0) {
                    zero = false ;
                }
            }

            if (zero) {
                break ;
            }
            
            vector<int> output = count(ans, v) ;
            cout << "    (" << output[0] << "," << output[1] << ")\n" ;
        }
    }
}