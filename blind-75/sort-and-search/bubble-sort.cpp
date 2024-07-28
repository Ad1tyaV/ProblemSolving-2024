#include<iostream>
#include<vector>

using namespace std;

void printArr(vector<int>& arr) {
    for(int tmp: arr) {
        cout<<tmp<<"\t";
    }
    cout<<"\n";
}

void bubbleSort(vector<int>& arr) {
    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[i]>arr[j]) {                
                swap(arr[j], arr[i]);
            }
        }
    }
}

int main() {
    vector<int> arr = {90, 22, 4, 222, 1, 5, 7};
    printArr(arr);
    bubbleSort(arr);
    printArr(arr);
}