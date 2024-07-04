#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include<unordered_set>

using namespace std;


int findComplexity(string password) {
    int length = password.size();
    unordered_set<string> store;
    store.insert(password);

    for(int subLength = 2; subLength<=length; subLength++) {
        for(int startIndex=0; startIndex+subLength<=length; startIndex++) {
            reverse(password.begin()+startIndex, password.begin()+startIndex+subLength);
            store.insert(password);
            reverse(password.begin()+startIndex, password.begin()+startIndex+subLength);
        }
    }

    return store.size();
}

int main() {

    cout<<findComplexity("abc")<<endl;
    cout<<findComplexity("abaa")<<endl;
    return 0;
}