#include<iostream>
#include<vector>
#include<climits>
#include<map>

using namespace std;

map<pair<int, int>, int> dp;

// int solve(vector<int> coins, int index, int result, int coinTrack) {
//     if(result==0) {
//         return coinTrack;
//     }

//     if(result<0)
//         return INT_MAX;

//     if(index==coins.size())
//         return INT_MAX;

//     if(dp.count({index, result}))
//         return dp[{index, result}];

//     int keepPicking = solve(coins, index, result-coins[index], coinTrack+1);
//     int pick = solve(coins, index+1, result-coins[index], coinTrack+1);
//     int skip = solve(coins, index+1, result, coinTrack);    

//     return dp[{index, result}] = min(keepPicking, min(pick, skip));
// }

void print(vector<int> result) {
    for(int coin: result) {
        cout<<coin<<"\t";
    }
    cout<<endl;
}

int solver(vector<int> coins, int index, int result, vector<int> coinsResult) {
    if(result==0) {
        print(coinsResult);
        return 0;
    }

    if(result<0)
        return INT_MAX;

    if(index==coins.size())
        return INT_MAX;

    if(dp.count({index, result}))
        return dp[{index, result}];

    coinsResult.push_back(coins[index]);
    int keepPicking = solver(coins, index, result-coins[index], coinsResult);
    int pick = solver(coins, index+1, result-coins[index], coinsResult);
    coinsResult.pop_back();
    int skip = solver(coins, index+1, result, coinsResult);    

    if(keepPicking!=INT_MAX)
        keepPicking++;
    if(pick!=INT_MAX)
        pick++;
    
    return dp[{index, result}] = min(keepPicking, min(pick, skip));
}

int main() {
    
    vector<int> coins = {1, 2, 5};
    // cout<<"Ans="<<solve(coins, 0, 11, 0)<<"\n";
    dp.clear();
    cout<<"\n";
    cout<<solver(coins, 0, 11, {})<<"\n";
    return 0;
}