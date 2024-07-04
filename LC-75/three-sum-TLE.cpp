class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();        
        set<vector<int>> resultSet;        

        for(int i=0; i<n; i++) {
            unordered_set<int> tracker;
            for(int j=i+1; j<n; j++) {                
                int target = -(nums[i]+nums[j]);
                if(tracker.count(target)) {
                    vector<int> tmp = {nums[i], nums[j], target};
                    sort(tmp.begin(), tmp.end());
                    resultSet.insert(tmp);
                }
                tracker.insert(nums[j]);
            }            
        }

        return vector(resultSet.begin(), resultSet.end());
    }
};