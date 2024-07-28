#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> arr) {
    for(int tmp: arr) {
        cout<<tmp<<"\t";
    }
    cout<<endl;
}

void insertionSort(vector<int>& arr) {
    for(int index=1; index<arr.size(); index++) {
        int current = arr[index];
        int left=index-1;

        while(left>=0 && arr[left]>current) {            
            arr[left+1] = arr[left];
            left--;
        }
        arr[left+1] = current;
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    printVector(arr);

    cout<<"After sorting\n";

    insertionSort(arr);
    printVector(arr);
    return 0;
}