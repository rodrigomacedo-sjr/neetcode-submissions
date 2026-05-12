struct Node {
    Node* next = nullptr;
    int val;
    int curr_min;
};

class MinStack {
private:
    Node* start = nullptr;

public:
    MinStack() {

    }
    
    void push(int val) {
        Node* newNode = new Node;

        newNode->val = val;
        newNode->curr_min = val < getMin() ? val : getMin();

        newNode->next = start;
        start = newNode;
    }
    
    void pop() {
        Node* gone = start;

        start = start->next;

        delete gone;
    }
    
    int top() {
        return start ? start->val : -1;
    }
    
    int getMin() {
        return start ? start->curr_min : INT_MAX;
    }
};
