#include<iostream>
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

int findParent(vector<int>& arr, int vertex) {
    while(arr[vertex]!=-1) {
        vertex = arr[vertex];
    }
    return vertex;
}

bool detectCycle(vector<vector<int>> adjList) {
    int vertices = adjList.size();
    for(vector<int> adj: adjList) {
        for(int tmp: adj) {
            vertices = max(vertices, tmp);
        }
    }

    vector<int> parentMap(vertices, -1);

    for(int from=0; from<vertices; from++) {
        for(int toEdge: adjList[from]) {
            int toParent = findParent(parentMap, toEdge);
            int fromParent = findParent(parentMap, from);

            if(toParent==fromParent) {
                if(toParent==-1) {
                    parentMap[toEdge] = from;
                } else {
                    return true;
                }
            } else {
                parentMap[toParent] = fromParent;
            }
        }
    }

    for(int vertex=0; vertex<vertices; vertex++) {
        cout<<parentMap[vertex]<<"\t";
    }
    cout<<"\n";

    return false;
}

int main() {

    vector<vector<int>> adjList = graphWithCycle();
    if(detectCycle(graphWithCycle()))
        cout<<"Cycle found\n";
    else
        cout<<"Cycle not found\n";

    if(detectCycle(graphWithoutCycle()))
        cout<<"Cycle found\n";
    else
        cout<<"Cycle not found\n";

    return 0;
}