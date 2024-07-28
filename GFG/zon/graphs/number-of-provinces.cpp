class DSU {
    public:
    vector<int> parent;
    vector<int> rank;
    
    DSU(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        
        for(int index=0; index<size; index++) {
            parent[index] = index;
        }
    }
    
    int findParent(int node) {
        if(node!=parent[node]) {
            parent[node] = findParent(parent[node]);
        }
        return parent[node];
    }
    
    void unite(int node1, int node2) {
        int node1Parent = findParent(node1);
        int node2Parent = findParent(node2);
        
        if(rank[node1Parent] > rank[node2Parent]) {
            parent[node2Parent] = parent[node1Parent];
        } else if(rank[node1Parent] < rank[node2Parent]) {
            parent[node1Parent] = parent[node2Parent];
        } else {
            parent[node2Parent] = node1Parent;
            rank[node1Parent]++;
        }
    }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DSU dsu(V);
        int provinces = 0;
        
        for(int vertex=0; vertex<V; vertex++) {
            for(int j=0; j<V; j++) {
                if(vertex==j)
                    continue;
                if(adj[vertex][j])
                    dsu.unite(vertex, j);
            }
        }
        
        for(int i=0; i<V; i++) {
            if(dsu.parent[i]==i) {
                provinces++;
            }
        }
        
        return provinces;
    }
};