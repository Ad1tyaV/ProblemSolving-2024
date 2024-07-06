#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm> 

using namespace std;

vector<int> getRandomVector(int n, int maxElement) {
    vector<int> tmp;

    for(int index=0; index<n; index++) {
        tmp.push_back(rand()%maxElement);
    }

    return tmp;
}

void print(vector<int> tmp) {
    for(int x: tmp) {
        cout<<x<<"\t";
    }
    cout<<endl;
}

int findElement(vector<int>& arr, int num) {
    int left = 0;
    int right = arr.size()-1;

    while(left<=right) {
        int mid = (right-left)/2 + (left);        
        if(arr[mid]==num) {
            return mid;
        }
        if(num>arr[mid]) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return left;
}

void addElement(vector<int>& arr, int number) {
    print(arr);
    int index = findElement(arr, number);
    arr.insert(arr.begin()+index, number);
    print(arr);
}

int main() {

    vector<int> randomVector = getRandomVector(10, 45);
    sort(randomVector.begin(), randomVector.end());
    addElement(randomVector, 10);
    
    return 0;
}

/*
Output
bash run-cpp.sh blind-75/sort-and-search/next-greatest-element.cpp
1       1       12      16      23      24      25      25      27      28
1       1       10      12      16      23      24      25      25      27      28
*/