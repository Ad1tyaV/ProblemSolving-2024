#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    public:
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

class BST {
    TreeNode* root;
    TreeNode* successor;

    TreeNode* deleteNode(TreeNode* root, int key) {        
        if(!root)
            return nullptr;

        if(key>root->val) {
            root->right = deleteNode(root->right, key);
        }
        else if(key<root->val) {
            root->left = deleteNode(root->left, key);
        }
        else {            
            if(root->left && root->right) {
                // has two children
                TreeNode* tmp = root->right;
                while(tmp->left) {
                    tmp = tmp->left;
                }
                root->val = tmp->val;
                root->right = deleteNode(root->right, tmp->val);
            } else if(!root->left && !root->right) {
                // Leaf node
                delete root;
                return nullptr;                
            } else {
                // has one child                
                return root->left? root->left: root->right;
            }
        }
        return root;
    }

    void inorderSuccessor(TreeNode* root, int key) {
        if(!root)
            return;
        if(key<root->val) {
            successor = root->val;
            inorderSuccessor(root->left, key);
        } else {
            inorderSuccessor(root->right, key);
        }
    }

    public:
    BST() {
        root=nullptr;
    }

    BST(int data) {
        root = new TreeNode(data);
    }

    TreeNode* findParent(TreeNode* node, int data) {
        if(!node) {
            return nullptr;
        }
        
        if(data>node->val) {
            if(!node->right) return node;
            return findParent(node->right, data);
        } else {
            if(!node->left) return node;
            return findParent(node->left, data);                
        }
        return nullptr;        
    }

    TreeNode* findNode(int data) {
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while(!nodeStack.empty()) {
            TreeNode* current = nodeStack.top();
            nodeStack.pop();

            if(current->val==data)
                return current;

            if(current->right) nodeStack.push(current->right);            
            if(current->left) nodeStack.push(current->left);            
        }
        return nullptr;
    }

    void addNode(int value) {
        if(!root) {
            root = new TreeNode(value);
            return;
        }

        TreeNode* parent = findParent(root, value);
        if(value>parent->val)
            parent->right = new TreeNode(value);
        else
            parent->left = new TreeNode(value);
    }

    void deleteNode(int key) {
        deleteNode(root, key);
    }

    vector<int> inorder() {
        stack<TreeNode*> nodeStack;
        TreeNode* current = root;        
        vector<int> order;

        while(current || !nodeStack.empty()) {
            while(current) {
                nodeStack.push(current);
                current = current->left;
            }

            TreeNode* top = nodeStack.top();
            nodeStack.pop();

            order.push_back(top->val);
            if(top->right)
                current = top->right;
        }
        return order;
    }

    void inorderSuccessor(int key){
        inorderSuccessor(root, key);
    }
};

int main() {
    BST bst = BST(10);
    
    for(int i=0; i<10; i++) {
        bst.addNode(rand()%80);
    }

    vector<int> order = bst.inorder();
    for(int tmp: order)
        cout<<tmp<<"\t";
    cout<<endl;

    int deleteIndex = rand()%order.size();
    cout<<"Deleting - "<<order[deleteIndex]<<endl;
    bst.deleteNode(order[deleteIndex]);
    cout<<"After deletion\n";
    for(int tmp: bst.inorder())
        cout<<tmp<<"\t";
    
    cout<<"\n";

    return 0;
}