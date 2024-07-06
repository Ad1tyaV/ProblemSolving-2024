/*
    https://leetcode.com/problems/design-twitter/submissions/1310884564/
*/
class Twitter {
    int currentTime = 0;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> [ {tweetId, timestamp} ]
    unordered_map<int, unordered_set<int>> followList;

public:
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, currentTime++});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> totalFeed = tweets[userId];        
        for(int following: followList[userId]) {            
            totalFeed.insert(end(totalFeed), begin(tweets[following]), end(tweets[following]));
        }

        sort(totalFeed.begin(), totalFeed.end(), [](pair<int, int> op1, pair<int, int> op2) {
            return op1.second>op2.second;
        });

        vector<int> feed;
        for(int index=0; index<10 && index < totalFeed.size() ; index++) {
            feed.push_back(totalFeed[index].first);
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */