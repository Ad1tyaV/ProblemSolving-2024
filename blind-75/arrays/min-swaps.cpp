/*
https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array/
https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array/solutions/5483489/readable-cpp-beats-70/
*/
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return 0;

        pair<int, int> minimum = {0, nums[0]};
        pair<int, int> maximum = {0, nums[0]};        

        for(int index=1; index<n; index++) {
            if(nums[index]<minimum.second) {
                minimum = {index, nums[index]};
            }
            if(nums[index]>=maximum.second) {
                maximum = {index, nums[index]};
            }
        }

        auto [largestIndex, largestElement] = maximum;
        auto& [smallestIndex, smallestElement] = minimum;
        int swaps = 0;

        while(largestIndex+1<n) {           
            swap(nums[largestIndex], nums[largestIndex+1]);
            if(largestIndex+1==smallestIndex) {
                smallestIndex = largestIndex;
            }
            largestIndex++;
            swaps++;
        }
        swaps += (smallestIndex);

        
        return swaps;
    }
};