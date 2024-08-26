#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int step ;

void DFS(vector<int>& marbles, vector<vector<int>>& tree, int node, vector<int>& parent) {
    for (int i = 0; i < tree[node].size(); i++) {
        DFS(marbles, tree, tree[node][i], parent) ;
    }

    if (parent[node] == -1) {
        return ;
    }

    int give = marbles[node] - 1 ;  // if give < 0 -> fetch from parent
    marbles[node] = 1 ;
    marbles[parent[node]] += give ;
    step += abs(give) ;
}


int main() {
    int vertexCnt, childCnt, num ;
    while (cin >> vertexCnt && vertexCnt) {
        step = 0 ;
        vector<int> marbles(vertexCnt) ;
        vector<vector<int>> tree(vertexCnt) ;
        vector<int> parent(vertexCnt, -1) ;

        for (int i = 0; i < vertexCnt; i++) {
            cin >> num >> marbles[num-1] >> childCnt ;
            tree[num-1] = vector<int>(childCnt) ;
            for (int j = 0; j < childCnt; j++) {
                cin >> tree[num-1][j] ;
                tree[num-1][j]-- ;  // from 0 not 1
                parent[tree[num-1][j]] = num - 1 ;
            }
        }

        int root = 0 ;
        while (parent[root] != -1) {
            root = parent[root] ;
        }

        DFS(marbles, tree, root, parent) ;
        cout << step << endl ;
    }
}