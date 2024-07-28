class Solution {
  public:
    // Function to reverse a linked list.
    struct Node* reverseList(struct Node* head) {
        Node* previous = nullptr;
        Node* current = head;
        Node* nextptr;
        
        while(current) {
            nextptr = current->next;
            current->next = previous;
            previous = current;
            current = nextptr;
        }
        return previous;
    }
};