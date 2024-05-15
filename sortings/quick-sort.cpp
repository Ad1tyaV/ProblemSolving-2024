#include<iostream>

using namespace std;

vector<int> quickSort(vector<int> arr, int left, int right) {    
    int pivot = arr[right-1];
    int wallIndex = left-1;

}

int main() {
    vector<int> arr = {12, 9, 33, 0, 4, 5 ,11, 123};
    quickSort(arr, 0, arr.size());
    return 0;
}