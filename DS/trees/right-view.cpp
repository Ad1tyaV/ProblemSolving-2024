/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};

        vector<int> rightView;

        queue<TreeNode*> bfs;
        bfs.push(root);

        while(!bfs.empty()) {
            int qSize = bfs.size();
            int rightVal;

            for(int index=0; index<qSize; index++) {
                TreeNode* front = bfs.front();
                bfs.pop();

                rightVal = front->val;
                TreeNode* left = front->left;
                TreeNode* right = front->right;

                if(left) {
                    bfs.push(left);
                }

                if(right) {
                    bfs.push(right);
                }
            }
            rightView.push_back(rightVal);
        }

        return rightView;
    }
};