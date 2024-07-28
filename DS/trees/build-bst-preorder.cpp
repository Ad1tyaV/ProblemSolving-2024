#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode {
    float val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(float val): val(val), left(nullptr), right(nullptr) {}
    TreeNode(float val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};

TreeNode* buildTreeFromPreorder(vector<float> arr, int minValue, int maxValue, int& index) {
    if(index>=arr.size())
        return nullptr;

    float key = arr[index];

    if(key<minValue || key>maxValue)
        return nullptr;

    TreeNode* root = new TreeNode(key);
    index++;

    root->left = buildTreeFromPreorder(arr, minValue, key, index);
    root->right = buildTreeFromPreorder(arr, key, maxValue, index);
    return root;
}

TreeNode* buildFromInorder(vector<float>& arr, int left, int right) {
    if(left>right)
        return nullptr;

    int mid = (left+right)/2;
    TreeNode* root = new TreeNode(arr[mid]);

    root->left = buildFromInorder(arr, left, mid-1);
    root->right = buildFromInorder(arr, mid+1, right);

    return root;
}

TreeNode* buildFromPostOrder(vector<float>& arr, int& index, int minValue, int maxValue) {
    if(index<0)
        return nullptr;

    float key = arr[index];    

    if(key<minValue || key>maxValue)
        return nullptr;

    TreeNode* root = new TreeNode(key);
    index--;

    root->right = buildFromPostOrder(arr, index, key, maxValue);
    root->left = buildFromPostOrder(arr, index, minValue, key);    

    return root;
}

void inorder(TreeNode* root) {
    if(!root)
        return;
    inorder(root->left);
    cout<<root->val<<"\t";
    inorder(root->right);
}

void postOrder(TreeNode* tmp) {
    if(!tmp)
        return;    
    postOrder(tmp->left);
    postOrder(tmp->right);
    cout<<tmp->val<<"\t";
}

int main() {
    vector<float> arr = {10.0, 9.0, 8.0, 9.5, 12.0, 11.0, 13.0};
    int index = 0;
    TreeNode* tmp = buildTreeFromPreorder(arr, INT_MIN, INT_MAX, index);
    inorder(tmp);
    tmp = nullptr;

    cout<<"\n Building Inorder\n";

    vector<float> arr2 = {10.0, 9.0, 8.0, 9.5, 12.0, 11.0, 13.0};
    sort(arr2.begin(), arr2.end());
    tmp = buildFromInorder(arr2, 0, arr2.size()-1);
    inorder(tmp);

    cout<<"\npostOrder Building:\n";
    vector<float> pOrder = {8, 9.5, 9, 11, 13, 12, 10};
    index = pOrder.size()-1;
    tmp = buildFromPostOrder(pOrder, index, INT_MIN, INT_MAX);
    inorder(tmp);

    cout<<endl;
    return 0;
}