#include <iostream>
using namespace std;


int main() {
    int height, slide, fatigue ;
    double climb ;
    while (cin >> height >> climb >> slide >> fatigue && height) {
        double temp = 0, minus = climb * fatigue / 100.0 ;
        for (int day = 1; ; day++) {
            temp += climb ;
            climb -= minus ;
            if (climb < 0) {
                climb = 0 ;
            }
            if (temp > height) {
                cout << "success on day " << day << endl ;
                break ;
            }

            temp -= slide ;
            if (temp < 0) {
                cout << "failure on day " << day << endl ;
                break ;
            }
        }
    }
}