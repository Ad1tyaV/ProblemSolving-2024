#include<iostream>
#include<stack>
#include<vector>
#include<unordered_set>

using namespace std;

bool checkCycleIterative(vector<vector<int>>& adjList) {
    int nodes = adjList.size();
    vector<bool> visited(nodes, false);
    unordered_set<int> path;

    for(int node=0; node<nodes; node++) {
        if(!visited[node]) {
            stack<int> dfsStack;
            dfsStack.push(node);

            while(!dfsStack.empty()) {
                int top = dfsStack.top();                

                if(!visited[top]) {
                    visited[top] = true;
                    path.insert(top);
                } else {
                    // We only pop when all neighbors are visited of the node
                    dfsStack.pop();
                    path.erase(top);
                }                

                for(int neighbor: adjList[top]) {
                    if(!visited[neighbor]) {
                        dfsStack.push(neighbor);
                    } else if(path.count(neighbor)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {

    vector<vector<int>> adjList = {
        {4},
        {10},
        {1},
        {2},
        {5, 6},
        {6},
        {8},
        {0},
        {9},
        {3},
        {}
    };

    if(checkCycleIterative(adjList))
        cout<<"Cycle found\n";
    else 
        cout<<"Cycle not found\n";
    
    
    return 0;
}