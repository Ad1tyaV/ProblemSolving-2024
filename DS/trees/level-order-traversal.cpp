#include<iostream>
#include<vector>
#include<queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

/*
    https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

vector<int> levelOrderTraversal(TreeNode* root) {
    if(!root)
        return {};

    queue<TreeNode*> bfs;
    vector<vector<int>> result;

    bfs.push(root);
    int level = 0;

    while(!bfs.empty()) {
        int queueSize = bfs.size();

        if(result.size()<level+1) {
            result.push_back({});
        }

        for(int count=0; count<queueSize; count++) {
            TreeNode* front = bfs.front();
            bfs.pop();

            TreeNode* left = front->left;
            TreeNode* right = front->right;

            result[level].push_back(front->val);

            if(left) {
                bfs.push(left);
            }
            if(right) {
                bfs.push(right);
            }
        }
        level++;        
    }
    return result;    
}

int main() {


    return 0;
}