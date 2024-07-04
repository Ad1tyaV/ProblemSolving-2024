#include <iostream>
#include <vector>

using namespace std;

vector<int> leftRotateNewVector(vector<int> list, int lShift) {
    int n = list.size();
    vector<int> result(n, 0);

    for(int index=0; index<n; index++) {
        int newIndex = index-lShift;
        if(newIndex<0)
            newIndex+=n;
        result[newIndex] = list[index];
    }
    return result;
}

int getNextIndex(int currentIndex, int n, int lShift) {
    int nextIndex = currentIndex-lShift;
    if(nextIndex<0)
        nextIndex += n;
    return nextIndex;
}

void leftRotateInPlace(vector<int>& list, int lShift) {
    int n = list.size();
    int currentIndex = n-1;
    int ni = getNextIndex(currentIndex, n, lShift);
    int _swap = list[currentIndex];
    vector<bool> visited(n, false);

    while(!visited[ni]) {
        visited[ni] = true;        
        int tmp = _swap;
        _swap = list[ni];
        list[ni] = tmp;
        ni = getNextIndex(ni, n, lShift);
    }    
}

int main() {

    // vector<int> result = leftRotateNewVector({1, 2, 3, 4, 5}, 2);
    
    vector<int> arr = {1, 2, 3, 4, 5};
    leftRotateInPlace(arr, 6);
    // vector<int> arr = {51, 69, 72, 74, 32, 82, 31, 34, 95, 61, 64, 100, 82, 100, 97, 60, 74, 14, 69, 91, 96, 27, 67, 85, 41, 91, 85, 77, 43, 37, 8, 46, 57, 80, 19, 88, 13, 49, 73, 60, 10, 37, 11, 43, 88, 7, 2, 14, 73, 22, 56, 20, 100, 22, 5, 40, 12, 41, 68, 6, 29, 28, 51, 85, 59, 21, 25, 23, 70, 97, 82, 31, 85, 93, 73, 73, 51, 26, 86, 23, 100, 41, 43, 99, 14, 99, 91, 25, 91, 10, 82, 20, 37, 33, 56, 95, 5, 80, 70, 74};
    // leftRotateInPlace(arr, 80);

    for(int tmp: arr) {
        cout<<tmp<<"\t";
    }
    cout<<endl;

    return 0;
}