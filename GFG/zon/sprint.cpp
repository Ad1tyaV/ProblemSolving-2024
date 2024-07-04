#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include<map>

using namespace std;



int findPoints(vector<int> d, int k) {
    vector<int> flattenIntervals;
    for(int element: d) {
        int track = 1;
        while(element--) {
            flattenIntervals.push_back(track++);
        }
    }
    
    int points = 0;

    
    for(int start=0; start<k; start++) {
        points += flattenIntervals[start];
    }

    int maxPoints = points;    

    for(int left=0, right=k; right<flattenIntervals.size(); right++, left++) {
        points += (flattenIntervals[right]-flattenIntervals[left]);        
        maxPoints = max(maxPoints, points);
    }
    
    
    return maxPoints;
}

int main() {

    cout<<"Ans="<<findPoints({7, 4, 3, 7, 2}, 8)<<endl;

    return 0;
}