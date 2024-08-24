#include <iostream>
#include <vector>
using namespace std;


typedef long long int LL ;


LL count(int units, int bars, int maxLen, vector<vector<LL>>& dp) {
    if (units < 0) {
        return 0 ;
    }
    if (bars == 0) {
        dp[units][bars] = (units == 0 ? 1 : 0) ;  // ensure that all units are used
        return dp[units][bars] ;  
    }

    if (dp[units][bars] != -1) {
        return dp[units][bars] ;
    }

    dp[units][bars] = 0 ;
    for (int L = 1; L <= maxLen; L++) {  // consider all sublens of a bar
        dp[units][bars] += count(units - L, bars - 1, maxLen, dp) ;
    }

    return (dp[units][bars]) ;  // because default value is -1
}


int main() {
    int units, bars, maxLen ;
    while (cin >> units >> bars >> maxLen) {
        vector<vector<LL>> dp(units+1, vector<LL>(bars+1, -1)) ;
        cout << count(units, bars, maxLen, dp) << endl ;
    }
}