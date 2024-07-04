#include<iostream>
#include<cmath>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data): data(data), left(nullptr), right(nullptr) {}
    TreeNode(int data, TreeNode* left, TreeNode* right): data(data), left(left), right(right) {}
};

void inorderTraversal(TreeNode* node) {
    if(node) {
        inorderTraversal(node->left);
        cout<<node->data<<"\t";
        inorderTraversal(node->right);
    }
}

int findLeftHeight(TreeNode* node) {
    if(!node)
        return 0;
    return 1 + findLeftHeight(node->left);
}

int findRightHeight(TreeNode* node) {
    if(!node)
        return 0;
    return 1 + findRightHeight(node->right);
}

int countNodes(TreeNode* node) {
    if(!node)
        return 0;
    int leftHeight = findLeftHeight(node->left) + 1;
    int rightHeight = findRightHeight(node->right) + 1;    

    if(leftHeight==rightHeight) {
        return pow(2, leftHeight)-1;
    }

    return 1 + countNodes(node->left)+countNodes(node->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // inorderTraversal(root);
    // cout<<endl;

    cout<<"Count Nodes="<<countNodes(root)<<endl;

    return 0;
}