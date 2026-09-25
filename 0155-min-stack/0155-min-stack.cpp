class MinStack {
public:

    std::vector<int> data;
    std::vector<int> min;

    MinStack() {
        
    }
    
    void push(int value) {
        data.push_back(value);

        if (min.empty() || value <= min.back()) {
            min.push_back(value);
        } else {
            min.push_back(min.back());
        }
    }
    
    void pop() {
        if (!data.empty()) {
            data.pop_back(); min.pop_back();
        }
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */