#include<iostream>
#include<deque>

using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(40);

    for(auto it=dq.begin(); it!=dq.end(); it++) {
        cout<<*it<<"\t";
    }
    cout<<endl;

    cout<<dq[1]<<endl;

    return 0;
}