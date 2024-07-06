#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value): value(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* left, TreeNode* right): value(value), left(left), right(right) {}
};

class BinarySearchTree {
    private:
    TreeNode* root;

    void inorderTraversal(TreeNode* root) {
        if(!root)
            return;
        inorderTraversal(root->left);
        cout<<root->value<<"\t";
        inorderTraversal(root->right);
    }  

    TreeNode* insertNode(TreeNode* root, int value) {
        if(!root)
            return root = new TreeNode(value);
        if(value > root->value) {
            root->right = insertNode(root->right, value);
        } else {
            root->left = insertNode(root->left, value);
        }
        return root;
    }
    
    public:
    BinarySearchTree() {
        root = nullptr;
    }

    BinarySearchTree(int value) {
        root = new TreeNode(value);
    }    

    TreeNode* insert(int value) {
        return insertNode(root, value);
    }

    void inorder() {
        inorderTraversal(root);
        cout<<"\n";
    }

};

int main() {

    BinarySearchTree* binarySearchTree = new BinarySearchTree(10);
    binarySearchTree->insert(20);
    binarySearchTree->insert(1);
    binarySearchTree->insert(2);
    binarySearchTree->insert(3);
    binarySearchTree->insert(4);
    binarySearchTree->insert(5);

    binarySearchTree->inorder();

    return 0;
}