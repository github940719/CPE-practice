#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main() {
    int testCase ;
    cin >> testCase ;
    vector<int> cost(36, 0) ;

    for (int i = 1; i <= testCase; i++) {
        for (int j = 0; j < 36; j++) {
            cin >> cost[j] ;
        }

        cout << "Case " << i << ":\n" ;
        int query ;
        cin >> query ;

        for (int j = 0; j < query; j++) {
            int n ;
            cin >> n ;
            cout << "Cheapest base(s) for number " << n << ":" ;

            vector<int> cost_each_base(35, 0) ;
            int minCost = INT_MAX ;
            for (int b = 2; b <= 36; b++) {
                int testn = n ;
                while (testn > 0) {
                    cost_each_base[b-2] += cost[testn %b] ;
                    testn /= b ;
                }
                minCost = min(minCost, cost_each_base[b-2]) ;
            }

            for (int b = 2; b <= 36; b++) {
                if (cost_each_base[b-2] == minCost) {
                    cout << " " << b ;
                }
            }
            cout << endl ;
        }

        if (i != testCase)
            cout << endl ;
    }
}