/*
    https://leetcode.com/problems/pacific-atlantic-water-flow/description/
    https://www.youtube.com/watch?v=pDvvDvgHUKE
    https://leetcode.com/problems/pacific-atlantic-water-flow/solutions/5438565/cpp-readable-solution/
*/
class Solution {
public:
    vector<pair<int, int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    void bfs(set<pair<int, int>>& visitSet, vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        queue<pair<int, int>> bfsQueue;

        for(auto iterator = visitSet.begin(); iterator!=visitSet.end(); iterator++) {
            bfsQueue.push(*iterator);
        }

        while(!bfsQueue.empty()) {
            pair<int, int> vertex = bfsQueue.front();
            bfsQueue.pop();

            for(pair<int, int> direction: directions) {
                int xNext = vertex.first + direction.first;
                int yNext = vertex.second + direction.second;

                if(xNext<0 || yNext<0 || xNext>=rows || yNext>=cols) // Out of bounds
                    continue;
                
                if(visitSet.count({xNext, yNext})) { // if it's already visited
                    continue;
                }

                if(heights[xNext][yNext]>=heights[vertex.first][vertex.second]) { //unvisited, so add
                    visitSet.insert({xNext, yNext});
                    bfsQueue.push({xNext, yNext});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int rows = heights.size();
        int cols = heights[0].size();        

        set<pair<int, int>> atlanticSet;
        set<pair<int, int>> pacificSet;

        for(int i=0; i<rows; i++) {            
            pacificSet.insert({i, 0});
            atlanticSet.insert({i, cols-1});
        }

        for(int i=0; i<cols; i++) {
            pacificSet.insert({0, i});
            atlanticSet.insert({rows-1, i});
        }               

        bfs(atlanticSet, heights);
        bfs(pacificSet, heights);
        vector<vector<int>> result;

        for(auto iterator=atlanticSet.begin(); iterator!=atlanticSet.end(); iterator++) {
            if(pacificSet.count(*iterator)) {
                result.push_back({iterator->first, iterator->second});
            }
        }

        return result;
    }
};