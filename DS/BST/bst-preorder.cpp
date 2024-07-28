#include<iostream>
#include<vector>
#include<climits>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value): value(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* left, TreeNode* right): value(value), left(left), right(right) {}
};

TreeNode* constructBST(vector<int>& arr, int index, int minValue, int maxValue) {
    if(index>=arr.size())
        return nullptr;

    int rootVal = arr[index];

    if(rootVal<minValue || rootVal>maxValue) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(rootVal);
    index++;

    root->left = constructBST(arr, index, minValue, value);
    root->right = constructBST(arr, index, value, maxValue);

    return root;
}

int main() {
    vector<int> arr = {8,5,1,7,10,12};
    TreeNode* root = constructBST(arr, 0, INT_MIN, INT_MAX);
    return 0;
}