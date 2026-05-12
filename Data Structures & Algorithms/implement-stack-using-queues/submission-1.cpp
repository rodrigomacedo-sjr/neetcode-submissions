class MyStack {
private:
    vector<queue<int>> q;

public:
    MyStack() {
        q.assign(2, {});
    }
    
    void push(int x) {
        q[0].push(x);
    }
    
    int pop() {
        int r = this->top();
        int n = q[0].size() - 1;

        for (int i = 0; i < n; ++i) {
            q[1].push(q[0].front());
            q[0].pop();
        }
        q[0].pop();

        for (int i = 0; i < n; ++i) {
            q[0].push(q[1].front());
            q[1].pop();
        }

        return r;
    }
    
    int top() {
        return q[0].back();
    }
    
    bool empty() {
        return q[0].empty() && q[1].empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */