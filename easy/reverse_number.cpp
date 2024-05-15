#include<iostream>

using namespace std;

int reverseNumber(int number) {  
    int backup = number;  
    int reversedNumber = 0;
    
    while(number>0) {
        reversedNumber *= 10; 
        int remainder = number % 10; 
        reversedNumber += remainder; 
        number /= 10;
    }
    cout<<"Original = "<<backup<<" Reversed="<<reversedNumber<<endl;
    return reversedNumber;
}

int main() {

    reverseNumber(20);
    reverseNumber(-20);
    reverseNumber(900);
    // reverseNumber(083);
    reverseNumber(0);
    reverseNumber(992);

    return 0;
}