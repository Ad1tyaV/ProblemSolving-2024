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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode* head = l3;
        int carry = 0;
        while(l1 && l2) {
            int sum = l1->val + l2->val + carry;
            l3->val = sum%10;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            if(l1 || l2) {
                l3->next = new ListNode();
                l3 = l3->next;
            }
        }
        while(l1) {
            int sum = l1->val + carry;
            carry = sum/10;
            l3 -> val = sum%10;
            l1 = l1->next;
            if(l1) {
                l3->next = new ListNode();
                l3 = l3->next;
            }
        }
        while(l2) {
            int sum = l2->val + carry;            
            carry = sum/10;
            l3->val = sum%10;
            l2 = l2->next;
            if(l2) {
                l3->next = new ListNode();      
                l3=l3->next;          
            }
        }
        if(carry) {
            l3->next = new ListNode();
            l3 = l3->next;
            l3->val = carry;
        }
        return head;
    }
};