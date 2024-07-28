#include <iostream>
#include <vector>

using namespace std;

vector<int> countSort(vector<int> arr) {
    vector<int> result;

    int maxElement = arr[0];
    for(int tmp: arr) {
        maxElement = max(maxElement, tmp);
    }

    vector<int> frequency(maxElement+1, 0);

    for(int tmp: arr) {
        frequency[tmp]++;
    }

    for(int index=0; index<frequency.size(); index++) {
        while(frequency[index]--) {
            result.push_back(index);
        }
    }
    return result;
}

int main() {

    for(int tmp: countSort({10, 200, 1, 6, 18, 3, 1})) {
        cout<<tmp<<"\t";
    }
    cout<<endl;

    return 0;
}