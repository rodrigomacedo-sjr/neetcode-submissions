class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        } else if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if ((right.size() + left.size()) % 2 == 0)
            return ((double) right.top() + left.top()) / 2.0;
        else
            return (double) left.top();
    }
};
