#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
    ListNode* head = new ListNode();
    ListNode* heady = new ListNode(10);

    cout<<head->val<<endl;
    cout<<heady->val<<endl;
    return 0;
}