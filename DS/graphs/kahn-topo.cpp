#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<vector<int>> graphWithCycle() {
    vector<vector<int>> adjList(5, vector<int>());
    adjList[0].push_back(1);
    adjList[1].push_back(2);
    adjList[2].push_back(3);
    adjList[3].push_back(4);
    adjList[4].push_back(2);

    return adjList;
}

vector<vector<int>> graphWithoutCycle() {
    vector<vector<int>> adjList(5, vector<int>());
    adjList[0].push_back(1);
    adjList[1].push_back(2);
    adjList[2].push_back(3);
    adjList[3].push_back(4);    

    return adjList;
}

void print(vector<int>& order) {
    for(int tmp: order) {
        cout<<tmp<<"\t";
    }
    cout<<endl;
}

vector<int> kahn_topo(int V, vector<vector<int>> adjList) {
    vector<int> inDegree(V, 0);
    vector<int> topologicalOrder;

     // Step 1: Calculate in-degrees of all vertices
    for(int vertex=0; vertex<V; vertex++) {
        for(int neighbor: adjList[vertex]) {
            inDegree[neighbor]++;
        }
    }

    queue<int> bfs;

    // Step 2: Initialize a queue with all vertices having in-degree of 0
    for(int vertex=0; vertex<V; vertex++) {
        if(inDegree[vertex]==0) {
            bfs.push(vertex);
        }
    }

    // Step 3: Process vertices in the queue
    while(!bfs.empty()) {
        int current = bfs.front();
        bfs.pop();
        topologicalOrder.push_back(current);

        for(int neighbor: adjList[current]) {
            inDegree[neighbor]--;
            if(inDegree[neighbor]==0) {
                bfs.push(neighbor);
            }
        }
    }

    // Step 4: Check if there was a cycle in the graph
    if (topologicalOrder.size() != V) {
        return {}; // The graph has a cycle
    }

    return topologicalOrder;
}

int main() {
    vector<int> order = kahn_topo();
    print(order);
    return 0;
}