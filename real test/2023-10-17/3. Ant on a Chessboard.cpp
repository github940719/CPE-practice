#include <iostream>
using namespace std;


void odd(int i, int time) {
    int start = i * i ;
    for (int x = 1; x <= i+1; x++) {
        start++ ;
        if (start == time) {
            cout << x << " " << i+1 << endl ;
            return ;
        }
    }
    for (int y = i; y >= 1; y--) {
        start++ ;
        if (start == time) {
            cout << i+1 << " " << y << endl ;
            return ;
        }
    }
}


void even(int i, int time) {
    int start = i * i ;
    for (int y = 1; y <= i+1; y++) {
        start++ ;
        if (start == time) {
            cout << i+1 << " " << y << endl ;
            return ;
        }
    }
    for (int x = i; x >=1; x--) {
        start++ ;
        if (start == time) {
            cout << x << " " << i+1 << endl ;
            return ;
        }
    }
}


int main() {
    int time ;
    while (cin >> time && time) {
        if (time == 1) {
            cout << "1 1\n" ;
            continue ;
        }

        int i = 1 ;
        for ( ; i * i < time; i++) {}

        i-- ;
        if (i & 1) { // odd 
            odd(i, time) ;
        }
        else {  // even
            even(i, time) ;
        }
    }
}