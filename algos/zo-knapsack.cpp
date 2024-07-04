#include<iostream>
#include<vector>
#include<map>
#include<climits>

using namespace std;

map<pair<int, int>, int> cache;
int n;


int knapsacks(vector<int> weights, vector<int> values, int capacity, int index, int value) {    
    if(cache.count({capacity, index}))
        return cache[{capacity, index}];

    if(capacity<0) {
        return INT_MIN;
    }

    if(index==n) {
        return value;
    }    

    int pick = knapsacks(weights, values, capacity-weights[index], index+1, value+values[index]);
    int skip = knapsacks(weights, values, capacity, index+1, value);    
    cache[{capacity, index}] = max(pick, skip);
        
    return cache[{capacity, index}];
}

int knapsack(const vector<int>& weights, const vector<int>& values, int capacity, int index, vector<int> solution) {
    // Check the cache to see if the result is already computed
    if (cache.count({capacity, index})) {
        return cache[{capacity, index}];
    }

    // Base cases
    if (capacity < 0) {
        return INT_MIN; // Return negative infinity if capacity is exceeded
    }
    if (index == n) {
        return 0; // If all items are considered, return value 0
    }

    // Recursively compute the maximum value when including or excluding the current item
    solution.push_back(weight[index]);
    int includeItem = values[index] + knapsack(weights, values, capacity - weights[index], index + 1, solution);
    solution.pop_back();
    int excludeItem = knapsack(weights, values, capacity, index + 1);

    // Store the result in the cache and return the maximum value
    cache[{capacity, index}] = max(includeItem, excludeItem);

    return cache[{capacity, index}];
}


int main() {

    vector<int> weights = {20, 2, 3, 4, 20};
    vector<int> values = {1, 8, 5, 3, 7};
    int maxWeight = 15;
    
    // vector<int> weights = {
    //     85, 99, 80, 58, 62, 98, 76, 55, 47, 75, 
    //     39, 25, 78, 40, 61, 91, 88, 19, 64, 83, 
    //     45, 51, 24, 29, 95, 53, 21, 74, 92, 14, 
    //     33, 43, 12, 87, 79, 60, 56, 26, 72, 93, 
    //     20, 67, 68, 34, 41, 18, 31, 77, 50, 65, 
    //     71, 59, 22, 11, 81, 38, 36, 52, 23, 69, 
    //     13, 54, 48, 15, 37, 66, 73, 46, 32, 44, 
    //     17, 63, 70, 35, 90, 16, 84, 57, 30, 82, 
    //     42, 89, 10, 27, 96, 49, 28, 94, 9, 7, 
    //     8, 6, 5, 4, 3, 2, 1, 100, 86, 97
    // };

    // vector<int> values = {
    //     95, 85, 75, 65, 55, 45, 35, 25, 15, 5, 
    //     90, 80, 70, 60, 50, 40, 30, 20, 10, 100, 
    //     94, 84, 74, 64, 54, 44, 34, 24, 14, 4, 
    //     89, 79, 69, 59, 49, 39, 29, 19, 9, 99, 
    //     93, 83, 73, 63, 53, 43, 33, 23, 13, 3, 
    //     88, 78, 68, 58, 48, 38, 28, 18, 8, 98, 
    //     92, 82, 72, 62, 52, 42, 32, 22, 12, 2, 
    //     87, 77, 67, 57, 47, 37, 27, 17, 7, 97, 
    //     91, 81, 71, 61, 51, 41, 31, 21, 11, 1, 
    //     86, 76, 66, 56, 46, 36, 26, 16, 6, 96
    // };

    

    // int maxWeight = 1000;

    vector<int> solution = {};

    n = weights.size();
    cout<<knapsack(weights, values, maxWeight, 0, solution)<<endl;
    cache.clear();
    // cout<<"S="<<knapsacks(weights, values, maxWeight, 0, 0)<<endl;


    return 0;
}