/*
    https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/
class Solution{
    public:
    
    vector<string> result;
    map<pair<int, int>, char> movement = {
        {{0, 1}, 'R'},
        {{0, -1}, 'L'},
        {{1, 0}, 'D'},
        {{-1, 0}, 'U'}
    };
    
    
    void dfs(vector<vector<int>> &m, int x, int y, string path) {
        
        if(x==m.size()-1 && y==m[0].size()-1) {
            result.push_back(path);
            return;
        }
        
        if(x>=m.size() || y>=m[0].size()) {
            return;
        }
        
        m[x][y] = 0;
        
        for(auto direction: movement) {
            int x_offset = direction.first.first;
            int y_offset = direction.first.second;
            int x_next = x + x_offset;
            int y_next = y + y_offset;
            
            if(x_next<0 || y_next<0)
                continue;
            if(x_next>=m.size() || y_next>=m[0].size())
                continue;
            
            if(m[x_next][y_next]) {
                path.push_back(direction.second);
                dfs(m, x_next, y_next, path);
                path.pop_back();
            }
        }
        m[x][y] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(!m[0][0])
            return {};
        dfs(m, 0, 0, "");
        
        return result;
    }
};