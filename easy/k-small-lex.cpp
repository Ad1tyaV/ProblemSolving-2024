#include<iostream>
#include<queue>

using namespace std;

char smallestCharacter(string word) {
    char smallest = word[0];
    for(int index=1; index<word.size(); index++) {
        if(smallest > word[index]) {
            smallest = word[index];
        }
    }
    return smallest;
}

char kthSmallestCharacter(string word, int k) {
    priority_queue<char, vector<char>, greater<char>> p_queue;
    for(int index=0; index<word.size(); index++) {
        p_queue.push(word[index]);
    }
    while(k-1) {
        p_queue.pop();
        k--;
    }
    return p_queue.top();
}

int main() {
    cout<<smallestCharacter("leetcode")<<endl;
    cout<<kthSmallestCharacter("leetcode", 2)<<endl;
    return 0;
}