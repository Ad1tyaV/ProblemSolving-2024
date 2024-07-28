#include<iostream>
#include<vector>
#include<map>

using namespace std;


bool recurse(multimap<char, char> tracker, string targetWord, int index) {
    
}

int main() {
    vector<pair<char, char>> blocks = { {'B', 'A'}, {'A', 'B'}, {'X', 'Y'}, {'A', 'B'} };
    string targetWord = "BABY";

    multimap<char, char> container(blocks.begin(), blocks.end());

    if(recurse(container, targetWord, 0))
        cout<<"POssible\n";
    else
        cout<<"Impossible\n";

    return 0;
}