#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    int testCase ;
    cin >> testCase ;

    while (testCase--) {
        int tileCnt, infoCnt, handCnt ;
        cin >> tileCnt >> infoCnt >> handCnt ;

        // info[tileNum] = vector with next tileNum
        vector<vector<int>> info(tileCnt+1, vector<int>(0)) ;
        for (int i = 1; i <= infoCnt; i++) {
            int a, b ;
            cin >> a >> b ;
            info[a].push_back(b) ;
        }

        queue<int> Q ;
        for (int i = 0; i < handCnt; i++) {
            int n ;
            cin >> n ;
            Q.push(n) ;
        }

        vector<bool> isDown(tileCnt, false) ;
        int downCnt = 0 ;


        // BFS
        while (!Q.empty()) {
            int push = Q.front() ;
            Q.pop() ;
            if (isDown[push])
                continue ;

            isDown[push] = true ;
            downCnt++ ;
            for (auto n = info[push].begin(); n != info[push].end(); n++) {
                Q.push(*n) ;
            }
        }

        cout << downCnt << endl ;
    }
}