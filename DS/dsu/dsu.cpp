#include<iostream>
#include<vector>

using namespace std;

class DSU {
    public:
    vector<int> parent;
    vector<int> rank;    

    DSU(int size) {
        parent.resize(size);
        rank.resize(size);

        for(int i=0; i<size; i++) {
            parent[i] = i; // Each node is it's own parent initially
        }
    }

    int findParent(int node) {
        if(parent[node]!=node) {
            parent[node] = findParent(parent[node]);
        }
        return parent[node];
    }
    void unite(int firstNode, int secondNode) {
        int firstNodeParent = findParent(node);
        int secondNodeParent = findParent(node);

        if(firstNodeParent!=secondParent) {
            if(rank[firstNodeParent]>rank[secondNodeParent]) {
                parent[secondNodeParent] = firstNodeParent;
            } else if(rank[firstNodeParent]<rank[secondNodeParent]) {
                parent[firstNodeParent] = secondNodeParent;
            } else {
                parent[secondNodeParent] = firstNodeParent;
                rank[firstNodeParent]++;
            }
        }
    }
};

int main() {
    return 0;
}