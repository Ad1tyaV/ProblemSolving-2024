#include<iostream>
#include<vector>

using namespace std;

int largestSum(vector<int> nums) {
    
    int n = nums.size();
        
    int currentSum = nums[0];
    int currentMax = nums[0];

    for(int index=1; index<n; index++) {
        currentSum += nums[index];
        currentSum = max(nums[index], currentSum);
        currentMax = max(currentMax, currentSum);
    }
    return currentMax;
}

int main() {

    cout<<largestSum({-2,-3,4,-1,-2,1,5,-3})<<"\n";
    cout<<largestSum({2})<<"\n";
    cout<<largestSum({-200, -400, 1, 2})<<"\n";
    cout<<largestSum({5,4,1,7,8})<<"\n";

    return 0;
}


/*

Input: arr = {-2,-3,4,-1,-2,1,5,-3}
Output: 7
Explanation: The subarray {4,-1, -2, 1, 5} has the largest sum 7.

Input: arr = {2}
Output: 2
Explanation: The subarray {2} has the largest sum 1.

Input: arr = {5,4,1,7,8}
Output: 25
Explanation: The subarray {5,4,1,7,8} has the largest sum 25.

*/