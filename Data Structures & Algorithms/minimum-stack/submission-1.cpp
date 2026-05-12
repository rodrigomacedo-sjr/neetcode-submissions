class MinStack {
private:
    stack<int> values;
    stack<int> curr_min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        values.push(val);
        int old_min = curr_min.empty() ? INT_MAX : getMin();
        int new_min = min(old_min, val);
        curr_min.push(new_min);
    }
    
    void pop() {
        values.pop();
        curr_min.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return curr_min.top();
    }
};
