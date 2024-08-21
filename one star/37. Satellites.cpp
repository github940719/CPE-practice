#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
    double dist, angle ;  // float will lead to wrong answer!
    string str ;
    while (cin >> dist >> angle >> str) {
        if (str == "min") {
            angle /= 60 ;
        }
        dist += 6440 ;

        if (angle > 180) {  // important!
            angle = 360 - angle ;
        }

        angle = angle * M_PI / 180 ;
        cout << fixed << setprecision(6) ;
        cout << dist * angle << " " ;
        cout << sqrt(pow(dist, 2) * 2 * (1 - cos(angle))) << endl ;
    }
}