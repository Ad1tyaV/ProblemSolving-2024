#include<iostream>
#include<vector>

using namespace std;

vector<char> compress(vector<char> chars) {
    if(chars.size()==1) {
        return chars;
    }

    vector<char> result;
    char currentCharacter = chars[0];
    int currentCharacterCount = 1;
    result.push_back(currentCharacter);

    for(int index=1; index<chars.size(); index++) {
        while(index<chars.size() && chars[index]==currentCharacter) {
            currentCharacterCount++;
            index++;
        }
        if(currentCharacterCount>1) {      
            for(char digit: to_string(currentCharacterCount)) {
                resut.push_back(digit);
            }
            currentCharacterCount = 1;
        }

        if(index<chars.size()) {
            currentCharacter = chars[index];
            result.push_back(chars[index]);
        }        
    }
    cout<<result.size()<<endl;
    return result;
}

int main() {
    
    vector<char> result = compress({'a','b','b','b','b','b','b','b','b','b','b','b','b'});
    for(char res: result) {
        cout<<res<<"\t";
    }
    cout<<endl;

    return 0;
}