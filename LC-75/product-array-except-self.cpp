#include<iostream>

using namespace std;

vector<int> productExceptSelf(vector<int> arr) {
    int numberOfElements = arr.size();
    vector<int> result = vector<int>(numberOfElements, 1);
    int leftProduct = 1;    

    for(int index=0; index<numberOfElements; index++) {
        result[index] = leftProduct;
        leftProduct *= arr[index];
    }

    int rightProduct = 1;

    for(int index=numberOfElements-1; i>-1; i--) {
                        
    }

}

int main() {

    vector<vector<int>> arr = { {12, 3, 55, 9, 20}, {-1, -1, 0, 0, 2, 3}, {3, 2, 0, 6, 7} };    

    return 0;
}