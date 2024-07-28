#include <iostream>
#include <queue>
#include <climits>

using namespace std;

class MyStack {
    queue<int> q1, q2;
    
    public:
    MyStack() {}
    void push(int element) {
        q2.push(element);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int top() {
        return q1.front();
    }

    int pop() {
        if(q1.empty())
            return INT_MIN;
        int top = q1.front();
        q1.pop();
        return top;
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {

    MyStack st;

    for(int index=0; index<10; index++) {
        st.push(index);
    }

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    cout<<st.top()<<endl;

    cout<<st.isEmpty()<<endl;

    return 0;
}