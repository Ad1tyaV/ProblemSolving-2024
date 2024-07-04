#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    // Leetcode solution - https://leetcode.com/problems/is-graph-bipartite/
        int n = graph.size();
        vector<int> colorMap(n, 0);

        int blue = 1;
        int white = -1;

        for(int vertex=0; vertex<n; vertex++) {            
            if(colorMap[vertex])
                continue;
            
            queue<int> bfs;
            bfs.push(vertex);
            colorMap[vertex] = blue;

            while(!bfs.empty()) {
                int front = bfs.front();
                bfs.pop();
                int currentColor = colorMap[front];

                for(int neighbor: graph[front]) {
                    int neighborColor = colorMap[neighbor];

                    if(neighborColor==currentColor)
                        return false;

                    if(!neighborColor) {
                        colorMap[neighbor] = -currentColor;
                        bfs.push(neighbor);
                    }
                }
            }

        }
        return true;
    }

bool isBipartite(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adjList(n+1);
    vector<int> colorMap(n+1, 0);

    int blue = 1;
    int white = 2;

    /*
        0 -> uncolored
        1-> blue
        2 -> white
    */

    for(int vertex = 1; vertex<=n; vertex++) {
        if(colorMap[vertex])
            continue;

        queue<int> bfs;
        bfs.push(vertex);
        colorMap[vertex] = blue;


        while(!bfs.empty()) {
            int front = bfs.front();
            bfs.pop();
            int currentColor = colorMap[front];

            for(int neighbor: adjList[front]) {
                int neighborColor = colorMap[neighbor];
                if(neighborColor) {
                    if(neighborColor==currentColor) {
                        return false;
                    }
                } else {
                    colorMap[neighbor] = -currentColor;
                    bfs.push(neighbor);
                }
            }
        }

    }
    return true;
}

int main() {

    vector<vector<int>> edges = {{1, 2}, {3, 1}, {4, 3}, {5,3}};

    if(isBipartite(5, edges))
        cout<<"Yes Bipartite\n";
    else 
        cout<<"Not Bipartite\n";

    return 0;
}