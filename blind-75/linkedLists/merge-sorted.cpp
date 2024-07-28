/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* headFirst = list1;
        ListNode* headSecond = list2;
        ListNode* resultHead = new ListNode(-1);
        ListNode* traverse = resultHead;

        while(headFirst && headSecond) {            
            if(headFirst->val<=headSecond->val) {
                traverse->next = headFirst;              
                headFirst = headFirst->next;
            } else {
                traverse->next = headSecond;
                headSecond = headSecond->next;
            }
            traverse = traverse->next;
        }

        traverse->next = headFirst? headFirst: headSecond;
        
        return resultHead->next;
    }
};