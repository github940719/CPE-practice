#include <iostream>
#include <vector>
using namespace std;


void judge(int vertexE, vector<vector<bool>> E) {
    for (int i = 0; i < vertexE; i++) {
        for (int j = 0; j < vertexE; j++) {
            bool endpoint = false, inconsistent = false ;
            for (int k = 0; k < vertexE; k++) {
                if (E[i][k] && E[j][k]) {
                    // i and j (edge in D) have the same endpoint
                    endpoint = true ;
                    // for "all the other" k 
                    // if E[i][k] and E[j][k] : ok
                    // if (not E[i][k]) and (not E[j][k]) : ok
                    // if one of them is true and the other is false : impossible
                }

                if (E[i][k] ^ E[j][k]) {  // XOR
                    inconsistent = true ;
                }
            }

            if (endpoint && inconsistent) {
                cout << "No\n" ;
                return ;
            }
        }
    }
    cout << "Yes\n" ;
}


int main() {
    int testCase ;
    cin >> testCase ;

    for (int i = 1; i <= testCase; i++) {
        cout << "Case #" << i << ": " ;
        int vertexE, edgeE ;
        cin >> vertexE >> edgeE ;

        vector<vector<bool>> E(vertexE, vector<bool>(vertexE)) ;
        for (int j = 0; j < edgeE; j++) {
            int x, y ;
            cin >> x >> y ;
            E[x][y] = true ;
        }

        judge(vertexE, E) ;
    } 
}