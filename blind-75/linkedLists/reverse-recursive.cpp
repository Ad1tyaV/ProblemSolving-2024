#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int data): data(data), next(nullptr) {}
    ListNode(int data, ListNode* next): data(data), next(next) {}
};

ListNode* buildList() {
    ListNode* head = nullptr;
    ListNode* tail = head;

    for(int i=1; i<8; i++) {
        if(!head) {
            head = tail = new ListNode(i);
        } else {
            tail->next = new ListNode(i);
            tail = tail->next;            
        }
    }
    return head;
}

void printLL(ListNode* head) {
    while(head) {
        cout<<head->data<<"\t";
        head = head->next;
    }
    cout<<endl;
}

ListNode* ans = nullptr;

void reverseLL(ListNode* head, ListNode* previous) {
    if(!head) {
        ans = previous;
        return;
    }   
    reverseLL(head->next, head);
    head-> next = previous;   
}

int main() {

    ListNode* head = buildList();
    printLL(head);
    reverseLL(head, nullptr);
    printLL(ans);

    return 0;
}

/*
bash run-cpp.sh blind-75/linkedLists/reverse-recursive.cpp
1       2       3       4       5       6       7
7       6       5       4       3       2       1
*/