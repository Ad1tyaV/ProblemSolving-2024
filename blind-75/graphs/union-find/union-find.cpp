#include <iostream>
#include <vector>

using namespace std;

int findParent(vector<int> vertices, int vertex) {
    if(vertices[vertex]<0)
        return vertex;
    return vertices[vertex] = findParent(vertices, vertices[vertex]);
}

void unionSets(vector<int>& vertices, int from, int to) {
    int fromParent = findParent(vertices, from);
    int toParent = findParent(vertices, to);

    if(fromParent==toParent)
        continue;

    if(vertices[fromParent]>vertices[toParent]) {
        vertices[fromParent] += vertices[toParent];
        vertices[toParent] = fromParent;
    } else {
        vertices[toParent] += vertices[fromParent];
        vertices[fromParent] = toParent;
    }
}



int main() {
    return 0;
}