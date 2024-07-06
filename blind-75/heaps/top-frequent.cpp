#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for(int number: nums) {
            frequency[number]++;
        }

        vector<int> result;

        auto cmp = [](const pair<int, int>& op1, const pair<int, int>& op2) {
            return op1.second > op2.second; 
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);


        for(auto it=frequency.begin(); it!=frequency.end(); it++) {            
            pq.push({it->first, it->second});
            if(pq.size()>k) {
                pq.pop();
            }
        }

        while(pq.size()) {    
            pair<int, int> top = pq.top();                        
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};