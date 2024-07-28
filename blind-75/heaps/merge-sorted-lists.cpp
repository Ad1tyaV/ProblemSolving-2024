/*
    https://leetcode.com/problems/merge-k-sorted-lists/description/
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return nullptr;
        if(lists.size()==1)
            return lists[0];
        priority_queue<int, vector<int>, greater<int>> minHeap;
        ListNode* head = nullptr;
        ListNode* traverse = head;

        for(ListNode* list: lists) {
            ListNode* head = list;
            while(head) {
                minHeap.push(head->val);
                head = head->next;
            }            
        }

        while(!minHeap.empty()) {
            if(!traverse) {
                head = traverse = new ListNode(minHeap.top());
                minHeap.pop();
                continue;
            }
            
            traverse->next = new ListNode(minHeap.top());
            traverse = traverse->next;
            minHeap.pop();
        }

        return head;
    }
};