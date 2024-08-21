#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;


int main() {
    int xbound, ybound ;
    cin >> xbound >> ybound ;

    int xinitial, yinitial ;
    char orientation ;
    string move ;
    unordered_set<int> s ;  // x * 100 + y
    while (cin >> xinitial >> yinitial >> orientation >> move) {
        bool lost = false ;
        for (int i = 0; i < move.length(); i++) {
            if (move[i] == 'L') {
                if (orientation == 'N') 
                    orientation = 'W' ;
                else if (orientation == 'W')
                    orientation = 'S' ;
                else if (orientation == 'S')
                    orientation = 'E' ;
                else 
                    orientation = 'N' ;
            }
            else if (move[i] == 'R') {
                if (orientation == 'N') 
                    orientation = 'E' ;
                else if (orientation == 'E')
                    orientation = 'S' ;
                else if (orientation == 'S')
                    orientation = 'W' ;
                else 
                    orientation = 'N' ;
            }
            else {
                if (orientation == 'N') {
                    if (yinitial == ybound) {
                        if (s.find(xinitial * 100 + yinitial) != s.end()) {
                            continue ;
                        }
                        s.insert(xinitial * 100 + yinitial) ;
                        lost = true ;
                        cout << xinitial << " " << yinitial << " " << orientation << " LOST\n" ;
                        break ;
                    }
                    yinitial++ ;
                }
                else if (orientation == 'W') {
                    if (xinitial == 0) {
                        if (s.find(xinitial * 100 + yinitial) != s.end()) {
                            continue ;
                        }
                        s.insert(xinitial * 100 + yinitial) ;
                        lost = true ;
                        cout << xinitial << " " << yinitial << " " << orientation << " LOST\n" ;
                        break; 
                    }
                    xinitial-- ;
                }
                else if (orientation == 'S') {
                    if (yinitial == 0) {
                        if (s.find(xinitial * 100 + yinitial) != s.end()) {
                            continue ;
                        }
                        s.insert(xinitial * 100 + yinitial) ;
                        lost = true ;
                        cout << xinitial << " " << yinitial << " " << orientation << " LOST\n" ;
                        break ;
                    }
                    yinitial-- ;
                }
                else {
                    if (xinitial == xbound) {
                        if (s.find(xinitial * 100 + yinitial) != s.end()) {
                            continue ;
                        }
                        s.insert(xinitial * 100 + yinitial) ;
                        lost = true ;
                        cout << xinitial << " " << yinitial << " " << orientation << " LOST\n" ;
                        break ;
                    }
                    xinitial++ ;
                }
            }
        }

        if (!lost)
            cout << xinitial << " " << yinitial << " " << orientation << endl ;
    }
}