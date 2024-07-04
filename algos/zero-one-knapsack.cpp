//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int solve(int W, int wt[], int val[], int n, int index) {        
        if(W<0)
            return INT_MIN;
        if(index==n) {            
            return 0;
        }
        int picked = val[index] + solve(W-wt[index], wt, val, n, index+1);
        int notPicked = solve(W, wt, val, n, index+1);
        return max(picked, notPicked);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) { 
        int index = 0;
        return solve(W, wt, val, n, index);
    }
};

//{ Driver Code Starts.

int main() {
    
    Solution ob;
    // int wt[] = {1, 2, 3};
    // int values[] = {4, 5, 1};
    int wt[] = {
        85, 99, 80, 58, 62, 98, 76, 55, 47, 75, 
        39, 25, 78, 40, 61, 91, 88, 19, 64, 83, 
        45, 51, 24, 29, 95, 53, 21, 74, 92, 14, 
        33, 43, 12, 87, 79, 60, 56, 26, 72, 93, 
        20, 67, 68, 34, 41, 18, 31, 77, 50, 65, 
        71, 59, 22, 11, 81, 38, 36, 52, 23, 69, 
        13, 54, 48, 15, 37, 66, 73, 46, 32, 44, 
        17, 63, 70, 35, 90, 16, 84, 57, 30, 82, 
        42, 89, 10, 27, 96, 49, 28, 94, 9, 7, 
        8, 6, 5, 4, 3, 2, 1, 100, 86, 97
    };

    int values[] = {
        95, 85, 75, 65, 55, 45, 35, 25, 15, 5, 
        90, 80, 70, 60, 50, 40, 30, 20, 10, 100, 
        94, 84, 74, 64, 54, 44, 34, 24, 14, 4, 
        89, 79, 69, 59, 49, 39, 29, 19, 9, 99, 
        93, 83, 73, 63, 53, 43, 33, 23, 13, 3, 
        88, 78, 68, 58, 48, 38, 28, 18, 8, 98, 
        92, 82, 72, 62, 52, 42, 32, 22, 12, 2, 
        87, 77, 67, 57, 47, 37, 27, 17, 7, 97, 
        91, 81, 71, 61, 51, 41, 31, 21, 11, 1, 
        86, 76, 66, 56, 46, 36, 26, 16, 6, 96
    };
            
    cout<<ob.knapSack(1000, wt, values, 100)<<endl;

	return 0;
}