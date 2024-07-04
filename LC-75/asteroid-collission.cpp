/*
https://leetcode.com/problems/asteroid-collision/?envType=study-plan-v2&envId=leetcode-75
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> result;
        int asteroidSize = asteroids.size();
        stack<int> asteroidStack;

        for(int asteroid: asteroids) {
            if(asteroid>0) {
                asteroidStack.push(asteroid);
            } else {
                if(asteroidStack.empty()) {
                    result.push_back(asteroid);
                } else {
                    int _asteroid = abs(asteroid);
                    while(!asteroidStack.empty()) {
                        int top = asteroidStack.top();
                        if(top>_asteroid) {
                            break;
                        }
                        if(top==_asteroid) {
                            _asteroid = -1;
                        }                         
                        asteroidStack.pop();                        
                    }
                    if(asteroidStack.empty() && _asteroid!=-1) {
                        result.push_back(asteroid);
                    }
                }
            }
        }

        vector<int> subresult;
        while(!asteroidStack.empty()) {
            subresult.push_back(asteroidStack.top());
            asteroidStack.pop();
        }

        reverse(subresult.begin(), subresult.end());

        for(int sub: subresult) {
            result.push_back(sub);
        }

        return result;
    }
};