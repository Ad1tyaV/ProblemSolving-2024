#include<iostream>
#include<vector>

using namespace std;

vector<string> result;

void permute(string q, int index) {
    
    if(index==q.size()) {        
        result.push_back(q);
        return;
    }

    for(int i=index; i<q.size(); i++) {        
        swap(q[i], q[index]);
        permute(q, index+1);        
        swap(q[i], q[index]);
    }

}

int main() {

    string q = "123";

    permute(q, 0);

    cout<<"Result size="<<result.size()<<endl;
    for(string tmp: result) {
        cout<<tmp<<"\t";
    }
    cout<<endl;

    return 0;
}