#include<iostream>

using namespace std;

class Solution {
public:
    class cmp {

    public:
        bool operator()(vector<int> p1, vector<int> p2) {
            if (p1[1] == p2[1]) {
                return p1[0] > p2[0];
            }
            return p1[1] > p2[1];
        }

    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        map<vector<int>, int> indexMap;
        vector<int> result;

        for (int index = 0; index < tasks.size(); index++) {
            indexMap[tasks[index]] = index;
        }

        sort(tasks.begin(), tasks.end(), [](vector<int> task1, vector<int> task2) {
            if (task1[0] == task2[0])
                return task1[1] < task2[1];
            return task1[0] < task2[0];
            });


        int index = 0;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        pq.push(tasks[index++]);

        while (!pq.empty()) {
            vector<int> top = pq.top();
            result.push_back(indexMap[top]);
            cout << top[0] << " -> " << top[1] << " size=" << pq.size() << endl;
            pq.pop();
            int burst = top[0] + top[1];

            while (index < tasks.size() && burst >= tasks[index][0]) {
                pq.push({ tasks[index][0], tasks[index][1] });
                index++;
            }
        }

        return result;
    }
};

int main() {

    Solution sol;
    sol.getOrder([[19, 13], [16, 9], [21, 10], [32, 25], [37, 4], [49, 24], [2, 15], [38, 41], [37, 34], [33, 6], [45, 4], [18, 18], [46, 39], [12, 24]] );
    return 0;
}