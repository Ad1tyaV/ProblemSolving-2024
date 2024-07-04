class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left<=right) {
            int mid = (left+right)/2;
            if(nums[mid]==target) {
                return true;
            } else if(target > nums[mid]) {
                left = mid+1;
            } else {
                right = mid-1;
            }            
        }
        return false;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3)
            return {};
        vector<vector<int>> result;        
        unordered_map<int, vector<int>> tracker;

        for(int index=0; index<n; index++) {            
            tracker[nums[index]].push_back(index);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==j)
                    continue;
                int sum = nums[i] + nums[j];                
                int target = -sum;
                if(!tracker.count(target))
                    continue;                
                vector<int> tmp = tracker[target];                

                if(binarySearch(tmp, i) && binarySearch(tmp, j)) {
                    if(tmp.size()>=3)
                        result.push_back({nums[i], nums[j], target});
                } else if(binarySearch(tmp, i) || binarySearch(tmp, j)) {
                    if(tmp.size()>=2)
                        result.push_back({nums[i], nums[j], target});
                }
                if(!binarySearch(tmp, i) && !binarySearch(tmp, j) && tmp.size()>=1) {
                    result.push_back({nums[i], nums[j], target});
                }
            }
        }
        
        set<vector<int>> resultSet;

        for(vector<int> res: result) {
            sort(res.begin(), res.end());
            resultSet.insert(res);
        }

        return vector(resultSet.begin(), resultSet.end());
    }
};