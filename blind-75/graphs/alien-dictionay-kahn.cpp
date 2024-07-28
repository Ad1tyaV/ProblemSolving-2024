string kahnOrder(unordered_map<char, vector<char>> adjList, unordered_map<char, int>& inDegree, int K) {
    queue<char> bfs;
    string order;
    
    // Start with nodes that have no incoming edges
    for(auto it = inDegree.begin(); it != inDegree.end(); it++) {
        if(it->second == 0) {
            bfs.push(it->first);
        }
    }
    
    while(!bfs.empty()) {
        char front = bfs.front();
        bfs.pop();
        order.push_back(front);
        
        for(char next: adjList[front]) {
            inDegree[next]--;
            if(inDegree[next] == 0) {
                bfs.push(next);
            }
        }
    }
    
    // Check if we have all nodes in the result
    if(order.size() != K)
        return "";
    return order;
}

unordered_map<char, vector<char>> getAdjList(string words[], int N, int K, unordered_map<char, int>& inDegree) {
    unordered_map<char, vector<char>> adjList;
    
    // Initialize inDegree for all characters
    for(int i = 0; i < N; i++) {
        for(char c : words[i]) {
            inDegree[c] = 0;
        }
    }

    for(int index = 0; index < N - 1; index++) {
        string word1 = words[index];
        string word2 = words[index + 1];
        
        int first = 0;
        int second = 0;

        while(first < word1.size() && second < word2.size()) {
            if(word1[first] != word2[second]) {
                // Only add an edge if it doesn't already exist
                if(find(adjList[word1[first]].begin(), adjList[word1[first]].end(), word2[second]) == adjList[word1[first]].end()) {
                    adjList[word1[first]].push_back(word2[second]);
                    inDegree[word2[second]]++;
                }
                break;
            }
            first++;
            second++;
        }
    }

    return adjList;
}

class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        unordered_map<char, int> inDegree;
        unordered_map<char, vector<char>> adjList = getAdjList(dict, N, K, inDegree);
        return kahnOrder(adjList, inDegree, K);
    }
};