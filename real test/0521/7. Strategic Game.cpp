#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> DFS(int num, int parent, vector<vector<int>>& tree) {
    // v[0] = min total soldiers of the sub tree whose root is num if there is not soldier in node num
    // v[1] = min total soldiers of the sub tree whose root is num if there is one soldier in node num
    vector<int> v = {0, 1} ;
    if (tree[num].empty()) {
        return v ;
    }

    for (auto i = tree[num].begin(); i != tree[num].end(); i++) {
        if (*i == parent) {
            continue ;  // parent node
        }
        vector<int> child = DFS(*i, num, tree) ;
        v[0] += child[1] ;
        v[1] += min(child[0], child[1]) ;
    }
    return v ;
}


int main() {
    int nodeCnt, connectedNum ;
    while (cin >> nodeCnt) {
        vector<vector<int>> tree(nodeCnt, vector<int>(0)) ;
        for (int i = 0; i < nodeCnt; i++) {
            string input ;
            cin >> input ;
            int colon = input.find(':') ;
            int num = stoi(input.substr(0, colon)) ;
            int upper = input.find('('), lower = input.find(')') ;
            int connectedCnt = stoi(input.substr(upper+1, lower-upper-1)) ;

            for (int j = 0; j < connectedCnt; j++) {
                cin >> connectedNum ;
                tree[num].push_back(connectedNum) ;
                tree[connectedNum].push_back(num) ;  // undirected graph s.t. each node can be root
            }
        }

        vector<int> root = DFS(0, -1, tree) ;  // -1 means no parent
        cout << min(root[0], root[1]) << endl ;
    }
}