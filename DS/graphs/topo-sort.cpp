/*
    course schedule-ii
    iterative topo-sort
    https://leetcode.com/problems/course-schedule-ii/
*/
class Solution {
public:
    enum Colors{
        WHITE,
        GRAY,
        BLACK
    };
    vector<vector<int>> adjList;
    vector<Colors> colorMap;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        adjList = vector<vector<int>>(numCourses);
        colorMap = vector<Colors>(numCourses, Colors::WHITE);
        vector<int> topoLogicalOrder;

        for(vector<int> pre: prereq) {
            int second = pre[0];
            int first = pre[1];
            adjList[first].push_back(second);
        }

        stack<int> courseStack;

        for(int course=0; course<numCourses; course++) {
            if(colorMap[course]==Colors::WHITE) {
                courseStack.push(course);
                colorMap[course] = Colors::GRAY;

                while(!courseStack.empty()) {
                    int top = courseStack.top();                    
                    bool visitedAllNeighbors = true;

                    for(int nextCourse: adjList[top]) {
                        if(colorMap[nextCourse]==Colors::GRAY)
                            return {};
                        if(colorMap[nextCourse]==Colors::WHITE) {
                            visitedAllNeighbors = false;
                            colorMap[nextCourse] = Colors::GRAY;
                            courseStack.push(nextCourse);
                            break;
                        }                        
                    }
                    if(visitedAllNeighbors) {
                        colorMap[top] = Colors::BLACK;
                        topoLogicalOrder.push_back(top);
                        courseStack.pop();
                    }
                }
            }
        }
        reverse(topoLogicalOrder.begin(), topoLogicalOrder.end());
        return topoLogicalOrder;
    }
};