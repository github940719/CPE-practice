#include <iostream>
using namespace std;


int main() {
    int testCase ;
    cin >> testCase ;

    int a, b ;
    for (int i = 1; i <= testCase; i++) {
        cin >> a >> b ;
        
        int n = a, ans = 0 ;
        if (a % 2== 0) {
            n = a+1 ;
        }
        for (int j = n; j <= b; j += 2) {
            ans += j ;
        }

        cout << "Case " << i << ": " << ans << endl ;
    }
}