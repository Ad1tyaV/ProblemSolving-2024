// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/?envType=company&envId=expedia&favoriteSlug=expedia-thirty-days

/*

There are n people in a social group labeled from 0 to n - 1. You are given an array logs where logs[i] = [timestampi, xi, yi] indicates that xi and yi will be friends at the time timestampi.

Friendship is symmetric. That means if a is friends with b, then b is friends with a. Also, person a is acquainted with a person b if a is friends with b, or a is a friend of someone acquainted with b.

Return the earliest time for which every person became acquainted with every other person. If there is no such earliest time, return -1.

 

Example 1:

Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
Output: 20190301
Explanation: 
The first event occurs at timestamp = 20190101, and after 0 and 1 become friends, we have the following friendship groups [0,1], [2], [3], [4], [5].
The second event occurs at timestamp = 20190104, and after 3 and 4 become friends, we have the following friendship groups [0,1], [2], [3,4], [5].
The third event occurs at timestamp = 20190107, and after 2 and 3 become friends, we have the following friendship groups [0,1], [2,3,4], [5].
The fourth event occurs at timestamp = 20190211, and after 1 and 5 become friends, we have the following friendship groups [0,1,5], [2,3,4].
The fifth event occurs at timestamp = 20190224, and as 2 and 4 are already friends, nothing happens.
The sixth event occurs at timestamp = 20190301, and after 0 and 3 become friends, we all become friends.
Example 2:

Input: logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4
Output: 3
Explanation: At timestamp = 3, all the persons (i.e., 0, 1, 2, and 3) become friends.
 

Constraints:

2 <= n <= 100
1 <= logs.length <= 104
logs[i].length == 3
0 <= timestampi <= 109
0 <= xi, yi <= n - 1
xi != yi
All the values timestampi are unique.
All the pairs (xi, yi) occur at most one time in the input.

*/

class DSU {
    vector<int> friends;
    vector<int> sizes;
    int n;
    
    public:
    DSU(int n) {
        this->n = n;
        friends = vector<int>(n);
        sizes = vector<int>(n);

        for(int i=0; i<n; i++) {
            friends[i] = i;
            sizes[i] = 1;
        }
    }

    int getParent(int f) {
        if(f==friends[f]) {
            return f;
        }
        return friends[f] = getParent(friends[f]);
    }

    void unionBySize(int friend_1, int friend_2) {
        int parent1 = getParent(friend_1);
        int parent2 = getParent(friend_2);

        if(parent1==parent2)
            return;
        
        if(sizes[parent1]>sizes[parent2]) {
            sizes[parent1] += sizes[parent2];
            friends[parent2] = parent1;
        } else {
            sizes[parent2] += sizes[parent1];
            friends[parent1] = parent2;
        }
    }

    bool allConnected() {
        int components = 0;
        for(int i=0; i<n; i++) {
            if(friends[i]==i) {
                components++;
                if(components>1)
                    return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), [&](vector<int>& log1, vector<int>& log2) {
            return log1[0]<log2[0];
        });

        DSU dsu(n);        

        for(vector<int>& log: logs) {
            dsu.unionBySize(log[1], log[2]);
            if(dsu.allConnected()) {
                return log[0];
            }
        }

        return -1;
    }
};