/*
    https://leetcode.com/problems/two-sum/description/
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>&nums, int target) {
    unordered_map<int, int> indexMapper;
        for(int i=0; i<nums.size(); i++) {
            auto targetIterator = indexMapper.find(target - nums[i]);
            if(targetIterator!=indexMapper.end()) {
                return {i, targetIterator->second};
            }
            indexMapper[nums[i]] = i;

        }        
        return {};        
}

int main() {
    vector<int> arr = {2, 7, 11, 15};    
    vector<int> result = twoSum(arr, 9);
    for(int res: result) {
        cout<<res<<endl;
    }
    return 0;
}