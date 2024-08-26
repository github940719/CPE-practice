#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
    long long int islandCnt, dist ;
    for (int i = 1; cin >> islandCnt >> dist && islandCnt && dist ; i++) {
        cout << "Case " << i << ": " ;

        // pos[0] = radar left most , pos[1] = radar right most , to cover the island
        vector<vector<double>> pos(islandCnt, vector<double>(2)) ;

        bool end = false ;
        for (int j = 0; j < islandCnt; j++) {
            int x, y ;
            cin >> x >> y ;

            if (y > dist) {
                end = true ;
                continue ;
            }
            // dist( (?, 0), (x, y) ) = dist
            // ? = x +- sqrt(dist^2 - y^2)
            double temp = sqrt((dist + y) * (dist - y)) ;
            pos[j][0] = x - temp ;
            pos[j][1] = x + temp ;
        }

        if (end) {
            cout << -1 << endl ;
            continue ;
        }

        sort(pos.begin(), pos.end(), [] (vector<double>& i, vector<double>& j) {
            return i[0] <= j[0] ;
        }) ;
        
        int ans = 1 ;
        double radar_right = pos[0][1] ;
        for (int i = 1; i < islandCnt; i++) {
            if (pos[i][0] > radar_right) {
                ans++ ;
                radar_right = pos[i][1] ;
            }
            else {
                radar_right = min(radar_right, pos[i][1]) ;
            }
        }
        cout << ans << endl ;
    }
}