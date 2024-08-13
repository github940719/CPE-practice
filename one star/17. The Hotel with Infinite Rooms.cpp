#include <iostream>
using namespace std;


int main() {
    int group ;
    long long int day ;

    while (cin >> group >> day) {
        while (day > 0) {
            day -= group ;
            group++ ;
        }
        group-- ;
        cout << group << endl ;
    }
}