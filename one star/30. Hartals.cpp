#include <iostream>
#include <vector>
using namespace std;


int main() {
    int testCase ;
    cin >> testCase ;

    while (testCase--) {
        int days, parties ;
        cin >> days >> parties ;
        vector<int> hartal(parties, 0) ;
        for (int i = 0; i < parties; i++) {
            cin >> hartal[i] ;
        }

        int ans = 0;
        for (int i = 0; i < days; i++) {  // 0: Sun, 1: Mon, 2: Tue, 3: Wed, 4: Thu, 5: Fri, 6: Sat
            if (i % 7 == 5 || i % 7 == 6) {  // Fri or Sat : holliday
                continue ;
            }
            for (int p = 0; p < parties; p++) {
                if ( (i + 1) % hartal[p] == 0) {
                    ans++ ;
                    break ;
                }
            }
        }
        cout << ans << endl ;
    }
}