#include <iostream>
using namespace std;


int main() {
    long long int t, vertex, edge ; 
    cin >> t ;
    while (t--) {
        cin >> vertex >> edge ;
        for (int critical = vertex - 1 ; critical >= 0; critical--) {
            bool success = false ;
            long long int vertex_temp = vertex - critical ;
            long long int edge_temp = edge - critical ;

            // confirm whether vertex_temp and edge_temp can form a connected graph
            if (vertex_temp == 1) {
                if (edge_temp == 0) {
                    success = true ;
                }
            }
            else if (vertex_temp == 2) {
                if (edge_temp == 1) {
                    success = true ;
                }
            }
            
            else if (edge_temp >= vertex_temp &&
                edge_temp <= (vertex_temp * (vertex_temp - 1) / 2)) {
                success = true ;
            }

            if (success) {
                cout << critical << endl ;
                break ;
            }
        }
    }
}