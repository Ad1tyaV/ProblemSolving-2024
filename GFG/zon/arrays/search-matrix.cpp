#include<iostream>

using namespace std;

/*
    https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621
*/

class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int>> matrix, int n, int m, int x) {
        
        for(int row=0; row<n; row++) {
            int left = 0;
            int right = m-1;
            
            while(left<=right) {
                int mid = (left+right)/2;
                int element = matrix[row][mid];
                
                if(element==x) {
                    return true;
                }
                
                if(x>element) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        
        return false;
    }
};

int main() {

    return 0;
}