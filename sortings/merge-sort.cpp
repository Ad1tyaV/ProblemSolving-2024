#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums, int left, int mid, int right) {
    int n1 = mid-left+1;
    int n2 = right-mid;

    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    for(int i=0; i<n1; i++) {
        leftArray[i] = nums[left+i];
    }

    for(int i=0; i<n2; i++) {
        rightArray[i] = nums[mid+i+1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2) {
        if(leftArray[i]<=rightArray[j]) {
            nums[k] = leftArray[i];
            i++;                
        } else {
            nums[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i<n1) {
        nums[k] = leftArray[i];
        i++; k++;
    }

    while(j<n2) {
        nums[k] = rightArray[j];
        j++; k++;
    }
}

void mergeSort(vector<int>& nums, int left, int right) {
    if(left < right) {
        int mid = left + (right-left)/2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);

        merge(nums, left, mid, right);
    }
}

int main() {


    return 0;
}