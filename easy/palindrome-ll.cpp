// [8,0,7,1,7,7,9,7,5,2,9,1,7,3,7,0,6,5,1,7,7,9,3,8,1,5,7,7,8,4,0,9,3,7,3,4,5,7,4,8,8,5,8,9,8,5,8,8,4,7,5,4,3,7,3,9,0,4,8,7,7,5,1,8,3,9,7,7,1,5,6,0,7,3,7,1,9,2,5,7,9,7,7,1,7,0,8]

#include<iostream>

using namespace std;

bool isDigitPalindrome(unsigned int number) {        
    unsigned int backup = number;
    unsigned int reversedNumber = 0;
    while(number) {
        reversedNumber *= 10;
        int remainder = number % 10;            
        reversedNumber += remainder;
        number /= 10;
    }        
    return reversedNumber == backup;
}

bool isPalindrome(ListNode* head) {
    if(!head || head->next==NULL)
        return true;
    
    unsigned int number = 0;
    while(head) {
        number *= 10;
        int digit = head->val;
        number += digit;
        head = head->next;
    }        
    return isDigitPalindrome(number);
}

int main() {


    return 0;
}