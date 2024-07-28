#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

enum Colors {
    WHITE,
    GRAY,
    BLACK
};

unordered_map<char, vector<char>> getAdjList(vector<string> words, int N, int K) {
    unordered_map<char, vector<char>> adjList;
    N = adjList.size();

    for (int index = 0; index < N - 1; index++) {
        string word1 = words[index];
        string word2 = words[index + 1];

        int minLength = min(word1.size(), word2.size());
        for (int i = 0; i < minLength; i++) {
            if (word1[i] != word2[i]) {
                adjList[word1[i]].push_back(word2[i]);
                break;
            }
        }
    }

    return adjList;
}

bool dfs(char node, unordered_map<char, vector<char>>& adjList, unordered_map<char, Colors>& colorMap, string& order) {
    colorMap[node] = GRAY;

    for (char neighbor : adjList[node]) {
        if (colorMap[neighbor] == WHITE) {
            if (!dfs(neighbor, adjList, colorMap, order)) {
                return false;
            }
        } else if (colorMap[neighbor] == GRAY) {
            // Cycle detected
            return false;
        }
    }

    colorMap[node] = BLACK;
    order.push_back(node);
    return true;
}

string generateTopoOrder(unordered_map<char, vector<char>> adjList) {
    unordered_map<char, Colors> colorMap;
    string order;

    // Initialize color map for all characters
    for (auto& pair : adjList) {
        if (colorMap.find(pair.first) == colorMap.end()) {
            colorMap[pair.first] = WHITE;
        }
        for (char neighbor : pair.second) {
            if (colorMap.find(neighbor) == colorMap.end()) {
                colorMap[neighbor] = WHITE;
            }
        }
    }

    // Perform DFS for all unvisited nodes
    for (auto& pair : adjList) {
        if (colorMap[pair.first] == WHITE) {
            if (!dfs(pair.first, adjList, colorMap, order)) {
                return ""; // Cycle detected
            }
        }
    }

    reverse(order.begin(), order.end());
    return order;
}

class Solution {
public:
    string findOrder(vector<string> words, int N, int K) {
        unordered_map<char, vector<char>> adjList = getAdjList(words, N, K);
        return generateTopoOrder(adjList);
    }
};

int main() {
    Solution solution;
    // string words[] = {"baa", "abcd", "abca", "cab", "cad"};
    vector<string> words = {"ajcckaehkjfagilhkdjljallcfbdfbgkgehifjcchekbeffcbl", "bfdhkciacljaldcceibeekkhljgdekiifgahgdeeicbe", "chcicjiaejkhkekggeakleibbbaackdeklajfk", "chjalfhchfagfebdecgklk", "cklikajaacgagkifchlec", "efdljeecegkajik", "ehbjcldikicjgghjaegijjkcclfkl", "eijhkidjlgbdjldcdfkakljhkbcefgdeaeegjeldbegig", "eljaafeklgigififfgfhfkaeecekkhjiifjdchejflffbdgdb", "jeegbibaddbl", "jfelahhdkhedakjedhbfcbcg", "kcgdghfgaidbjefcdifggdcfgjliecjkhkkcijik", "kdikglgefhj", "kiaifgfkecajablj", "kickgieghlhckl", "kkbcehagbdjclkibdejfjhgjkllddbdjifkijdialj", "lbakdalbihdheafcflhcehdghklhjgaiaejbhcach", "lcgedkcajkdkdggabhggjdfbhcibkgbj", "libefdiclhdcelhbjdg"};
    // int N = 5, K = 4;
    string order = solution.findOrder(words, 0, 0);
    cout << "Order: " << order << endl;
    return 0;
}