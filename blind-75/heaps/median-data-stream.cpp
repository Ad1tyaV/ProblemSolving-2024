/*
    https://www.youtube.com/watch?v=EcNbRjEcb14
*/
class MedianFinder {
    priority_queue<int> maxHeap;    
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top()>=num) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if(maxHeap.size()>minHeap.size()+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size()>maxHeap.size()+1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int m = maxHeap.size();
        int n = minHeap.size();

        if(m>n) {
            return maxHeap.top();
        } else if(m<n) {
            return minHeap.top();
        }
        return (maxHeap.top() + minHeap.top())/2.0;
    }
};